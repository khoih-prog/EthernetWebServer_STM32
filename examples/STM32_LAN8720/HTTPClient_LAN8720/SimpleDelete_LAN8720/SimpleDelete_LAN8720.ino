/****************************************************************************************************************************
  SimpleDelete_LAN8720.ino - Simple Arduino web server sample for Ethernet shield

  For STM32 with built-in Ethernet LAN8742A (Nucleo-144, DISCOVERY, etc) or W5x00/ENC28J60 shield/module

  EthernetWebServer_STM32 is a library for the STM32 running Ethernet WebServer

  Based on and modified from ESP8266 https://github.com/esp8266/Arduino/releases
  Built by Khoi Hoang https://github.com/khoih-prog/EthernetWebServer_STM32
  Licensed under MIT license

  Simple DELETE client for HttpClient
  Connects to server once every five seconds, sends a DELETE request
  and a request body

  created 14 Feb 2016
  modified 22 Jan 2019
  by Tom Igoe
 *****************************************************************************************************************************/

#include "defines.h"

char serverAddress[] = "192.168.2.112";  // server address
int port = 8080;

EthernetClient      client;
EthernetHttpClient  httpClient(client, serverAddress, port);

void setup()
{
  Serial.begin(115200);
  delay(2000);

  Serial.print("\nStarting SimpleDelete_LAN8720 on " + String(BOARD_NAME));
  Serial.println(" with " + String(SHIELD_TYPE));
  Serial.println(ETHERNET_WEBSERVER_STM32_VERSION);

  // start the ethernet connection and the server:
  // Use DHCP dynamic IP and random mac
  uint16_t index = millis() % NUMBER_OF_MAC;
  // Use Static IP
  //Ethernet.begin(mac[index], ip);
  Ethernet.begin(mac[index]);

  Serial.print(F("Using mac index = "));
  Serial.println(index);

  Serial.print(F("Connected! IP address: "));
  Serial.println(Ethernet.localIP());
}

void loop()
{
  Serial.println("making DELETE request");
  String contentType = "application/x-www-form-urlencoded";
  String delData = "name=light&age=46";

  httpClient.del("/", contentType, delData);

  // read the status code and body of the response
  int statusCode = httpClient.responseStatusCode();
  String response = httpClient.responseBody();

  Serial.print("Status code: ");
  Serial.println(statusCode);
  Serial.print("Response: ");
  Serial.println(response);

  Serial.println("Wait five seconds");
  delay(5000);
}
