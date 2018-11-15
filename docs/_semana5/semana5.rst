Semana 5
===========
Esta semanas continuaremos explorando el API de FreeRTOS. Ya casi tenemos todos los elementos básicos para comenzar a realizar 
aplicaciones. Es bueno aclarar en este punto que hay muchos más detalles del API que hemos dejado de lado, por tanto, 
aún más camino por recorrer en el futuro.

Objetivos
----------

1. Conocer el funcionamiento del sistea al iniciar y su arquitectura de memoria.
2. Aprender algunos mecanismos de sincronización del sistema.


Consideraciones de las semanas anteriores
------------------------------------------

Reto de la semana pasada
^^^^^^^^^^^^^^^^^^^^^^^^^
Una posible solución al reto de la semana pasa:

.. code-block:: c
   :lineno-start: 1

    #include <stdio.h>
    #include <string.h>
    #include "freertos/FreeRTOS.h"
    #include "freertos/task.h"
    #include "freertos/queue.h"
    #include "freertos/portmacro.h"


    static void vSenderTask( void *pvParameters );
    static void vReceiverTask( void *pvParameters );

    QueueHandle_t xQueueMessage;
    QueueHandle_t xQueueACK;

    char * messages[] = {"Hola mundo" ,
                        "Cruel y despiadado", 
                        "La vida es bella, el feo es uno",
                        "Hay 10 tipos de personas en el mundo: los que entienden el binario, y los que no",
                        "Por favor envie todo el spam a mi direccion principal, root@localhost"};

    void app_main(void)
    {
        xQueueMessage = xQueueCreate( 1, sizeof( char * ) );
        xQueueACK = xQueueCreate( 1, sizeof( uint8_t ) );

        if( (xQueueMessage != NULL) &&(xQueueACK != NULL) )
        {
            xTaskCreate( vSenderTask, "Sender", 2048, NULL, 2, NULL );
            xTaskCreate( vReceiverTask, "Receiver", 2048, NULL, 2, NULL );
        }
        else
        {
            printf("The queues could not be created.\r\n");
        }
    }
    /*-----------------------------------------------------------*/

    static void vSenderTask( void *pvParameters )
    {
        UBaseType_t msgIndex = 0;
        char buffer[100];
        char *pbuffer = buffer;
        uint8_t ack = 0;

        for( ;; )
        {
            //printf("Sending message... %d\r\n",msgIndex);
            strcpy (buffer,messages[msgIndex]);
            msgIndex = (msgIndex + 1) % (sizeof(messages)/sizeof(messages[0]));
            xQueueSendToBack( xQueueMessage, &pbuffer, portMAX_DELAY );
            xQueueReceive( xQueueACK, &ack, portMAX_DELAY);
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    }

    /*-----------------------------------------------------------*/

    static void vReceiverTask( void *pvParameters )
    {
        char * pbuffer;
        portCHAR ack = 1;

        for( ;; )
        {
            //printf( "Waiting message...\r\n");
            xQueueReceive( xQueueMessage, &pbuffer, portMAX_DELAY);
            printf("Message: %s\r\n",pbuffer);
            xQueueSendToBack( xQueueACK, &ack, portMAX_DELAY );
        }
    }


El resultados sera::

    Message: Hola mundo
    Message: Cruel y despiadado
    Message: La vida es bella, el feo es uno
    Message: Hay 10 tipos de personas en el mundo: los que entienden el binario, y los que no
    Message: Por favor envie todo el spam a mi direccion principal, root@localhost

El código anterior tiene varias cosas interesante:

* La línea ``xQueueMessage = xQueueCreate( 1, sizeof( char * ) );`` crea una cola de tamaño 1. El item es de 4 bytes,
  correspondientes al tamaño de las direcciones en el ESP-32 (``sizeof(char *)``). En este caso la idea es que el item de la
  cola almacenará la dirección del buffer con los caráctares del mensaje.
* ``msgIndex = (msgIndex + 1) % (sizeof(messages)/sizeof(messages[0]));`` Incrementa el índice de mensajes haciendo que al 
  llegar a la cantidad de items contenidos en el arreglo de mensajes, se reinicie el conteo a 0 gracias a la función módulo 
  (``%``).
*  ``char *pbuffer = buffer;`` almacena la dirección del buffer con los caracteres.
* En ``xQueueSendToBack( xQueueMessage, &pbuffer, portMAX_DELAY );`` ``&pbuffer`` pasa la dirección de una variable que 
  contendrá el valor del item a enviar. En este caso, el valor es una dirección, es decir, la dirección en memoria donde 
  están los caracteres con el mensaje.
* Al ``xQueueReceive( xQueueMessage, &pbuffer, portMAX_DELAY);`` se pasa la dirección de una variable donde se almecenará 
  la dirección en memoria del buffer de caracteres.


Sobre la función app_main
^^^^^^^^^^^^^^^^^^^^^^^^^
Pregunta Juanito: ¿Qué es app_main? app_main es una función llamada por el framework ``ESP-IDF``. Esta función es llamada 
por la tarea principal:

.. code-block:: c 
   :lineno-start: 1

    static void main_task(void* args)
    {
        // Now that the application is about to start, disable boot watchdogs
        REG_CLR_BIT(TIMG_WDTCONFIG0_REG(0), TIMG_WDT_FLASHBOOT_MOD_EN_S);
        REG_CLR_BIT(RTC_CNTL_WDTCONFIG0_REG, RTC_CNTL_WDT_FLASHBOOT_MOD_EN);
    #if !CONFIG_FREERTOS_UNICORE
        // Wait for FreeRTOS initialization to finish on APP CPU, before replacing its startup stack
        while (port_xSchedulerRunning[1] == 0) {
            ;
        }
    #endif
        //Enable allocation in region where the startup stacks were located.
        heap_caps_enable_nonos_stack_heaps();

        //Initialize task wdt if configured to do so
    #ifdef CONFIG_TASK_WDT_PANIC
        ESP_ERROR_CHECK(esp_task_wdt_init(CONFIG_TASK_WDT_TIMEOUT_S, true))
    #elif CONFIG_TASK_WDT
        ESP_ERROR_CHECK(esp_task_wdt_init(CONFIG_TASK_WDT_TIMEOUT_S, false))
    #endif

        //Add IDLE 0 to task wdt
    #ifdef CONFIG_TASK_WDT_CHECK_IDLE_TASK_CPU0
        TaskHandle_t idle_0 = xTaskGetIdleTaskHandleForCPU(0);
        if(idle_0 != NULL){
            ESP_ERROR_CHECK(esp_task_wdt_add(idle_0))
        }
    #endif
        //Add IDLE 1 to task wdt
    #ifdef CONFIG_TASK_WDT_CHECK_IDLE_TASK_CPU1
        TaskHandle_t idle_1 = xTaskGetIdleTaskHandleForCPU(1);
        if(idle_1 != NULL){
            ESP_ERROR_CHECK(esp_task_wdt_add(idle_1))
        }
    #endif

        app_main();
        vTaskDelete(NULL);
    }


Antes de llegar aquí han ocurrido los siguientes pasos:

* La CPU 0 o PRO_CPU inicia en la posición de memoria ``0x40000400`` correspondiente al vector de reset del chip.
* En este punto la CPU 1 o APP_CPU está en estado de reset.
* Una vez inicia la PRO_CPU se ejecuta el primer bootloader, cargado por el fabricante del chip. La función de ese bootloader 
  es cargar un segundo bootloader, residente en la posición ``0x1000``, con más funciones que el primero y cuyo código
  fuente se puede consultar el directorio ``components/bootloader``. El concepto de segundo bootloader permite hacer cosas como 
  leer la tabla de particiones de la flash, implementar estrategias de encriptado de la memoria, ejecutar un proceso 
  de carga segura de la aplicación, secure boot, y hacer actualizaciones del programa tipo ``over-the-air`` u ``OTA``.
* Espressif entrega como parte del ESP-IDF el bootloader anterior. Por tanto, es posible modificarlo completamente 
  o cambiar su funcionamiento.
* El segundo ``bootloader`` lee la tabla de particiones y decide cuál aplicación cargar. Aquí es donde ocurre la majia de 
  seleccionar entre una aplicación nueva (actualización mediante OTA) o seguir con la aplicación anterior.
* El segundo bootloader también se encarga de cargar partes de la aplicación en la ``IRAM`` (*instruction RAM*) 
  o ``DRAM`` (*data RAM*) así como configurar las zonas de la FLASH utilizadas como IROM (*instruction ROM*) o 
  DROM (*data ROM*).
* Finalmente el segundo bootloader le entrega el control a la aplicación.
* El punto de entrada de la aplicación es ``call_start_cpu0`` ubicado en ``components/esp32/cpu_start.c``.
* En ``call_start_cpu0`` se inicia la APP_CPU que ejecutará la función ``call_start_cpu1``. Finalmente PRO_CPU saltará ``start_cpu0`` 
  y APP_CPU a ``start_cpu1``. Estas de últimas funciones iniciarán el planificador en cada CPU y se creará 
  la tarea ``main_task`` quien finalmente llamará el punto de entrada del código de usuario que será la función ``app_main``.
* Una vez se retorne de ``app_main`` la tarea ``main_task`` terminará y será borrada.
* Se pueden leer más detalles de este proceso `aquí <http://esp-idf.readthedocs.io/en/latest/api-guides/general-notes.html>`__.

Ejercicios con el API de FreeRTOS
---------------------------------
Para realizar los siguientes ejercicio es necesario tener a la mano dos documentos:

1. `Tutorial oficial <https://www.freertos.org/Documentation/161204_Mastering_the_FreeRTOS_Real_Time_Kernel-A_Hands-On_Tutorial_Guide.pdf>`__.
2. La implementación de Espressif. `ESP-FREERTOS <https://esp-idf.readthedocs.io/en/latest/api-reference/system/freertos.html>`__.

Ejercicio 1: memoria de aplicación 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
El código y datos de la aplicación pueden ubicarse en varias regiones de memoria: ``IRAM``, ``IROM``, ``RTC fast memory``, 
``DRAM``, ``DROM``, ``RTC slow memory``. 

Para indicarle al enlazador (``linker``) que ubique códígo en la IRAM se utiliza el atributo ``IRAM_ATTR``::

    #include "esp_attr.h"

    void IRAM_ATTR gpio_isr_handler(void* arg)
    {
            // ...
    }

La definición de un servicios de atención a interrupción es un uso típico de lo anterior. Otro caso, son las funciones 
del API de FreeRTOS.

Por otra parte, Si una función, explícitamente, no se ubica en IRAM o en RTC, se colocará en *flash*, es decir, ``IROM``.

En la región ``RTC fast memory``, debe ubicarse el código que se ejecutará luego de despartar de una condición de 
``Deep sleep``.

La datos constantes de la aplicación se pueden colocan en la DRAM utilizando el atributo DRAM_ATTR::

    DRAM_ATTR const char[] format_string = "%p %x";
    char buffer[64];
    sprintf(buffer, format_string, ptr, val);

Por defecto las constantes se ubican en la ``DROM``. Las constantes literales se embeben en el propio código de la aplicación.

Finalmente, en ``RTC slow memory`` se ubican las variables estáticas globales y globales que serán usadas desde la 
memoria RTC, así::
    
    RTC_NOINIT_ATTR uint32_t rtc_noinit_data;

Ejericio 2: comunicación entre interrupciones y tareas
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Para este ejercicio vamos a conectar dos puertos de entrada con dos puertos de salida del microcontrolador. 
Los puertos de entrada capturarán el cambio de nivel de voltaje en las salidas así: GPIO5 flancos de subida, GPIO4 
flancos de subida y bajada. Los eventos anteriores serán enviados, desde un servicio de atención a interrupción, 
a una tarea utilizando una cola. A esta técnica de tratamiento de las interrupciones se le conoce como ``PROCESAMIENTO 
DIFERIDO DE INTERRUPCIONES``. El código del ejemplo es el siguiente:

.. code-block:: c
   :lineno-start: 1

    /* GPIO Example

    This example code is in the Public Domain (or CC0 licensed, at your option.)

    Unless required by applicable law or agreed to in writing, this
    software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
    CONDITIONS OF ANY KIND, either express or implied.
    */
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include "freertos/FreeRTOS.h"
    #include "freertos/task.h"
    #include "freertos/queue.h"
    #include "driver/gpio.h"

    /**
    * Brief:
    * This test code shows how to configure gpio and how to use gpio interrupt.
    *
    * GPIO status:
    * GPIO18: output
    * GPIO19: output
    * GPIO4:  input, pulled up, interrupt from rising edge and falling edge
    * GPIO5:  input, pulled up, interrupt from rising edge.
    *
    * Test:
    * Connect GPIO18 with GPIO4
    * Connect GPIO19 with GPIO5
    * Generate pulses on GPIO18/19, that triggers interrupt on GPIO4/5
    *
    */

    #define GPIO_OUTPUT_IO_0    18
    #define GPIO_OUTPUT_IO_1    19
    #define GPIO_OUTPUT_PIN_SEL  ((1ULL<<GPIO_OUTPUT_IO_0) | (1ULL<<GPIO_OUTPUT_IO_1))
    #define GPIO_INPUT_IO_0     4
    #define GPIO_INPUT_IO_1     5
    #define GPIO_INPUT_PIN_SEL  ((1ULL<<GPIO_INPUT_IO_0) | (1ULL<<GPIO_INPUT_IO_1))
    #define ESP_INTR_FLAG_DEFAULT 0

    static xQueueHandle gpio_evt_queue = NULL;

    static void IRAM_ATTR gpio_isr_handler(void* arg)
    {
        uint32_t gpio_num = (uint32_t) arg;
        xQueueSendFromISR(gpio_evt_queue, &gpio_num, NULL);
    }

    static void gpio_task_example(void* arg)
    {
        uint32_t io_num;
        for(;;) {
            if(xQueueReceive(gpio_evt_queue, &io_num, portMAX_DELAY)) {
                printf("GPIO[%d] intr, val: %d\n", io_num, gpio_get_level(io_num));
            }
        }
    }

    void app_main()
    {
        gpio_config_t io_conf;
        //disable interrupt
        io_conf.intr_type = GPIO_PIN_INTR_DISABLE;
        //set as output mode
        io_conf.mode = GPIO_MODE_OUTPUT;
        //bit mask of the pins that you want to set,e.g.GPIO18/19
        io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
        //disable pull-down mode
        io_conf.pull_down_en = 0;
        //disable pull-up mode
        io_conf.pull_up_en = 0;
        //configure GPIO with the given settings
        gpio_config(&io_conf);

        //interrupt of rising edge
        io_conf.intr_type = GPIO_PIN_INTR_POSEDGE;
        //bit mask of the pins, use GPIO4/5 here
        io_conf.pin_bit_mask = GPIO_INPUT_PIN_SEL;
        //set as input mode    
        io_conf.mode = GPIO_MODE_INPUT;
        //enable pull-up mode
        io_conf.pull_up_en = 1;
        gpio_config(&io_conf);

        //change gpio intrrupt type for one pin
        gpio_set_intr_type(GPIO_INPUT_IO_0, GPIO_INTR_ANYEDGE);

        //create a queue to handle gpio event from isr
        gpio_evt_queue = xQueueCreate(10, sizeof(uint32_t));
        //start gpio task
        xTaskCreate(gpio_task_example, "gpio_task_example", 2048, NULL, 10, NULL);

        //install gpio isr service
        gpio_install_isr_service(ESP_INTR_FLAG_DEFAULT);
        //hook isr handler for specific gpio pin
        gpio_isr_handler_add(GPIO_INPUT_IO_0, gpio_isr_handler, (void*) GPIO_INPUT_IO_0);
        //hook isr handler for specific gpio pin
        gpio_isr_handler_add(GPIO_INPUT_IO_1, gpio_isr_handler, (void*) GPIO_INPUT_IO_1);

        //remove isr handler for gpio number.
        gpio_isr_handler_remove(GPIO_INPUT_IO_0);
        //hook isr handler for specific gpio pin again
        gpio_isr_handler_add(GPIO_INPUT_IO_0, gpio_isr_handler, (void*) GPIO_INPUT_IO_0);

        int cnt = 0;
        while(1) {
            printf("cnt: %d\n", cnt++);
            vTaskDelay(1000 / portTICK_RATE_MS);
            gpio_set_level(GPIO_OUTPUT_IO_0, cnt % 2);
            gpio_set_level(GPIO_OUTPUT_IO_1, cnt % 2);
        }
    }

El resultado es::

    cnt: 1
    GPIO[4] intr, val: 1
    GPIO[5] intr, val: 1
    cnt: 2
    GPIO[4] intr, val: 0
    cnt: 3
    GPIO[4] intr, val: 1
    GPIO[5] intr, val: 1
    cnt: 4
    GPIO[4] intr, val: 0
    cnt: 5
    GPIO[4] intr, val: 1
    GPIO[5] intr, val: 1
    cnt: 6
    GPIO[4] intr, val: 0
    cnt: 7

Varias consideraciones:
    
* La interrupción de más baja prioridad interrumpirá la tarea de más alta prioridad. Las tareas son manejadas por software, 
  mientras que las interrupciones son lanzadas por hardware.
* Debido a lo anterior, es recomendable que las interrupciones sean, en lo posible, muy cortas y el procesamiento diferido.
* El procesamiento de interrupciones diferido consiste en que la interrupción registra la causa de la interrupción y le 
  informa a una tarea acerca de ésta, es decir, la interrupción delega el procesamiento a una tarea. Esto permite salir 
  rápidamente de la interrupción.
* Las interrupciones utilizan funciones del API de FreeRTOS especialmente disañadas para su contexto. El nombre de las 
  funciones utilizadas por las interrupciones es casi idéntico a las funciones que usan las tareas más la terminación 
  ``FromISR``. Por ejemplo, en el código anterior ``xQueueSendFromISR(gpio_evt_queue, &gpio_num, NULL);``.
* Algunas funciones del API para las interrupciones incluyen el puntero ``pxHigherPriorityTaskWoken``. Dichas funciones 
  colocarán en ``pdTRUE`` la variable apuntada si el llamado a la función hace que una tarea de más alta prioridad que la 
  tarea que actualmente está corriendo se desbloquee. Por tanto, la variable apuntada por ``pxHigherPriorityTaskWoken`` debe 
  inicializarse en ``pdFALSE``.

Ejercicio 3: semáforos binarios, RETO!
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Los semáforos binarios permiten informarle a una tarea que el evento por el cual esperan ha ocurrido. De esta manera, 
mediante el uso de un semáforo binario, es posible sincronizar tareas o una tarea con una interrupción. El API 
para utilizar semáforos binarios está definido aquí ``freertos/include/freertos/semphr.h``. Cuando un semáforo binario se 
utiliza para sincronizar una interrupción con un tarea, la interrupción ejecutará continuamente una operación ``give`` sobre 
el semáforo, mientras que la tarea realizará un ``take``. Si el semáforo no está disponible, la operación ``take`` 
bloqueará la tarea hasta que la interrupción realice la operación ``give``, momento en el cual la tarea bloqueada estará lista 
para correr. La siguiente figura ilustra el funcionamiento de un semáforo binario:

.. image:: ../_static/semaphore.jpeg

El reto consiste en repetir el ejercicio anterior pero sólo con una pareja de puertos de entrada salida y utilizando un 
semáforo binario para realizar el procesamiento diferido de la interrupción. 







