Semana 15
===========
Durante la semana pasado y en la primera sesión de esta semana utilizamos TCP/IP y el model cliente servidor para 
integrar sensores y actuadores utilizando WiFi. En esta sesión vamos a utilizar el protocolo UDP.

Objetivos
----------

1. Integrar sensores y actuadores con dispositivos de cómputo utilizando WiFi y el protocolo UDP.

Ejercicio: analizar el código
------------------------------

Para explorar `UDP <https://www.arduino.cc/en/Reference/WiFi>`__ vamos a realizar un proyecto simple que ilustra el uso 
del protocolo. Se trata de un conjunto de actuadores distribuidos en el espacio. Cada actuador enciende y apaga un puerto
de entrada salida según lo indique el comando recibido por UDP. Adicionalmente se cuenta con un dispositivo, bridge, que
reenvía los comandos enviados por el puerto serial através de WiFi por UDP.

El protocolo de comunicación serial es simple. Se trata de un protocolo ascii compuesto por tres caracteres. El primero indica
a cual actuador se enviará el comando. El segundo el estado deseado para la salida ('1' on, '0' off). Por último 
se envía un carácter de sincronización ('*').

El código del bridge es el siguiente:

.. code-block:: cpp
   :lineno-start: 1

    #include <ESP8266WiFi.h>
    #include <WiFiUdp.h>

    const char* ssid = "YOUR SSID";
    const char* password = "SSID PASSWORD";
    WiFiUDP udpDevice;
    uint16_t localUdpPort = 4210;
    uint16_t UDPPort = 4210;
    #define MAX_LEDSERVERS 3
    const char* hosts[MAX_LEDSERVERS] = {"192.168.0.100", "192.168.0.104", "192.168.0.107"};
    #define SERIALMESSAGESIZE 3

    uint32_t previousMillis = 0;
    #define ALIVE 1000

    void setup() {
    pinMode(D0, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
    digitalWrite(D0, HIGH);
    Serial.begin(9600);
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    // Print the IP address
    Serial.println(WiFi.localIP());
    udpDevice.begin(localUdpPort);
    }

    void networkTask() {
    uint8_t LEDServer = 0;
    uint8_t LEDValue = 0;
    uint8_t syncChar;

    if (Serial.available() >= SERIALMESSAGESIZE) {
        LEDServer = Serial.read() - '0';
        LEDValue = Serial.read();
        syncChar = Serial.read();
        if ((LEDServer == 0) || (LEDServer > 3)) {
        Serial.println("Servidor inválido (seleccione 1,2,3)");
        return;
        }
        if (syncChar == '*') {
        udpDevice.beginPacket(hosts[LEDServer - 1] , UDPPort);
        udpDevice.write(LEDValue);
        udpDevice.endPacket();
        }
    }
    }

    void aliveTask() {
    uint32_t currentMillis;
    static uint8_t ledState = 0;
    currentMillis  = millis();
    if ((currentMillis - previousMillis) >= ALIVE) {
        previousMillis = currentMillis;
        if (ledState == 0) {
        digitalWrite(D0, HIGH);
        ledState = 1;
        }
        else {
        digitalWrite(D0, LOW);
        ledState = 0;
        }
    }
    }

    void loop() {
    networkTask();
    aliveTask();
    }

Note que a diferencia de TCP/IP, con UDP no es necesario establecer una conexión. Los pasos necesario para enviar datos 
por UDP serán:

* Crear un objeto WiFiUDP
* Iniciar el objeto estableciendo un socket compuesto por la dirección IP y el puerto de escucha.
* Iniciar la construcción del paquete a transmitir con beginPacket(), 
* Popular el buffer de transmisión con write.
* Enviar el paquete con endPacket().

El código de los actuadores distribuidos será:

.. code-block:: cpp
   :lineno-start: 1

    #include <ESP8266WiFi.h>
    #include <WiFiUdp.h>

    const char* ssid = "YOUR SSID";
    const char* password = "SSID PASSWORD";
    WiFiUDP udpDevice;
    uint16_t localUdpPort = 4210;


    uint32_t previousMillis = 0;
    #define ALIVE 1000

    void setup() {
    pinMode(D0, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
    digitalWrite(D0, HIGH);
    pinMode(D8, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
    digitalWrite(D8, LOW);
    Serial.begin(9600);
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    // Print the IP address
    Serial.println(WiFi.localIP());
    udpDevice.begin(localUdpPort);
    }


    void networkTask() {
    uint8_t data;
    uint8_t packetSize = udpDevice.parsePacket();
    if (packetSize) {
        data = udpDevice.read();
        if (data == '1') {
        digitalWrite(LED_BUILTIN, LOW);
        digitalWrite(D8, HIGH);
        } else if (data == '0') {
        digitalWrite(LED_BUILTIN, HIGH);
        digitalWrite(D8, LOW);
        }
        // send back a reply, to the IP address and port we got the packet from
        udpDevice.beginPacket(udpDevice.remoteIP(), udpDevice.remotePort());
        udpDevice.write('1');
        udpDevice .endPacket();
    }
    }

    void aliveTask() {
    uint32_t currentMillis;
    static uint8_t ledState = 0;
    currentMillis  = millis();
    if ((currentMillis - previousMillis) >= ALIVE) {
        previousMillis = currentMillis;
        if (ledState == 0) digitalWrite(D0, HIGH);
        else digitalWrite(D0, LOW);
    }
    }

    void loop() {
    networkTask();
    //  aliveTask();
    }


Los pasos para recibir datos por UDP son:

* Crear un objeto WiFiUDP
* Iniciar el objeto estableciendo un socket compuesto por la dirección IP y el puerto de escucha.
* Procesar el siguiente paquete UDP con parsePacket(). Esta acción devolverá el tamaño del paquete en bytes.
* Luego de llamar parsePacket() será posible utilizar los métodos read() y available().
* Leer el paquete.

En el ejemplo mostrado, note que un actuador distribuido responderá al bridge con el carácter '1' cada que reciba un 
paquete. De esta manera el bridge sabrá que el dato llegó a su destino; sin embargo, tenga presente que esta acción de 
validación no es obligatoria en UDP. 

Ejercicio: despliegue del ejercicio
------------------------------------
Para desplegar el ejercicio es necesario identificar claramente las direcciones IP de cada uno de los actuadores remotos.
Utilice un ESP8266 para cada actuador. Un ESP8266 para el bridge. Utilice el programa Hercules para simular la aplicación 
del PC.