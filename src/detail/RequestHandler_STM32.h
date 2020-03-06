/****************************************************************************************************************************
   RequestHandler.h - Dead simple web-server.
   For STM32 with built-in Ethernet (Nucleo-144, DISCOVERY, etc)

   EthernetWebServer_STM32 is a library for the STM32 run built-in Ethernet WebServer

   Forked and modified from ESP8266 https://github.com/esp8266/Arduino/releases
   Built by Khoi Hoang https://github.com/khoih-prog/ESP8266_AT_WebServer
   Licensed under MIT license
   Version: 1.0.2

   Original author:
   @file       Esp8266WebServer.h
   @author     Ivan Grokhotkov

   Version Modified By   Date      Comments
   ------- -----------  ---------- -----------
    1.0.0   K Hoang      26/02/2020 Initial coding for STM32 with built-in Ethernet (Nucleo-144, DISCOVERY, etc) and ENC28J60
    1.0.1   K Hoang      28/02/2020 Add W5x00 Ethernet shields using Ethernet library
    1.0.2   K Hoang      05/03/2020 Remove dependency on functional-vlpp
 *****************************************************************************************************************************/

#ifndef RequestHandler_STM32_h
#define RequestHandler_STM32_h

class RequestHandler {
  public:
    virtual ~RequestHandler() { }
    virtual bool canHandle(HTTPMethod method, String uri) {
      return false;
    }
    virtual bool canUpload(String uri) {
      return false;
    }
    virtual bool handle(EthernetWebServer& server, HTTPMethod requestMethod, String requestUri) {
      return false;
    }
    virtual void upload(EthernetWebServer& server, String requestUri, HTTPUpload& upload) {}

    RequestHandler* next() {
      return _next;
    }
    void next(RequestHandler* r) {
      _next = r;
    }

  private:
    RequestHandler* _next = nullptr;
};

#endif //RequestHandler_STM32_h
