/****************************************************************************************************************************
  EthernetWebServer_STM32.hpp - Dead simple web-server.
  For STM32 with built-in Ethernet LAN8742A (Nucleo-144, DISCOVERY, etc) or W5x00/ENC28J60 shield/module

  EthernetWebServer_STM32 is a library for the STM32 running Ethernet WebServer

  Based on and modified from ESP8266 https://github.com/esp8266/Arduino/releases
  Built by Khoi Hoang https://github.com/khoih-prog/EthernetWebServer_STM32
  Licensed under MIT license

  Original author:
  @file       Esp8266WebServer.h
  @author     Ivan Grokhotkov

  Version: 1.5.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      26/02/2020 Initial coding for STM32 with built-in Ethernet (Nucleo-144, DISCOVERY, etc) and ENC28J60
  ...
  1.3.0   K Hoang      20/12/2021 Reduce usage of Arduino String with std::string. Use reference passing instead of value-passing
  1.3.1   K Hoang      25/12/2021 Fix bug
  1.3.2   K Hoang      28/12/2021 Fix wrong http status header bug and authenticate issue caused by libb64
  1.3.3   K Hoang      11/01/2022 Fix libb64 fallthrough compile warning
  1.3.4   K Hoang      02/03/2022 Fix decoding error bug
  1.4.0   K Hoang      04/04/2022 Use Ethernet_Generic library as default for W5x00 Ethernet
  1.4.1   K Hoang      27/04/2022 Change from `arduino.cc` to `arduino.tips` in examples
  1.5.0   K Hoang      04/04/2022 Add support to custom SPI, such as SPI2, SPI3, SPI_New, etc.
 *************************************************************************************************************************************/

#pragma once

#ifndef ETHERNET_WEBSERVER_STM32_HPP
#define ETHERNET_WEBSERVER_STM32_HPP

#define USE_NEW_WEBSERVER_VERSION     true

#include <functional-vlpp.h>

#ifndef USE_BUILTIN_ETHERNET
  // Use true  for built-in Ethernet (Nucleo-144, DISCOVERY, etc) using STM32Ethernet library (https://github.com/khoih-prog/STM32Ethernet)
  // Use false for for ENC28J60 and UIPEthernet library (https://github.com/UIPEthernet/UIPEthernet)
  #define USE_BUILTIN_ETHERNET   false
#endif

#if USE_BUILTIN_ETHERNET
  #include <LwIP.h>
  #include <STM32Ethernet.h>
#elif USE_UIP_ETHERNET
  #include <UIPEthernet.h>
  #include <utility/logging.h>
#elif USE_CUSTOM_ETHERNET
  // Do nothing here
#elif !( USE_ETHERNET_GENERIC || USE_ETHERNET_ESP8266 || USE_ETHERNET_ENC )  
  #include <Ethernet_Generic.hpp>
#endif

#include "detail/mimetable.h"

// For PROGMEM commands
#include <pgmspace.h>

// Permit redefinition of SENDCONTENT_P_BUFFER_SZ in sketch, default is 4K, minimum is 512  bytes
#ifndef SENDCONTENT_P_BUFFER_SZ
  #define SENDCONTENT_P_BUFFER_SZ     4096
  #warning SENDCONTENT_P_BUFFER_SZ using default 4 Kbytes
#else
  #if (SENDCONTENT_P_BUFFER_SZ < 512)
    #undef SENDCONTENT_P_BUFFER_SZ
    #define SENDCONTENT_P_BUFFER_SZ   512
    #warning SENDCONTENT_P_BUFFER_SZ reset to min 512 bytes
  #endif
#endif

#define memccpy_P(dest, src, c, n) memccpy((dest), (src), (c), (n))

#ifndef PGM_VOID_P
  #define PGM_VOID_P const void *
#endif

/////////////////////////////////////////////////////////////////////////

enum HTTPMethod 
{ 
  HTTP_ANY, 
  HTTP_GET,
  HTTP_HEAD,
  HTTP_POST, 
  HTTP_PUT, 
  HTTP_PATCH, 
  HTTP_DELETE, 
  HTTP_OPTIONS 
};

enum HTTPUploadStatus 
{ 
  UPLOAD_FILE_START, 
  UPLOAD_FILE_WRITE, 
  UPLOAD_FILE_END,
  UPLOAD_FILE_ABORTED
};

enum HTTPClientStatus 
{ 
  HC_NONE, 
  HC_WAIT_READ, 
  HC_WAIT_CLOSE 
};

enum HTTPAuthMethod 
{ 
  BASIC_AUTH, 
  DIGEST_AUTH 
};

#define HTTP_DOWNLOAD_UNIT_SIZE 1460

#if !defined(HTTP_UPLOAD_BUFLEN)
  #define HTTP_UPLOAD_BUFLEN 4096   //2048
#endif

#define HTTP_MAX_DATA_WAIT      3000 //ms to wait for the client to send the request
#define HTTP_MAX_POST_WAIT      3000 //ms to wait for POST data to arrive
#define HTTP_MAX_SEND_WAIT      5000 //ms to wait for data chunk to be ACKed
#define HTTP_MAX_CLOSE_WAIT     2000 //ms to wait for the client to close the connection

#define CONTENT_LENGTH_UNKNOWN  ((size_t) -1)
#define CONTENT_LENGTH_NOT_SET  ((size_t) -2)

/////////////////////////////////////////////////////////////////////////

#define RETURN_NEWLINE       "\r\n"

#include <string>
#include <Arduino.h>

typedef std::string EWString;

/////////////////////////////////////////////////////////////////////////

class EthernetWebServer;

typedef struct 
{
  HTTPUploadStatus status;
  String  filename;
  String  name;
  String  type;
  size_t  totalSize;      // file size
  size_t  currentSize;    // size of data currently in buf
  size_t  contentLength;  // size of entire post request, file size + headers and other request data.
  uint8_t buf[HTTP_UPLOAD_BUFLEN];
} HTTPUpload;

#include "detail/RequestHandler_STM32.h"

class EthernetWebServer
{
  public:
    EthernetWebServer(int port = 80);
    ~EthernetWebServer();

    void begin();
    void handleClient();

    void close();
    void stop();

    bool authenticate(const char * username, const char * password);
    void requestAuthentication();

    // Reuse functional-vlpp from v1.0.3
    typedef vl::Func<void(void)> THandlerFunction;
    //typedef std::function<void(void)> THandlerFunction;

    void on(const String &uri, THandlerFunction handler);
    void on(const String &uri, HTTPMethod method, THandlerFunction fn);
    void on(const String &uri, HTTPMethod method, THandlerFunction fn, THandlerFunction ufn);
    void addHandler(RequestHandler* handler);
    void onNotFound(THandlerFunction fn);  //called when handler is not assigned
    void onFileUpload(THandlerFunction fn); //handle file uploads

    String uri() 
    {
      return _currentUri;
    }
    
    HTTPMethod method() 
    {
      return _currentMethod;
    }
    
    EthernetClient client() 
    {
      return _currentClient;
    }
    
    #if USE_NEW_WEBSERVER_VERSION
    HTTPUpload& upload() 
    {
      return *_currentUpload;
    }
    #else
    HTTPUpload& upload() 
    {
      return _currentUpload;
    }
    #endif

    String arg(const String& name);         // get request argument value by name
    String arg(int i);                      // get request argument value by number
    String argName(int i);                  // get request argument name by number
    
    int args();                             // get arguments count
    bool hasArg(const String& name);        // check if argument exists
    void collectHeaders(const char* headerKeys[], const size_t headerKeysCount); // set the request headers to collect
    String header(const String& name);      // get request header value by name
    String header(int i);                   // get request header value by number
    String headerName(int i);               // get request header name by number
    int headers();                          // get header count
    bool hasHeader(const String& name);     // check if header exists

    String hostHeader();                    // get request host header if available or empty String if not

    // send response to the client
    // code - HTTP response code, can be 200 or 404
    // content_type - HTTP content type, like "text/plain" or "image/png"
    // content - actual content body
    void send(int code, const char* content_type = NULL, const String& content = String(""));
    void send(int code, char* content_type, const String& content);
    void send(int code, const String& content_type, const String& content);
    //KH
    void send(int code, char*  content_type, const String& content, size_t contentLength);

    void setContentLength(size_t contentLength);
    void sendHeader(const String& name, const String& value, bool first = false);
    void sendContent(const String& content);
    void sendContent(const String& content, size_t size);
    
    // KH, Restore PROGMEM commands
    void send_P(int code, PGM_P content_type, PGM_P content);
    void send_P(int code, PGM_P content_type, PGM_P content, size_t contentLength);
    
    void sendContent_P(PGM_P content);
    void sendContent_P(PGM_P content, size_t size);
    //////

    static String urlDecode(const String& text);

    template<typename T> size_t streamFile(T &file, const String& contentType) 
    {
      using namespace mime;
      setContentLength(file.size());
      
      if (String(file.name()).endsWith(mimeTable[gz].endsWith) && contentType != mimeTable[gz].mimeType && contentType != mimeTable[none].mimeType) 
      {
        sendHeader("Content-Encoding", "gzip");
      }
      
      send(200, contentType, "");
      
      return _currentClient.write(file);
    }


  protected:
    void _addRequestHandler(RequestHandler* handler);
    void _handleRequest();
    void _finalizeResponse();
    bool _parseRequest(EthernetClient& client);
    
    //KH
    #if USE_NEW_WEBSERVER_VERSION
    void _parseArguments(const String& data);
    int  _parseArgumentsPrivate(const String& data, vl::Func<void(String&,String&,const String&,int,int,int,int)> handler);
    bool _parseForm(EthernetClient& client, const String& boundary, uint32_t len);
    #else
    void _parseArguments(const String& data);    
    bool _parseForm(EthernetClient& client, const String& boundary, uint32_t len);
    #endif
    
    static String _responseCodeToString(int code);
    bool _parseFormUploadAborted();
    void _uploadWriteByte(uint8_t b);
    uint8_t _uploadReadByte(EthernetClient& client);
    void _prepareHeader(String& response, int code, const char* content_type, size_t contentLength);
    void _prepareHeader(EWString& response, int code, const char* content_type, size_t contentLength);
    bool _collectHeader(const char* headerName, const char* headerValue);

    struct RequestArgument 
    {
      String key;
      String value;
    };

    EthernetServer  _server;

    EthernetClient    _currentClient;
    HTTPMethod        _currentMethod;
    String            _currentUri;
    uint8_t           _currentVersion;
    HTTPClientStatus  _currentStatus;
    unsigned long     _statusChange;

    RequestHandler*   _currentHandler;
    RequestHandler*   _firstHandler;
    RequestHandler*   _lastHandler;
    THandlerFunction  _notFoundHandler;
    THandlerFunction  _fileUploadHandler;

    int               _currentArgCount;
    RequestArgument*  _currentArgs;
    
    //KH
    #if USE_NEW_WEBSERVER_VERSION
    HTTPUpload*       _currentUpload;
    int               _postArgsLen;
    RequestArgument*  _postArgs;
    
    #else
    HTTPUpload        _currentUpload;
    #endif
    
    int               _headerKeysCount;
    RequestArgument*  _currentHeaders;
    size_t            _contentLength;
    String            _responseHeaders;

    String            _hostHeader;
    bool              _chunked;
};


#endif		// ETHERNET_WEBSERVER_STM32_HPP
