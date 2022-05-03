/****************************************************************************************************************************
  MQTTClient_Basic.ino - Dead simple MQTT Client for Ethernet shields

  EthernetWebServer is a library for the Ethernet shields to run WebServer
  
  Based on and modified from ESP8266 https://github.com/esp8266/Arduino/releases
  Built by Khoi Hoang https://github.com/khoih-prog/EthernetWebServer
  Licensed under MIT license
 *****************************************************************************************************************************/

/*
  Basic MQTT example (without SSL!) with Authentication
  This sketch demonstrates the basic capabilities of the library.
  It connects to an MQTT server then:
  - providing username and password
  - publishes "hello world" to the topic "outTopic"
  - subscribes to the topic "inTopic", printing out any messages
    it receives. NB - it assumes the received payloads are strings not binary
    
  It will reconnect to the server if the connection is lost using a blocking
  reconnect function. See the 'mqtt_reconnect_nonblocking' example for how to
  achieve the same result without blocking the main loop.
*/

#include "defines.h"

#include <PubSubClient.h>

// Update these with values suitable for your network.
const char* mqttServer = "broker.emqx.io";        // Broker address

const char *ID        = "MQTTClient_SSL-Client";  // Name of our device, must be unique
const char *TOPIC     = "MQTT_Pub";               // Topic to subcribe to
const char *subTopic  = "MQTT_Sub";               // Topic to subcribe to

//IPAddress mqttServer(172, 16, 0, 2);

void callback(char* topic, byte* payload, unsigned int length) 
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  
  for (unsigned int i = 0; i < length; i++) 
  {
    Serial.print((char)payload[i]);
  }
  
  Serial.println();
}

EthernetClient  ethClient;
PubSubClient    client(mqttServer, 1883, callback, ethClient);

void reconnect()
{
  // Loop until we're reconnected
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection to ");
    Serial.print(mqttServer);

    // Attempt to connect
    if (client.connect(ID, "try", "try"))
    {
      Serial.println("...connected");
      
      // Once connected, publish an announcement...
      String data = "Hello from MQTTClient_SSL on " + String(BOARD_NAME);

      client.publish(TOPIC, data.c_str());

      //Serial.println("Published connection message successfully!");
      //Serial.print("Subcribed to: ");
      //Serial.println(subTopic);
      
      // This is a workaround to address https://github.com/OPEnSLab-OSU/SSLClient/issues/9
      //ethClientSSL.flush();
      // ... and resubscribe
      client.subscribe(subTopic);
      // for loopback testing
      client.subscribe(TOPIC);
      // This is a workaround to address https://github.com/OPEnSLab-OSU/SSLClient/issues/9
      //ethClientSSL.flush();
    }
    else
    {
      Serial.print("...failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");

      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  Serial.print("\nStart MQTTClient_Basic on " + String(BOARD_NAME));
  Serial.println(" with " + String(SHIELD_TYPE));

#if USE_ETHERNET_GENERIC
  Serial.println(ETHERNET_GENERIC_VERSION);
#endif
  
  Serial.println(ETHERNET_WEBSERVER_STM32_VERSION);

#if !(USE_BUILTIN_ETHERNET)
  #if (USING_SPI2)
    #if defined(CUR_PIN_MISO)
      ET_LOGWARN(F("Default SPI pinout:"));
      ET_LOGWARN1(F("MOSI:"), CUR_PIN_MOSI);
      ET_LOGWARN1(F("MISO:"), CUR_PIN_MISO);
      ET_LOGWARN1(F("SCK:"),  CUR_PIN_SCK);
      ET_LOGWARN1(F("SS:"),   CUR_PIN_SS);
      ET_LOGWARN(F("========================="));
    #endif
  #else
    ET_LOGWARN(F("Default SPI pinout:"));
    ET_LOGWARN1(F("MOSI:"), MOSI);
    ET_LOGWARN1(F("MISO:"), MISO);
    ET_LOGWARN1(F("SCK:"),  SCK);
    ET_LOGWARN1(F("SS:"),   SS);
    ET_LOGWARN(F("========================="));
  #endif
#endif

#if !(USE_BUILTIN_ETHERNET || USE_UIP_ETHERNET)
  // For other boards, to change if necessary
  #if ( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC )
  Ethernet.init (USE_THIS_SS_PIN);

  #elif USE_CUSTOM_ETHERNET
  // You have to add initialization for your Custom Ethernet here
  // This is just an example to setCSPin to USE_THIS_SS_PIN, and can be not correct and enough
  //Ethernet.init(USE_THIS_SS_PIN);

  #endif  //( ( USE_ETHERNET_GENERIC || USE_ETHERNET_ENC )
#endif

  // start the ethernet connection and the server:
  // Use DHCP dynamic IP and random mac
  uint16_t index = millis() % NUMBER_OF_MAC;
  // Use Static IP
  //Ethernet.begin(mac[index], ip);
  Ethernet.begin(mac[index]);

  Serial.print(F("Connected! IP address: "));
  Serial.println(Ethernet.localIP());

  client.setServer(mqttServer, 1883);
  client.setCallback(callback);

  // Allow the hardware to sort itself out
  delay(1500);
}

#define MQTT_PUBLISH_INTERVAL_MS       5000L

String data         = "Hello from MQTTClient_Basic on " + String(BOARD_NAME) + " with " + String(SHIELD_TYPE);
const char *pubData = data.c_str();

unsigned long lastMsg = 0;

void loop() 
{
  static unsigned long now;
  
  if (!client.connected()) 
  {
    reconnect();
  }

  // Sending Data
  now = millis();
  
  if (now - lastMsg > MQTT_PUBLISH_INTERVAL_MS)
  {
    lastMsg = now;

    if (!client.publish(TOPIC, pubData))
    {
      Serial.println("Message failed to send.");
    }

    Serial.print("Message Send : " + String(TOPIC) + " => ");
    Serial.println(data);
  }
  
  client.loop();
}
