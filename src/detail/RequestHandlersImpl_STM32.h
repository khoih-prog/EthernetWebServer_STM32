/****************************************************************************************************************************
   RequestHandlerImpl.h - Dead simple web-server.
   For STM32 with built-in Ethernet LAN8742A (Nucleo-144, DISCOVERY, etc) or W5x00/ENC28J60 shield/module

   EthernetWebServer_STM32 is a library for the STM32 running Ethernet WebServer

   Based on and modified from ESP8266 https://github.com/esp8266/Arduino/releases
   Built by Khoi Hoang https://github.com/khoih-prog/EthernetWebServer_STM32
   Licensed under MIT license
   
   Original author:
   @file       Esp8266WebServer.h
   @author     Ivan Grokhotkov
   
   Version: 1.2.1

   Version Modified By   Date      Comments
   ------- -----------  ---------- -----------
    1.0.0   K Hoang      26/02/2020 Initial coding for STM32 with built-in Ethernet (Nucleo-144, DISCOVERY, etc) and ENC28J60
    1.0.1   K Hoang      28/02/2020 Add W5x00 Ethernet shields using Ethernet library
    1.0.2   K Hoang      05/03/2020 Remove dependency on functional-vlpp
    1.0.3   K Hoang      22/07/2020 Fix bug not closing client and releasing socket. Add features.
    1.0.4   K Hoang      23/07/2020 Add support to all STM32 boards (STM32F/L/H/G/WB/MP1) with 32K+ Flash.
    1.0.5   K Hoang      16/09/2020 Add support to Ethernet2, Ethernet3, Ethernet Large for W5x00
                                    Add support to new EthernetENC library for ENC28J60. Add debug feature.
    1.0.6   K Hoang      24/09/2020 Add support to PROGMEM-related commands, such as sendContent_P() and send_P()
    1.1.0   K Hoang      17/11/2020 Add basic HTTP and WebSockets Client by merging ArduinoHttpClient
    1.1.1   K Hoang      26/12/2020 Suppress all possible compiler warnings. Add Version String
    1.2.0   K Hoang      11/04/2021 Add support to LAN8720 using STM32F4 or STM32F7
    1.2.1   K Hoang      04/10/2021 Change option for PIO `lib_compat_mode` from default `soft` to `strict`. Update Packages Patches
 *************************************************************************************************************************************/

#pragma once

#include "RequestHandler_STM32.h"
#include "mimetable.h"

class FunctionRequestHandler : public RequestHandler
{
  public:

    FunctionRequestHandler(EthernetWebServer::THandlerFunction fn, EthernetWebServer::THandlerFunction ufn, const String &uri, HTTPMethod method)
      : _fn(fn)
      , _ufn(ufn)
      , _uri(uri)
      , _method(method)
    {
    }

    bool canHandle(HTTPMethod requestMethod, String requestUri) override
    {
      if (_method != HTTP_ANY && _method != requestMethod)
        return false;

      if (requestUri == _uri)
        return true;

      if (_uri.endsWith("/*"))
      {
        String _uristart = _uri;
        _uristart.replace("/*", "");

        if (requestUri.startsWith(_uristart))
          return true;
      }

      return false;
    }

    bool canUpload(String requestUri) override
    {
      if (!_ufn || !canHandle(HTTP_POST, requestUri))
        return false;

      return true;
    }

    bool handle(EthernetWebServer& server, HTTPMethod requestMethod, String requestUri) override
    {
      ETW_UNUSED(server);
      
      if (!canHandle(requestMethod, requestUri))
        return false;

      _fn();
      return true;
    }

    void upload(EthernetWebServer& server, String requestUri, HTTPUpload& upload) override
    {
      ETW_UNUSED(server);
      ETW_UNUSED(upload);
      
      if (canUpload(requestUri))
        _ufn();
    }

  protected:
    EthernetWebServer::THandlerFunction _fn;
    EthernetWebServer::THandlerFunction _ufn;
    String _uri;
    HTTPMethod _method;
};

class StaticRequestHandler : public RequestHandler
{
  public:

    bool canHandle(HTTPMethod requestMethod, String requestUri) override
    {
      if (requestMethod != HTTP_GET)
        return false;

      if ((_isFile && requestUri != _uri) || !requestUri.startsWith(_uri))
        return false;

      return true;
    }

#if USE_NEW_WEBSERVER_VERSION

    static String getContentType(const String& path)
    {
      using namespace mime;
      char buff[sizeof(mimeTable[0].mimeType)];

      // Check all entries but last one for match, return if found
      for (size_t i = 0; i < sizeof(mimeTable) / sizeof(mimeTable[0]) - 1; i++)
      {
        strcpy(buff, mimeTable[i].endsWith);

        if (path.endsWith(buff))
        {
          strcpy(buff, mimeTable[i].mimeType);
          return String(buff);
        }
      }

      // Fall-through and just return default type
      strcpy(buff, mimeTable[sizeof(mimeTable) / sizeof(mimeTable[0]) - 1].mimeType);
      return String(buff);
    }

#else

    static String getContentType(const String& path)
    {
      if (path.endsWith(".html"))           return "text/html";
      else if (path.endsWith(".htm"))       return "text/html";
      else if (path.endsWith(".css"))       return "text/css";
      else if (path.endsWith(".txt"))       return "text/plain";
      else if (path.endsWith(".js"))        return "application/javascript";
      else if (path.endsWith(".png"))       return "image/png";
      else if (path.endsWith(".gif"))       return "image/gif";
      else if (path.endsWith(".jpg"))       return "image/jpeg";
      else if (path.endsWith(".ico"))       return "image/x-icon";
      else if (path.endsWith(".svg"))       return "image/svg+xml";
      else if (path.endsWith(".ttf"))       return "application/x-font-ttf";
      else if (path.endsWith(".otf"))       return "application/x-font-opentype";
      else if (path.endsWith(".woff"))      return "application/font-woff";
      else if (path.endsWith(".woff2"))     return "application/font-woff2";
      else if (path.endsWith(".eot"))       return "application/vnd.ms-fontobject";
      else if (path.endsWith(".sfnt"))      return "application/font-sfnt";
      else if (path.endsWith(".xml"))       return "text/xml";
      else if (path.endsWith(".pdf"))       return "application/pdf";
      else if (path.endsWith(".zip"))       return "application/zip";
      else if (path.endsWith(".gz"))        return "application/x-gzip";
      else if (path.endsWith(".appcache"))  return "text/cache-manifest";

      return "application/octet-stream";
    }

#endif

  protected:

    String _uri;
    String _path;
    String _cache_header;
    bool _isFile;
    size_t _baseUriLength;
};

