## EthernetWebServer_STM32

[![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer_STM32.svg?)](https://www.ardu-badge.com/EthernetWebServer_STM32)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/EthernetWebServer_STM32.svg)](https://github.com/khoih-prog/EthernetWebServer_STM32/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/EthernetWebServer_STM32/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/EthernetWebServer_STM32.svg)](http://github.com/khoih-prog/EthernetWebServer_STM32/issues)

---

#### New in v1.0.3

1. Fix bug not closing client and releasing socket.
2. Merge new features from latest ESP8266WebServer
3. Add and enhance examples.
4. Add back dependency to [`Functional-VLPP library`](https://github.com/khoih-prog/functional-vlpp).

### New in Version v1.0.2

1. Remove dependency on [`Functional-VLPP library`](https://github.com/khoih-prog/functional-vlpp).
2. Enhance examples and update README.md

### New in Version v1.0.1

1. Add support to ***W5x00*** Ethernet shields to all STM32 boards having 64+K bytes Flash.

This library currently supports
1. STM32 boards with built-in Ethernet such as :
  - ***Nucleo-144 (F429ZI, F767ZI)***
  - ***Discovery (STM32F746G-DISCOVERY)***
  - ***All STM32 Boards with Built-in Ethernet***, See [How To Use Built-in Ethernet](https://github.com/khoih-prog/EthernetWebServer_STM32/issues/1)
2. ***STM32 boards (with 64+K Flash) running ENC28J60 shields***
3. ***STM32 boards (with 64+K Flash) running W5x00 shields***
4. See [EthernetWebServer Library Issue 1](https://github.com/khoih-prog/EthernetWebServer/issues/1) for reason to create this separate library from [EthernetWebServer library](https://github.com/khoih-prog/EthernetWebServer)

---

This is simple yet complete WebServer library for `STM32` boards running built-in Ethernet (Nucleo-144, Discovery) or EMC28J60 Ethernet shields. The functions are similar and compatible to ESP8266/ESP32 WebServer libraries to make life much easier to port sketches from ESP8266/ESP32.

The library supports 
1. TCP/UDP Server and Client
2. HTTP Server and Client
3. HTTP GET and POST requests, provides argument parsing, handles one client at a time.

Library is based on and modified from:
1. [Ivan Grokhotkov's ESP8266WebServer](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WebServer)

The EthernetWebServer class found in `EthernetWebServer_STM32.h` header, is a simple web server that knows how to handle HTTP requests such as GET and POST and can only support one simultaneous client.

---

## Prerequisite
 1. [`Arduino IDE 1.8.12+` for Arduino](https://www.arduino.cc/en/Main/Software)
 2. [`Arduino Core for STM32 1.9.0+`](https://github.com/stm32duino/Arduino_Core_STM32) for STM32 (Use Arduino Board Manager)
 3. [`Functional-VLPP library v1.0.1+`](https://github.com/khoih-prog/functional-vlpp) to use server's lambda function. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/Functional-Vlpp.svg?)](https://www.ardu-badge.com/Functional-Vlpp)
 4. Depending on which Ethernet card you're using:
   - [`STM32Ethernet library v1.2.0+`](https://github.com/stm32duino/STM32Ethernet) for built-in Ethernet on (Nucleo-144, Discovery)
   - [`Ethernet library v2.0.0+`](https://www.arduino.cc/en/Reference/Ethernet) for W5100, W5200 and W5500.
   - [`EthernetLarge library v2.0.0+`](https://github.com/OPEnSLab-OSU/EthernetLarge) for W5100, W5200 and W5500.
   - [`Ethernet2 library v1.0.4+`](https://github.com/khoih-prog/Ethernet2) for W5500.
   - [`Ethernet3 library v1.5.3+`](https://github.com/sstaub/Ethernet3) for W5500/WIZ550io/WIZ850io/USR-ES1 with Wiznet W5500 chip.
   - [`UIPEthernet v2.0.8+`](https://github.com/UIPEthernet/UIPEthernet) for ENC28J60
 4. [`LwIP library v2.1.2+`](https://github.com/stm32duino/LwIP) for built-in Ethernet on (Nucleo-144, Discovery)

---

## Installation

### Use Arduino Library Manager
The best way is to use `Arduino Library Manager`. Search for `EthernetWebServer_STM32`, then select / install the latest version. 
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer_STM32.svg?)](https://www.ardu-badge.com/EthernetWebServer_STM32) for more detailed instructions.

### Manual Install

1. Navigate to [EthernetWebServer_STM32](https://github.com/khoih-prog/EthernetWebServer_STM32) page.
2. Download the latest release `EthernetWebServer_STM32-master.zip`.
3. Extract the zip file to `EthernetWebServer_STM32-master` directory 
4. Copy whole 
  - `EthernetWebServer_STM32-master` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO:
1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install **EthernetWebServer_STM32** library by using [Library Manager](https://docs.platformio.org/en/latest/librarymanager/). Search for ***EthernetWebServer_STM32*** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](examples/platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically.

---

### Libraries' Patches

1. If your application requires 2K+ HTML page, the current [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) must be modified if you are using W5200/W5500 Ethernet shields. W5100 is not supported for 2K+ buffer. If you use boards requiring different CS/SS pin for W5x00 Ethernet shield, for example ESP32, ESP8266, nRF52, etc., you also have to modify the following libraries to be able to specify the CS/SS pin correctly.

2. To fix [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet), just copy these following files into the [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) directory to overwrite the old files:
- [Ethernet.h](LibraryPatches/Ethernet/src/Ethernet.h)
- [Ethernet.cpp](LibraryPatches/Ethernet/src/Ethernet.cpp)
- [EthernetServer.cpp](LibraryPatches/Ethernet/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/Ethernet/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/Ethernet/src/utility/w5100.cpp)

3. To fix [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge), just copy these following files into the [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge) directory to overwrite the old files:
- [EthernetLarge.h](LibraryPatches/EthernetLarge/src/EthernetLarge.h)
- [EthernetLarge.cpp](LibraryPatches/EthernetLarge/src/EthernetLarge.cpp)
- [EthernetServer.cpp](LibraryPatches/EthernetLarge/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/EthernetLarge/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/EthernetLarge/src/utility/w5100.cpp)

4. To fix [`UIPEthernet`](https://github.com/UIPEthernet/UIPEthernet), just copy these following files into the [`UIPEthernet`](https://github.com/UIPEthernet/UIPEthernet) directory to overwrite the old files:
- [Enc28J60Network.h](LibraryPatches/UIPEthernet/utility/Enc28J60Network.h)
- [Enc28J60Network.cpp](LibraryPatches/UIPEthernet/utility/Enc28J60Network.cpp)

5. Check if you need to install the UIPthernet patch [new STM32 core F3/F4 compatibility](https://github.com/UIPEthernet/UIPEthernet/commit/c6d6519a260166b722b9cee5dd1f0fb2682e6782) to avoid errors `#include HardwareSPI.h` on some STM32 boards (Nucleo-32 F303K8, etc.)

---

### Configuration Notes

#### 1. How to select which Ethernet to use

Select ***one and only one*** Ethernet library to use as follows:

- Standard W5x00 Ethernet library is used by default, in the sketch, just be sure to comment out or leave these #defines to be false :

```
#define USE_BUILTIN_ETHERNET    false
//  If don't use USE_BUILTIN_ETHERNET, and USE_UIP_ETHERNET => use W5x00 with Ethernet library
#define USE_UIP_ETHERNET        false 

```

- To use built-in LAN8742A :

```
#define USE_BUILTIN_ETHERNET    true
//  If don't use USE_BUILTIN_ETHERNET, and USE_UIP_ETHERNET => use W5x00 with Ethernet library
#define USE_UIP_ETHERNET        false 
```

- To use ENC28J60 Ethernet :

```
#define USE_BUILTIN_ETHERNET    false
//  If don't use USE_BUILTIN_ETHERNET, and USE_UIP_ETHERNET => use W5x00 with Ethernet library
#define USE_UIP_ETHERNET        true
```
---

### HOWTO

#### 1. Use new Ethernet Library and shield

 1. The ***Ethernet_Shield_W5200, EtherCard, EtherSia  libraries are not supported***. Don't use unless you know how to modify those libraries.
 2. Requests to support for any future custom Ethernet library will be ignored. ***Use at your own risk***.

#### 2. Select another CS/SS pin to use

The default CS/SS pin is 10 for all boards.

---

### Usage

#### Class Constructor

```cpp
  EthernetWebServer server(80);
```

Creates the EthernetWebServer class object.

*Parameters:* 
 
host port number: ``int port`` (default is the standard HTTP port 80)

#### Basic Operations

***Starting the server***

```cpp
  void begin();
```

***Handling incoming client requests***

```cpp
  void handleClient();
```

***Disabling the server***

```cpp
  void close();
  void stop();
```

Both methods function the same

***Client request handlers***

```cpp
  void on();
  void addHandler();
  void onNotFound();
  void onFileUpload();	
```

Example:*

```cpp
  server.on("/", handlerFunction);
  server.onNotFound(handlerFunction);   // called when handler is not assigned
  server.onFileUpload(handlerFunction); // handle file uploads
```

***Sending responses to the client***

```cpp
  void send();
  void send_P();
```

`Parameters:`

`code` - HTTP response code, can be `200` or `404`, etc.

`content_type` - HTTP content type, like `"text/plain"` or `"image/png"`, etc.

`content` - actual content body

#### Advanced Options

***Getting information about request arguments***

```cpp
  const String & arg();
  const String & argName();
  int args();
  bool hasArg();
```

`Function usage:`

`arg` - get request argument value, use `arg("plain")` to get POST body
	
`argName` - get request argument name
	
`args` - get arguments count
	
`hasArg` - check if argument exist

***Getting information about request headers***

```cpp
  const String & header();
  const String & headerName();
  const String & hostHeader();
  int headers();
  bool hasHeader();
``` 
`Function usage:`

`header` - get request header value

`headerName` - get request header name

`hostHeader` - get request host header if available, else empty string
  
`headers` - get header count
	
`hasHeader` - check if header exist

***Authentication***

```cpp
  bool authenticate();
  void requestAuthentication();
```

`Function usage:`

`authenticate` - server authentication, returns true if client is authenticated else false

`requestAuthentication` - sends authentication failure response to the client

`Example Usage:`

```cpp

  if(!server.authenticate(username, password)){
    server.requestAuthentication();
  }
```

#### Other Function Calls

```cpp
  const String & uri(); // get the current uri
  HTTPMethod  method(); // get the current method 
  WiFiClient client(); // get the current client
  HTTPUpload & upload(); // get the current upload
  void setContentLength(); // set content length
  void sendHeader(); // send HTTP header
  void sendContent(); // send content
  void sendContent_P(); 
  void collectHeaders(); // set the request headers to collect
  void serveStatic();
  size_t streamFile();
```

---

## Examples

Also see examples: 
 1. [HelloServer](examples/HelloServer)
 2. [HelloServer2](examples/HelloServer2)
 3. [AdvancedWebServer](examples/AdvancedWebServer)
 4. [HttpBasicAuth](examples/HttpBasicAuth)
 5. [PostServer](examples/PostServer)
 6. [SimpleAuthentication](examples/SimpleAuthentication)
 7. [UdpNTPClient](examples/UdpNTPClient)
 8. [UdpSendReceive](examples/UdpSendReceive)
 9. [WebClient](examples/WebClient)
10. [WebClientRepeating](examples/WebClientRepeating)
11. [WebServer](examples/WebServer)

### Example [AdvancedWebServer](examples/AdvancedWebServer)

Please take a look at other examples, as well.

```cpp
/*
   Currently support
   1) STM32 boards with built-in Ethernet (to use USE_BUILTIN_ETHERNET = true) such as :
      - Nucleo-144 (F429ZI, F767ZI)
      - Discovery (STM32F746G-DISCOVERY)
      - All STM32 Boards with Built-in Ethernet, See How To Use Built-in Ethernet at (https://github.com/khoih-prog/EthernetWebServer_STM32/issues/1)
   2) STM32 boards (with 64+K Flash) running EMC28J60 shields (to use USE_BUILTIN_ETHERNET = false)
   3) STM32 boards (with 32+K Flash) running W5x00 Ethernet shields

*/

#if !( defined(STM32F0) || defined(STM32F1) || defined(STM32F2) || defined(STM32F3)  ||defined(STM32F4) || defined(STM32F7) )
#error This code is designed to run on STM32F platform! Please check your Tools->Board setting.
#endif

#define DEBUG_ETHERNET_WEBSERVER_PORT       Serial

// Debug Level from 0 to 4
#define _ETHERNET_WEBSERVER_LOGLEVEL_       4

#define USE_BUILTIN_ETHERNET    true
//  If don't use USE_BUILTIN_ETHERNET, and USE_UIP_ETHERNET => use W5x00 with Ethernet library
#define USE_UIP_ETHERNET        true  //false 

#if (USE_BUILTIN_ETHERNET)
#define ETHERNET_NAME     "Built-in LAN8742A Ethernet"
#elif (USE_UIP_ETHERNET)
#define ETHERNET_NAME     "ENC28J60 Ethernet Shield"
#else
#define ETHERNET_NAME     "W5x00 Ethernet Shield"
#endif

#if defined(STM32F0)
#warning STM32F0 board selected
#define BOARD_TYPE  "STM32F0"
#elif defined(STM32F1)
#warning STM32F1 board selected
#define BOARD_TYPE  "STM32F1"
#elif defined(STM32F2)
#warning STM32F2 board selected
#define BOARD_TYPE  "STM32F2"
#elif defined(STM32F3)
#warning STM32F3 board selected
#define BOARD_TYPE  "STM32F3"
#elif defined(STM32F4)
#warning STM32F4 board selected
#define BOARD_TYPE  "STM32F4"
#elif defined(STM32F7)
#warning STM32F7 board selected
#define BOARD_TYPE  "STM32F7"
#else
#warning STM32 unknown board selected
#define BOARD_TYPE  "STM32 Unknown"
#endif

#ifndef BOARD_NAME
  #define BOARD_NAME    BOARD_TYPE
#endif

#include <EthernetWebServer_STM32.h>

// Enter a MAC address and IP address for your controller below.
#define NUMBER_OF_MAC      20

byte mac[][NUMBER_OF_MAC] =
{
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x01 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x02 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x03 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x04 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x05 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x06 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x07 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x08 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x09 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0A },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0B },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0C },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0D },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0E },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x0F },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x10 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x11 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x12 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x13 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0x32, 0x14 },
};
// Select the IP address according to your local network
IPAddress ip(192, 168, 2, 232);

EthernetWebServer server(80);

int reqCount = 0;                // number of requests received

const int led = 13;

void handleRoot()
{
  digitalWrite(led, 1);
  
  #define BUFFER_SIZE     400
  
  char temp[BUFFER_SIZE];
  int sec = millis() / 1000;
  int min = sec / 60;
  int hr = min / 60;
  int day = hr / 24;

  snprintf(temp, BUFFER_SIZE - 1,
           "<html>\
<head>\
<meta http-equiv='refresh' content='5'/>\
<title>AdvancedServer %s</title>\
<style>\
body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }\
</style>\
</head>\
<body>\
<h2>Hi from EthernetWebServer!</h2>\
<h3>on %s</h3>\
<p>Uptime: %d d %02d:%02d:%02d</p>\
<img src=\"/test.svg\" />\
</body>\
</html>", BOARD_NAME, BOARD_NAME, day, hr % 24, min % 60, sec % 60);

  server.send(200, "text/html", temp);
  
  digitalWrite(led, 0);
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

void drawGraph()
{
  String out;
  out.reserve(3000);
  char temp[70];
  out += "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"310\" height=\"150\">\n";
  out += "<rect width=\"310\" height=\"150\" fill=\"rgb(250, 230, 210)\" stroke-width=\"1\" stroke=\"rgb(0, 0, 0)\" />\n";
  out += "<g stroke=\"black\">\n";
  int y = rand() % 130;

  for (int x = 10; x < 300; x += 10)
  {
    int y2 = rand() % 130;
    sprintf(temp, "<line x1=\"%d\" y1=\"%d\" x2=\"%d\" y2=\"%d\" stroke-width=\"1\" />\n", x, 140 - y, x + 10, 140 - y2);
    out += temp;
    y = y2;
  }
  out += "</g>\n</svg>\n";

  server.send(200, "image/svg+xml", out);
}

void setup(void)
{
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);

  Serial.begin(115200);
  Serial.println("\nStart AdvancedWebServer on " + String(BOARD_NAME) + " board, running " + String(ETHERNET_NAME));

  // start the ethernet connection and the server
  // Use random mac
  srand(1);
  uint16_t index = rand() % NUMBER_OF_MAC;
  //uint16_t index = random(NUMBER_OF_MAC);

  // Use Static IP
  //Ethernet.begin(mac[index], ip);
  // Use DHCP dynamic IP and random mac
  Ethernet.begin(mac[index]);

  server.on("/", handleRoot);
  server.on("/test.svg", drawGraph);
  server.on("/inline", []()
  {
    server.send(200, "text/plain", "This works as well");
  });

  server.onNotFound(handleNotFound);
  server.begin();

  Serial.print(F("HTTP EthernetWebServer is @ IP : "));
  Serial.println(Ethernet.localIP());
}

void loop(void)
{
  server.handleClient();
}
```

---

### Debug Termimal Output Samples

1. Following is debug terminal output and screen shot when running example [AdvancedWebServer](examples/AdvancedWebServer) on STM32 Nucleo-144 NUCLEO_F767ZI running Built-in LAN8742A Ethernet

<p align="center">
    <img src="https://github.com/khoih-prog/EthernetWebServer_STM32/blob/master/pics/AdvancedWebServer.png">
</p>

```
Start AdvancedWebServer on NUCLEO_F767ZI board, running Built-in LAN8742A Ethernet
HTTP EthernetWebServer is @ IP : 192.168.2.150
EthernetWebServer::handleClient: New Client
method:  GET
url:  /
search:
headerName: Host
headerValue: 192.168.2.150
headerName: Connection
headerValue: keep-alive
headerName: Cache-Control
headerValue: max-age=0
headerName: DNT
headerValue: 1
headerName: Upgrade-Insecure-Requests
headerValue: 1
headerName: User-Agent
headerValue: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.89 Safari/537.36
headerName: Accept
headerValue: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9
headerName: Accept-Encoding
headerValue: gzip, deflate
headerName: Accept-Language
headerValue: en-GB,en-US;q=0.9,en;q=0.8
args:
args count:  0
args:
args count:  0
Request: /
Arguments: 
Final list of key/value pairs:
EthernetWebServer::_handleRequest handle
EthernetWebServer::send1: len =  341
content =  <html><head><meta http-equiv='refresh' content='5'/><title>AdvancedWebServer NUCLEO_F767ZI</title><style>body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }</style></head><body><h2>Hi from EthernetWebServer!</h2><h3>on NUCLEO_F767ZI</h3><p>Uptime: 0 d 00:00:31</p><img src="/test.svg" /></body></html>
EthernetWebServer::_prepareHeader sendHeader Conn close
EthernetWebServer::send1: write header =  HTTP/1.1 200 OK
Content-Type: text/html
Content-Length: 341
Connection: close

EthernetWebServer::sendContent: Client.write content:  <html><head><meta http-equiv='refresh' content='5'/><title>AdvancedWebServer NUCLEO_F767ZI</title><style>body { background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }</style></head><body><h2>Hi from EthernetWebServer!</h2><h3>on NUCLEO_F767ZI</h3><p>Uptime: 0 d 00:00:31</p><img src="/test.svg" /></body></html>
EthernetWebServer::_handleRequest OK
EthernetWebServer::handleClient: Don't keepCurrentClient
EthernetWebServer::handleClient: Client disconnected
EthernetWebServer::handleClient: New Client
method:  GET
url:  /test.svg
search:
headerName: Host
headerValue: 192.168.2.150
headerName: Connection
headerValue: keep-alive
headerName: User-Agent
headerValue: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/84.0.4147.89 Safari/537.36
headerName: DNT
headerValue: 1
headerName: Accept
headerValue: image/webp,image/apng,image/*,*/*;q=0.8
headerName: Referer
headerValue: http://192.168.2.150/
headerName: Accept-Encoding
headerValue: gzip, deflate
headerName: Accept-Language
headerValue: en-GB,en-US;q=0.9,en;q=0.8
args:
args count:  0
args:
args count:  0
Request: /test.svg
Arguments: 
Final list of key/value pairs:
EthernetWebServer::_handleRequest handle
EthernetWebServer::send1: len =  1949
content =  <svg xmlns="http://www.w3.org/2000/svg" version="1.1" width="310" height="150">
<rect width="310" height="150" fill="rgb(250, 230, 210)" stroke-width="1" stroke="rgb(0, 0, 0)" />
<g stroke="black">
<line x1="10" y1="90" x2="20" y2="22" stroke-width="1" />
<line x1="20" y1="22" x2="30" y2="98" stroke-width="1" />
<line x1="30" y1="98" x2="40" y2="64" stroke-width="1" />
<line x1="40" y1="64" x2="50" y2="104" stroke-width="1" />
<line x1="50" y1="104" x2="60" y2="31" stroke-width="1" />
<line x1="60" y1="31" x2="70" y2="59" stroke-width="1" />
<line x1="70" y1="59" x2="80" y2="139" stroke-width="1" />
<line x1="80" y1="139" x2="90" y2="117" stroke-width="1" />
<line x1="90" y1="117" x2="100" y2="75" stroke-width="1" />
<line x1="100" y1="75" x2="110" y2="72" stroke-width="1" />
<line x1="110" y1="72" x2="120" y2="137" stroke-width="1" />
<line x1="120" y1="137" x2="130" y2="20" stroke-width="1" />
<line x1="130" y1="20" x2="140" y2="94" stroke-width="1" />
<line x1="140" y1="94" x2="150" y2="81" stroke-width="1" />
<line x1="150" y1="81" x2="160" y2="38" stroke-width="1" />
<line x1="160" y1="38" x2="170" y2="33" stroke-width="1" />
<line x1="170" y1="33" x2="180" y2="53" stroke-width="1" />
<line x1="180" y1="53" x2="190" y2="88" stroke-width="1" />
<line x1="190" y1="88" x2="200" y2="32" stroke-width="1" />
<line x1="200" y1="32" x2="210" y2="110" stroke-width="1" />
<line x1="210" y1="110" x2="220" y2="87" stroke-width="1" />
<line x1="220" y1="87" x2="230" y2="11" stroke-width="1" />
<line x1="230" y1="11" x2="240" y2="98" stroke-width="1" />
<line x1="240" y1="98" x2="250" y2="76" stroke-width="1" />
<line x1="250" y1="76" x2="260" y2="121" stroke-width="1" />
<line x1="260" y1="121" x2="270" y2="139" stroke-width="1" />
<line x1="270" y1="139" x2="280" y2="103" stroke-width="1" />
<line x1="280" y1="103" x2="290" y2="60" stroke-width="1" />
<line x1="290" y1="60" x2="300" y2="36" stroke-width="1" />
</g>
</svg>

EthernetWebServer::_prepareHeader sendHeader Conn close
EthernetWebServer::send1: write header =  HTTP/1.1 200 OK
Content-Type: image/svg+xml
Content-Length: 1949
Connection: close

```

2. The following is debug terminal output and screen shot when running example [WebClient](examples/WebClient) on STM32 Nucleo-144 NUCLEO_F767ZI running Built-in LAN8742A Ethernet

```
 
Start WebClient on NUCLEO_F767ZI board, running Built-in LAN8742A Ethernet
You're connected to the network, IP = 192.168.2.150

Starting connection to server...
Connected to server
HTTP/1.1 200 OK
Server: nginx/1.4.2
Date: Wed, 22 Jul 2020 21:49:29 GMT
Content-Type: text/plain
Content-Length: 2263
Last-Modified: Wed, 02 Oct 2013 13:46:47 GMT
Connection: close
Vary: Accept-Encoding
ETag: "524c23c7-8d7"
Accept-Ranges: bytes


           `:;;;,`                      .:;;:.           
        .;;;;;;;;;;;`                :;;;;;;;;;;:     TM 
      `;;;;;;;;;;;;;;;`            :;;;;;;;;;;;;;;;
     :;;;;;;;;;;;;;;;;;;         `;;;;;;;;;;;;;;;;;;
    ;;;;;;;;;;;;;;;;;;;;;       .;;;;;;;;;;;;;;;;;;;;
   ;;;;;;;;:`   `;;;;;;;;;     ,;;;;;;;;.`   .;;;;;;;;
  .;;;;;;,         :;;;;;;;   .;;;;;;;          ;;;;;;;
  ;;;;;;             ;;;;;;;  ;;;;;;,            ;;;;;;. 
 ,;;;;;               ;;;;;;.;;;;;;`              ;;;;;; 
 ;;;;;.                ;;;;;;;;;;;`      ```       ;;;;;`
 ;;;;;                  ;;;;;;;;;,       ;;;       .;;;;;
`;;;;:                  `;;;;;;;;        ;;;        ;;;;;
,;;;;`    `,,,,,,,,      ;;;;;;;      .,,;;;,,,     ;;;;;
:;;;;`    .;;;;;;;;       ;;;;;,      :;;;;;;;;     ;;;;;
:;;;;`    .;;;;;;;;      `;;;;;;      :;;;;;;;;     ;;;;;
.;;;;.                   ;;;;;;;.        ;;;        ;;;;;
 ;;;;;                  ;;;;;;;;;        ;;;        ;;;;;
 ;;;;;                 .;;;;;;;;;;       ;;;       ;;;;;,
 ;;;;;;               `;;;;;;;;;;;;                ;;;;; 
 `;;;;;,             .;;;;;; ;;;;;;;              ;;;;;; 
  ;;;;;;:           :;;;;;;.  ;;;;;;;            ;;;;;;
   ;;;;;;;`       .;;;;;;;,    ;;;;;;;;        ;;;;;;;:
    ;;;;;;;;;:,:;;;;;;;;;:      ;;;;;;;;;;:,;;;;;;;;;;
    `;;;;;;;;;;;;;;;;;;;.        ;;;;;;;;;;;;;;;;;;;;
      ;;;;;;;;;;;;;;;;;           :;;;;;;;;;;;;;;;;:
       ,;;;;;;;;;;;;;,              ;;;;;;;;;;;;;; 
         .;;;;;;;;;`                  ,;;;;;;;;:         
                                                         
                                                         
                                                         
                                                         
    ;;;   ;;;;;`  ;;;;:  .;;  ;; ,;;;;;, ;;. `;,  ;;;;
    ;;;   ;;:;;;  ;;;;;; .;;  ;; ,;;;;;: ;;; `;, ;;;:;;
   ,;:;   ;;  ;;  ;;  ;; .;;  ;;   ,;,   ;;;,`;, ;;  ;;
   ;; ;:  ;;  ;;  ;;  ;; .;;  ;;   ,;,   ;;;;`;, ;;  ;;. 
   ;: ;;  ;;;;;:  ;;  ;; .;;  ;;   ,;,   ;;`;;;, ;;  ;;` 
  ,;;;;;  ;;`;;   ;;  ;; .;;  ;;   ,;,   ;; ;;;, ;;  ;;
  ;;  ,;, ;; .;;  ;;;;;:  ;;;;;: ,;;;;;: ;;  ;;, ;;;;;;
  ;;   ;; ;;  ;;` ;;;;.   `;;;:  ,;;;;;, ;;  ;;,  ;;;;

Disconnecting from server...

```

---

### Version v1.0.3

1. Fix bug not closing client and releasing socket.
2. Merge new features from latest ESP8266WebServer
3. Add and enhance examples.
4. Add back dependency to [`Functional-VLPP library`](https://github.com/khoih-prog/functional-vlpp).

### Version v1.0.2

1. Remove dependendy on [`Functional-VLPP library`](https://github.com/khoih-prog/functional-vlpp).
2. Enhance examples and update README.md

### Version v1.0.1

1. Add support to W5x00 Ethernet shields to all STM32 boards having 64+K bytes Flash.

### Version v1.0.0

This is simple yet complete WebServer library for `STM32` boards running built-in Ethernet (Nucleo-144, Discovery) or EMC28J60 Ethernet shields. ***The functions are similar and compatible to ESP8266/ESP32 WebServer libraries*** to make life much easier to port sketches from ESP8266/ESP32.

This library currently supports
1. ***STM32 boards with built-in Ethernet*** such as :
  - Nucleo-144 (F429ZI, F767ZI)
  - Discovery (STM32F746G-DISCOVERY)
  - All STM32 Boards with Built-in Ethernet, See [How To Use Built-in Ethernet](https://github.com/khoih-prog/EthernetWebServer_STM32/issues/1)
  
2. ***STM32 boards (with 64+K Flash) running EMC28J60 shields***
- Nucleo-144
- Nucleo-64
- Discovery
- STM32MP1
- Generic STM32F1 (with 64+K Flash): C8 and up
- Generic STM32F4
- STM32L0
- LoRa boards
- 3-D printer boards
- Generic Flight Controllers
- Midatronics boards

and these boards are not supported:

- Some Nucleo-32 (small Flash/memory)
- Eval (no Serial, just need to redefine in sketch, library and UIPEthernet)
- Generic STM32F0 (small Flash/memory)
- Generic STM32F1 (with 64-K Flash): C6
- Generic STM32F3 : no HardwareSPI.h
- Electronics Speed Controllers (small Flash/memory)

3. HTTP Server and Client
4. HTTP GET and POST requests, provides argument parsing, handles one client at a time.

---

### TO DO

1. Bug Searching and Killing
2. Add SSL/TLS Client and Server support
3. Support more types of Ethernet shields such as W5x00, etc.
4. Support more non-compatible Ethernet Libraries such as Ethernet_Shield_W5200, EtherCard, EtherSia
5. Add mDNS features.
6. Use AsyncTCP features from [Phil Bowles' STM32AsyncTCP](https://github.com/philbowles/STM32AsyncTCP).

### DONE

 1. Add support to ***STM32F1,2,3,4,7 boards*** with 64K+ Flash.
 2. Add support to ***built-in Ethernet LAN8742A*** using [STM32Ethernet library](https://github.com/stm32duino/STM32Ethernet) , for boards such as Nucleo-144 NUCLEO_F767ZI.
 3. Add support to ***Ethernet W5x00***, using either [`Ethernet`](https://www.arduino.cc/en/Reference/Ethernet), [`Ethernet2`](https://github.com/khoih-prog/Ethernet2), [`Ethernet3`](https://github.com/sstaub/Ethernet3) or [`EthernetLarge`](https://github.com/OPEnSLab-OSU/EthernetLarge) library
 4. Add support to Ethernet ***ENC28J60***, using [`UIPEthernet`](https://github.com/UIPEthernet/UIPEthernet) library
 
---

### Contributions and Thanks
1. Based on and modified from [Ivan Grokhotkov's ESP8266WebServer](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266WebServer)
2. [jandrassy](https://github.com/jandrassy) for [UIPEthernet library](https://github.com/UIPEthernet/UIPEthernet)
3. Thanks to [Miguel Alexandre Wisintainer](https://github.com/tcpipchip) to help debug and test.

<table>
  <tr>
    <td align="center"><a href="https://github.com/igrr"><img src="https://github.com/igrr.png" width="100px;" alt="igrr"/><br /><sub><b>⭐️ igrr</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/jandrassy"><img src="https://github.com/jandrassy.png" width="100px;" alt="jandrassy"/><br /><sub><b>jandrassy</b></sub></a><br /></td>
<td align="center"><a href="https://github.com/tcpipchip"><img src="https://github.com/tcpipchip.png" width="100px;" alt="tcpipchip"/><br /><sub><b>tcpipchip</b></sub></a><br /></td>
  </tr> 
</table>

## Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

## Copyright

Copyright 2020- Khoi Hoang


