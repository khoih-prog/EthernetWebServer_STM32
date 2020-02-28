/****************************************************************************************************************************
 *  PostServer.h - Dead simple web-server for Ethernet shields
 *
 * For STM32 with built-in Ethernet (Nucleo-144, DISCOVERY, etc)
 *
 * EthernetWebServer_STM32 is a library for the STM32 run built-in Ethernet WebServer
 *
 * Forked and modified from ESP8266 https://github.com/esp8266/Arduino/releases
 * Built by Khoi Hoang https://github.com/khoih-prog/ESP8266_AT_WebServer
 * Licensed under MIT license
 * Version: 1.0.1
 *
 * Original author:
 * @file       Esp8266WebServer.h
 * @author     Ivan Grokhotkov
 *
 * Version Modified By   Date      Comments
 * ------- -----------  ---------- -----------
 *  1.0.0   K Hoang      26/02/2020 Initial coding for STM32 with built-in Ethernet (Nucleo-144, DISCOVERY, etc) and ENC28J60
 *  1.0.1   K Hoang      28/02/2020 Add W5x00 Ethernet shields using Ethernet library
 *****************************************************************************************************************************/
/*
 * Currently support 
 * 1) STM32 boards with built-in Ethernet (to use USE_BUILTIN_ETHERNET = true) such as :
 *    - Nucleo-144 (F429ZI, F767ZI)
 *    - Discovery (STM32F746G-DISCOVERY)
 *    - All STM32 Boards with Built-in Ethernet, See How To Use Built-in Ethernet at (https://github.com/khoih-prog/EthernetWebServer_STM32/issues/1)
 * 2) STM32 boards (with 64+K Flash) running EMC28J60 shields (to use USE_BUILTIN_ETHERNET = false)
 * 3) STM32 boards (with 32+K Flash) running W5x00 Ethernet shields
 * 
 */

#define USE_BUILTIN_ETHERNET    false    //true
//  If don't use USE_BUILTIN_ETHERNET, and USE_UIP_ETHERNET => use W5x00 with Ethernet library
#define USE_UIP_ETHERNET        false 

#include <EthernetWebServer_STM32.h>

// Enter a MAC address and IP address for your controller below.

byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};

// Select the IP address according to your local network
IPAddress ip(192, 168, 2, 200);

EthernetWebServer server(80);

const int led = 13;

const String postForms = 
"<html>\
<head>\
<title>EthernetWebServer POST handling</title>\
<style>\
body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
</style>\
</head>\
<body>\
<h1>POST plain text to /postplain/</h1><br>\
<form method=\"post\" enctype=\"text/plain\" action=\"/postplain/\">\
<input type=\"text\" name=\'{\"hello\": \"world\", \"trash\": \"\' value=\'\"}\'><br>\
<input type=\"submit\" value=\"Submit\">\
</form>\
<h1>POST form data to /postform/</h1><br>\
<form method=\"post\" enctype=\"application/x-www-form-urlencoded\" action=\"/postform/\">\
<input type=\"text\" name=\"hello\" value=\"world\"><br>\
<input type=\"submit\" value=\"Submit\">\
</form>\
</body>\
</html>";

void handleRoot() 
{
  digitalWrite(led, 1);
  server.send(200, "text/html", postForms);
  digitalWrite(led, 0);
}

void handlePlain() 
{
  if (server.method() != HTTP_POST) 
  {
    digitalWrite(led, 1);
    server.send(405, "text/plain", "Method Not Allowed");
    digitalWrite(led, 0);
  } else 
  {
    digitalWrite(led, 1);
    server.send(200, "text/plain", "POST body was:\n" + server.arg("plain"));
    digitalWrite(led, 0);
  }
}

void handleForm() 
{
  if (server.method() != HTTP_POST) 
  {
    digitalWrite(led, 1);
    server.send(405, "text/plain", "Method Not Allowed");
    digitalWrite(led, 0);
  } 
  else 
  {
    digitalWrite(led, 1);
    String message = "POST form was:\n";
    for (uint8_t i = 0; i < server.args(); i++) 
    {
      message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
    }
    server.send(200, "text/plain", message);
    digitalWrite(led, 0);
  }
}

void handleNotFound() 
{
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i = 0; i < server.args(); i++) 
  {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}

void setup(void) 
{
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  
  Serial.begin(115200);
  delay(1000);
  Serial.println("\nStarting POSTServer");

  // start the ethernet connection and the server:
  Ethernet.begin(mac, ip);
  
  server.on("/", handleRoot);

  server.on("/postplain/", handlePlain);

  server.on("/postform/", handleForm);

  server.onNotFound(handleNotFound);

  server.begin();
  
  Serial.print(F("HTTP EthernetWebServer started @ IP : "));
  Serial.println(Ethernet.localIP());
}

void loop(void) 
{
  server.handleClient();
}
