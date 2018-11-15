Semana 14
===========
Esta semana conectaremos sensores y actuadores a dispositivos de cómputo mediante WiFi.

Objetivos
----------

1. Integrar sensores y actuadores con dispositivos de cómputo utilizando WiFi

Ejercicio 1:
--------------
Analice el funcionamiento del siguiente código escrito en processing:

.. code-block:: java
   :lineno-start: 1

    import processing.net.*;


    final int MAXCLIENTS = 2;

    Server myServer;
    Client myclients[] = new Client[MAXCLIENTS];
    int numberOfClients = 0;
    int val = 0;

    void setup() {
    size(200, 200);
    myServer = new Server(this, 5204);
    }
    
    void draw() {
    val = (val + 1) % 255;
    background(val);

    for (int i = 0; i<MAXCLIENTS; i++) {
        Client clientConnected = myclients[i];
        if (clientConnected != null) {
        if (clientConnected.active()) {
            if(clientConnected.available()>0){
            String line = clientConnected.readStringUntil('>');
            myServer.write(line);
            myServer.write("\r\n");
            sendGroup();
            }
        } else {
            myclients[i] = null;
        }
        }
    }
    }

    void sendGroup(){
    Client clientToSend;
    for (int i = 0; i<MAXCLIENTS; i++) {
        clientToSend = myclients[i];
        if (clientToSend != null) {
        if (clientToSend.active()) {
            clientToSend.write("Hello\r\n");
        } else {
            myclients[i] = null;
        }
        }
    }
    }


    void serverEvent(Server someServer, Client someClient) {
    int i;
    for (i = 0; i<MAXCLIENTS; i++) {
        if (myclients[i] ==null) {
        myclients[i] = someClient;
        println("We have a new client: " + someClient.ip());
        break;
        }
    }
    if (i == MAXCLIENTS) {
        println("Client: " + someClient.ip()+ " is rejected");
        someClient.stop();
    }
    }

¿Qué hace el programa? Corra el programa y conecte clientes utilizando un simulador como
 `hercules <https://www.hw-group.com/software/hercules-setup-utility>`__.

Ejercicio 2:
-------------
Utilizando como base el código anterior realice un programa que permita leer el valor de un sensor BME280 y modificar 
el estado de un LED. El programa correrá en un computador y el sensor y actuador en un ESP32.

Ejercicio 3:
-------------
Simule dos sensores y actuadores más, para un total de 3.