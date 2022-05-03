/****************************************************************************************************************************
  HueBlink.ino - Simple Arduino web server sample for Ethernet shield

  For STM32 with built-in Ethernet LAN8742A (Nucleo-144, DISCOVERY, etc) or W5x00/ENC28J60 shield/module

  EthernetWebServer_STM32 is a library for the STM32 running Ethernet WebServer

  Based on and modified from ESP8266 https://github.com/esp8266/Arduino/releases
  Built by Khoi Hoang https://github.com/khoih-prog/EthernetWebServer_STM32
  Licensed under MIT license

  Uses HttpClient to control Philips Hue
  For more on Hue developer API see http://developer.meethue.com

  To control a light, the Hue expects a HTTP PUT request to:

  http://hue.hub.address/api/hueUserName/lights/lightNumber/state

  The body of the PUT request looks like this:
  {"on": true} or {"on":false}

  This example  shows how to concatenate Strings to assemble the
  PUT request and the body of the request.

  modified 15 Feb 2016
  by Tom Igoe (tigoe) to match new API
 *****************************************************************************************************************************/

#include "defines.h"

char hueHubIP[]     = "192.168.2.223";            // IP address of the HUE bridge
String hueUserName  = "huebridgeusername";        // hue bridge username

EthernetClient      client;
EthernetHttpClient  httpClient(client, hueHubIP);

void setup()
{
  Serial.begin(115200);
  while (!Serial && millis() < 5000);

  Serial.print("\nStarting HueBlink on " + String(BOARD_NAME));
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
}

void sendRequest(int light, String cmd, String value) 
{
  // make a String for the HTTP request path:
  String request = "/api/" + hueUserName;
  request += "/lights/";
  request += light;
  request += "/state/";

  String contentType = "application/json";

  // make a string for the JSON command:
  String hueCmd = "{\"" + cmd;
  hueCmd += "\":";
  hueCmd += value;
  hueCmd += "}";
  
  // see what you assembled to send:
  Serial.print("PUT request to server: ");
  Serial.println(request);
  Serial.print("JSON command to server: ");

  // make the PUT request to the hub:
  httpClient.put(request, contentType, hueCmd);

  // read the status code and body of the response
  int statusCode = httpClient.responseStatusCode();
  String response = httpClient.responseBody();

  Serial.println(hueCmd);
  Serial.print("Status code from server: ");
  Serial.println(statusCode);
  Serial.print("Server response: ");
  Serial.println(response);
  Serial.println();
}

void loop()
{
  sendRequest(3, "on", "true");   // turn light on
  delay(2000);                    // wait 2 seconds
  sendRequest(3, "on", "false");  // turn light off
  delay(2000);                    // wait 2 seconds
}
