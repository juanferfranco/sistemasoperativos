Semana 11
===========
Esta semana continuaremos con la revisión teórica de I2C, pero esta vez acecándonos al componente práctico mediante el 
análisis del API que provee el framework de arduino. Una vez digerido el material anterior se propondrán algunos ejercicios y 
dos retos. Uno de los retos será la comunicación entre dos controladores utilizando I2C y el otro reto la comunicación entre 
un controlador y un sensor.

Objetivos
----------

1. Estudiar y practicar el API de I2C del framework arduino.
2. Solucionar algunos ejercicios prácticos y dos retos de programación con I2C.

API I2C del framework de arduino y ejercicios
----------------------------------------------
En este `enlace <https://drive.google.com/open?id=1Hg5zy4VJLpjAjO-xdBMAljGYHGpOJRmjZoIGko7Xldo>`__ se encuentra el material 
con la descripción del API.

Reto 1:
--------
Se propone realizar un chat entre dos terminales seriales ASCII. Las terminales están conectadas por medio de dos arduinos, 
que a su vez se conectan utilizando I2C.

Reto 2:
---------
En este reto vamos a conectar un sensor a un controlador mediante el bus I2C. Este reto tendrá las siguientes 
consideraciones:

* Reto personal: NO BUSCAR EN INTERNET la solución, NO BUSCAR EN INTERNET soluciones similares para basarse en ellas, 
  SE PUEDE CONSULTAR la documentación de I2C de Arduino, es decir, el API, y las hojas de datos del sensor.

* Se requiere construir un programa interactivo que reciba comandos enviados desde la terminal serial de arduino para:

    * Detectar si el sensor está conectado al sistema de cómputo.
    * Configurar la hora, minutos, segundos y el formato 12H o 24H.
    * Configurar el día, mes, año y día de la semana. 
    * Leer la hora completa (horas, minutos, segundos).
    * Leer la fecha completa (día, mes, año y día de la semana). 
    * Almacenar información en la RAM interna del dispositivo.
    * Leer información de la RAM interna del dispositivo.

* `Hoja de datos <https://www.maximintegrated.com/en/products/digital/real-time-clocks/DS1307.html>`__ 
  del circuito integrado del sensor: 

* Documentación oficial de arduino: https://www.arduino.cc/en/Reference/Wire

* Información del sensor:

* Información del `sensor <http://robotdyn.com/wifi-d1-mini-shield-rtc-ds1307-real-time-clock-with-battery.html>`__

* `Planos <http://robotdyn.com/pub/media/0G-00005695==D1mini-SHLD-RTCDS1307/DOCS/Schematic==0G-00005695==D1mini-SHLD-RTCDS1307.pdf>`__ 
  del sensor.
