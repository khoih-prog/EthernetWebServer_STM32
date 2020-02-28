/****************************************************************************************************************************
 * SimpleAuthentication.ino - Dead simple web-server for Ethernet shields
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

  String content = "<html><body><form action='/login' method='POST'>To log in, please use : admin/admin<br>";
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

  String content = "<html><body><H2>Hello, you're connected to EthernetWebServer!</H2><br>";

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

void setup(void)
{
  Serial.begin(115200);
  delay(1000);
  Serial.println("\nStarting SimpleAuthentication");

  // start the ethernet connection and the server:
  Ethernet.begin(mac, ip);

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

void loop(void)
{
  server.handleClient();
}
