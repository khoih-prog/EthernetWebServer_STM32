/****************************************************************************************************************************
  SimpleAuthentication_LAN8720.ino - Dead simple web-server for Ethernet shields
  
  For STM32 with built-in Ethernet LAN8742A (Nucleo-144, DISCOVERY, etc) or W5x00/ENC28J60 shield/module

  EthernetWebServer_STM32 is a library for the STM32 running Ethernet WebServer

  Based on and modified from ESP8266 https://github.com/esp8266/Arduino/releases
  Built by Khoi Hoang https://github.com/khoih-prog/EthernetWebServer_STM32
  Licensed under MIT license
 *****************************************************************************************************************************/
/*
   Currently support
   1) STM32 boards with built-in Ethernet (to use USE_BUILTIN_ETHERNET = true) such as :
      - Nucleo-144 (F429ZI, F767ZI)
      - Discovery (STM32F746G-DISCOVERY)
      - STM32 boards (STM32F/L/H/G/WB/MP1) with 32K+ Flash, with Built-in Ethernet, 
      - See How To Use Built-in Ethernet at (https://github.com/khoih-prog/EthernetWebServer_STM32/issues/1)
   2) STM32F/L/H/G/WB/MP1 boards (with 32+K Flash) running ENC28J60 shields (to use USE_BUILTIN_ETHERNET = false)
   3) STM32F/L/H/G/WB/MP1 boards (with 32+K Flash) running W5x00 shields
*/

#include "defines.h"

EthernetWebServer server(80);

//Check if header is present and correct
bool is_authenticated()
{
  Serial.println(F("Enter is_authenticated"));
  
  if (server.hasHeader("Cookie"))
  {
    Serial.print(F("Found cookie: "));
    String cookie = server.header("Cookie");
    Serial.println(cookie);
    if (cookie.indexOf("ESPSESSIONID=1") != -1)
    {
      Serial.println(F("Authentication Successful"));
      return true;
    }
  }
  Serial.println(F("Authentication Failed"));
  return false;
}

//login page, also called for disconnect
void handleLogin()
{
  String msg;

  Serial.println(F("Enter handleLogin"));
  
  if (server.hasHeader("Cookie"))
  {
    Serial.print(F("Found cookie: "));
    String cookie = server.header("Cookie");
    Serial.println(cookie);
  }

  if (server.hasArg("DISCONNECT"))
  {
    Serial.println("Disconnection");
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.sendHeader("Set-Cookie", "ESPSESSIONID=0");
    server.send(301);
    return;
  }

  if (server.hasArg("USERNAME") && server.hasArg("PASSWORD"))
  {
    if (server.arg("USERNAME") == "admin" &&  server.arg("PASSWORD") == "password")
    {
      server.sendHeader("Location", "/");
      server.sendHeader("Cache-Control", "no-cache");
      server.sendHeader("Set-Cookie", "ESPSESSIONID=1");
      server.send(301);
      Serial.println(F("Log in Successful"));
      return;
    }
    msg = "Wrong username/password! try again.";
    Serial.println(F("Log in Failed"));
  }

  String content = "<html><body><form action='/login' method='POST'>To log in, please use : admin/password<br>";
  content += "User:<input type='text' name='USERNAME' placeholder='user name'><br>";
  content += "Password:<input type='password' name='PASSWORD' placeholder='password'><br>";
  content += "<input type='submit' name='SUBMIT' value='Submit'></form>" + msg + "<br>";
  content += "You also can go <a href='/inline'>here</a></body></html>";
  server.send(200, "text/html", content);
}

//root page can be accessed only if authentication is ok
void handleRoot()
{
  String header;

  Serial.println(F("Enter handleRoot"));

  if (!is_authenticated())
  {
    server.sendHeader("Location", "/login");
    server.sendHeader("Cache-Control", "no-cache");
    server.send(301);
    return;
  }

  String content = String("<html><body><H2>Hello, you're connected to EthernetWebServer on ") + BOARD_NAME + "!</H2><br>";

  if (server.hasHeader("User-Agent"))
  {
    content += "the user agent used is : " + server.header("User-Agent") + "<br><br>";
  }

  content += "You can access this page until you <a href=\"/login?DISCONNECT=YES\">disconnect</a></body></html>";
  server.send(200, "text/html", content);
}

//no need authentication
void handleNotFound()
{
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
}

void setup()
{
  Serial.begin(115200);
  delay(2000);

  Serial.println("\nStart SimpleAuthentication_LAN8720 on " + String(BOARD_NAME) + ", using " + String(SHIELD_TYPE));
  Serial.println(ETHERNET_WEBSERVER_STM32_VERSION);
  
  // start the ethernet connection and the server:
  // Use DHCP dynamic IP and random mac
  uint16_t index = millis() % NUMBER_OF_MAC;
  // Use Static IP
  //Ethernet.begin(mac[index], ip);
  Ethernet.begin(mac[index]);
  
  Serial.print(F("Connected! IP address: "));
  Serial.println(Ethernet.localIP());

  server.on("/", handleRoot);
  server.on("/login", handleLogin);

  server.on("/inline", []()
  {
    server.send(200, "text/plain", "this works without need of authentication");
  });

  server.onNotFound(handleNotFound);

  //here the list of headers to be recorded
  const char * headerkeys[] = {"User-Agent", "Cookie"} ;
  size_t headerkeyssize = sizeof(headerkeys) / sizeof(char*);

  //ask server to track these headers
  server.collectHeaders(headerkeys, headerkeyssize);
  server.begin();

  Serial.print(F("HTTP EthernetWebServer is @ IP : "));
  Serial.println(Ethernet.localIP());
}

void loop()
{
  server.handleClient();
}
