/****************************************************************************************************************************
   Ethernet_HttpClient.h - Dead simple HTTP WebClient.
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

// Class to simplify HTTP fetching on Arduino
// (c) Copyright MCQN Ltd. 2010-2012
// Released under Apache License, version 2.0

#pragma once

#include <Arduino.h>
#include <IPAddress.h>
#include "Client.h"

#include "detail/Debug_STM32.h"

static const int HTTP_SUCCESS = 0;

// The end of the headers has been reached.  This consumes the '\n'
// Could not connect to the server
static const int HTTP_ERROR_CONNECTION_FAILED = -1;

// This call was made when the EthernetHttpClient class wasn't expecting it
// to be called.  Usually indicates your code is using the class
// incorrectly
static const int HTTP_ERROR_API = -2;

// Spent too long waiting for a reply
static const int HTTP_ERROR_TIMED_OUT = -3;

// The response from the server is invalid, is it definitely an HTTP
// server?
static const int HTTP_ERROR_INVALID_RESPONSE = -4;

// Define some of the common methods and headers here
// That lets other code reuse them without having to declare another copy
// of them, so saves code space and RAM
#define HTTP_METHOD_GET               "GET"
#define HTTP_METHOD_POST              "POST"
#define HTTP_METHOD_PUT               "PUT"
#define HTTP_METHOD_PATCH             "PATCH"
#define HTTP_METHOD_DELETE            "DELETE"
#define HTTP_HEADER_CONTENT_LENGTH    "Content-Length"
#define HTTP_HEADER_CONTENT_TYPE      "Content-Type"
#define HTTP_HEADER_CONNECTION        "Connection"
#define HTTP_HEADER_TRANSFER_ENCODING "Transfer-Encoding"
#define HTTP_HEADER_USER_AGENT        "User-Agent"
#define HTTP_HEADER_VALUE_CHUNKED     "chunked"

// Number of milliseconds that we wait each time there isn't any data
// available to be read (during status code and header processing)
#define kHttpWaitForDataDelay     1000L

// Number of milliseconds that we'll wait in total without receiveing any
// data before returning HTTP_ERROR_TIMED_OUT (during status code and header
// processing)
#define kHttpResponseTimeout      30000L

class EthernetHttpClient : public Client
{
  public:
    static const int kNoContentLengthHeader = -1;
    static const int kHttpPort = 80;
    static const char* kUserAgent;

    // FIXME Write longer API request, using port and user-agent, example
    // FIXME Update tempToPachube example to calculate Content-Length correctly

    EthernetHttpClient(Client& aClient, const char* aServerName, uint16_t aServerPort = kHttpPort);
    EthernetHttpClient(Client& aClient, const String& aServerName, uint16_t aServerPort = kHttpPort);
    EthernetHttpClient(Client& aClient, const IPAddress& aServerAddress, uint16_t aServerPort = kHttpPort);

    /** Start a more complex request.
        Use this when you need to send additional headers in the request,
        but you will also need to call endRequest() when you are finished.
    */
    void beginRequest();

    /** End a more complex request.
        Use this when you need to have sent additional headers in the request,
        but you will also need to call beginRequest() at the start.
    */
    void endRequest();

    /** Start the body of a more complex request.
        Use this when you need to send the body after additional headers
        in the request, but can optionally call endRequest() when
        you are finished.
    */
    void beginBody();

    /** Connect to the server and start to send a GET request.
      @param aURLPath     Url to request
      @return 0 if successful, else error
    */
    int get(const char* aURLPath);
    int get(const String& aURLPath);

    /** Connect to the server and start to send a POST request.
      @param aURLPath     Url to request
      @return 0 if successful, else error
    */
    int post(const char* aURLPath);
    int post(const String& aURLPath);

    /** Connect to the server and send a POST request
        with body and content type
      @param aURLPath     Url to request
      @param aContentType Content type of request body
      @param aBody        Body of the request
      @return 0 if successful, else error
    */
    int post(const char* aURLPath, const char* aContentType, const char* aBody);
    int post(const String& aURLPath, const String& aContentType, const String& aBody);
    int post(const char* aURLPath, const char* aContentType, int aContentLength, const byte aBody[]);

    /** Connect to the server and start to send a PUT request.
      @param aURLPath     Url to request
      @return 0 if successful, else error
    */
    int put(const char* aURLPath);
    int put(const String& aURLPath);

    /** Connect to the server and send a PUT request
        with body and content type
      @param aURLPath     Url to request
      @param aContentType Content type of request body
      @param aBody        Body of the request
      @return 0 if successful, else error
    */
    int put(const char* aURLPath, const char* aContentType, const char* aBody);
    int put(const String& aURLPath, const String& aContentType, const String& aBody);
    int put(const char* aURLPath, const char* aContentType, int aContentLength, const byte aBody[]);

    /** Connect to the server and start to send a PATCH request.
      @param aURLPath     Url to request
      @return 0 if successful, else error
    */
    int patch(const char* aURLPath);
    int patch(const String& aURLPath);

    /** Connect to the server and send a PATCH request
        with body and content type
      @param aURLPath     Url to request
      @param aContentType Content type of request body
      @param aBody        Body of the request
      @return 0 if successful, else error
    */
    int patch(const char* aURLPath, const char* aContentType, const char* aBody);
    int patch(const String& aURLPath, const String& aContentType, const String& aBody);
    int patch(const char* aURLPath, const char* aContentType, int aContentLength, const byte aBody[]);

    /** Connect to the server and start to send a DELETE request.
      @param aURLPath     Url to request
      @return 0 if successful, else error
    */
    int del(const char* aURLPath);
    int del(const String& aURLPath);

    /** Connect to the server and send a DELETE request
        with body and content type
      @param aURLPath     Url to request
      @param aContentType Content type of request body
      @param aBody        Body of the request
      @return 0 if successful, else error
    */
    int del(const char* aURLPath, const char* aContentType, const char* aBody);
    int del(const String& aURLPath, const String& aContentType, const String& aBody);
    int del(const char* aURLPath, const char* aContentType, int aContentLength, const byte aBody[]);

    /** Connect to the server and start to send the request.
        If a body is provided, the entire request (including headers and body) will be sent
      @param aURLPath        Url to request
      @param aHttpMethod     Type of HTTP request to make, e.g. "GET", "POST", etc.
      @param aContentType    Content type of request body (optional)
      @param aContentLength  Length of request body (optional)
      @param aBody           Body of request (optional)
      @return 0 if successful, else error
    */
    int startRequest(const char* aURLPath,
                     const char* aHttpMethod,
                     const char* aContentType = NULL,
                     int aContentLength = -1,
                     const byte aBody[] = NULL);

    /** Send an additional header line.  This can only be called in between the
      calls to beginRequest and endRequest.
      @param aHeader Header line to send, in its entirety (but without the
                     trailing CRLF.  E.g. "Authorization: Basic YQDDCAIGES"
    */
    void sendHeader(const char* aHeader);

    void sendHeader(const String& aHeader)
    {
      sendHeader(aHeader.c_str());
    }

    /** Send an additional header line.  This is an alternate form of
      sendHeader() which takes the header name and content as separate strings.
      The call will add the ": " to separate the header, so for example, to
      send a XXXXXX header call sendHeader("XXXXX", "Something")
      @param aHeaderName Type of header being sent
      @param aHeaderValue Value for that header
    */
    void sendHeader(const char* aHeaderName, const char* aHeaderValue);

    void sendHeader(const String& aHeaderName, const String& aHeaderValue)
    {
      sendHeader(aHeaderName.c_str(), aHeaderValue.c_str());
    }

    /** Send an additional header line.  This is an alternate form of
      sendHeader() which takes the header name and content separately but where
      the value is provided as an integer.
      The call will add the ": " to separate the header, so for example, to
      send a XXXXXX header call sendHeader("XXXXX", 123)
      @param aHeaderName Type of header being sent
      @param aHeaderValue Value for that header
    */
    void sendHeader(const char* aHeaderName, const int aHeaderValue);

    void sendHeader(const String& aHeaderName, const int aHeaderValue)
    {
      sendHeader(aHeaderName.c_str(), aHeaderValue);
    }

    /** Send a basic authentication header.  This will encode the given username
      and password, and send them in suitable header line for doing Basic
      Authentication.
      @param aUser Username for the authorization
      @param aPassword Password for the user aUser
    */
    void sendBasicAuth(const char* aUser, const char* aPassword);

    void sendBasicAuth(const String& aUser, const String& aPassword)
    {
      sendBasicAuth(aUser.c_str(), aPassword.c_str());
    }

    /** Get the HTTP status code contained in the response.
      For example, 200 for successful request, 404 for file not found, etc.
    */
    int responseStatusCode();

    /** Check if a header is available to be read.
      Use readHeaderName() to read header name, and readHeaderValue() to
      read the header value
      MUST be called after responseStatusCode() and before contentLength()
    */
    bool headerAvailable();

    /** Read the name of the current response header.
      Returns empty string if a header is not available.
    */
    String readHeaderName();

    /** Read the vallue of the current response header.
      Returns empty string if a header is not available.
    */
    String readHeaderValue();

    /** Read the next character of the response headers.
      This functions in the same way as read() but to be used when reading
      through the headers.  Check whether or not the end of the headers has
      been reached by calling endOfHeadersReached(), although after that point
      this will still return data as read() would, but slightly less efficiently
      MUST be called after responseStatusCode() and before contentLength()
      @return The next character of the response headers
    */
    int readHeader();

    /** Skip any response headers to get to the body.
      Use this if you don't want to do any special processing of the headers
      returned in the response.  You can also use it after you've found all of
      the headers you're interested in, and just want to get on with processing
      the body.
      MUST be called after responseStatusCode()
      @return HTTP_SUCCESS if successful, else an error code
    */
    int skipResponseHeaders();

    /** Test whether all of the response headers have been consumed.
      @return true if we are now processing the response body, else false
    */
    bool endOfHeadersReached();

    /** Test whether the end of the body has been reached.
      Only works if the Content-Length header was returned by the server
      @return true if we are now at the end of the body, else false
    */
    bool endOfBodyReached();
    
    virtual bool endOfStream() 
    {
      return endOfBodyReached();
    };
    
    virtual bool completed() 
    {
      return endOfBodyReached();
    };

    /** Return the length of the body.
      Also skips response headers if they have not been read already
      MUST be called after responseStatusCode()
      @return Length of the body, in bytes, or kNoContentLengthHeader if no
      Content-Length header was returned by the server
    */
    int contentLength();

    /** Returns if the response body is chunked
      @return true if response body is chunked, false otherwise
    */
    int isResponseChunked() 
    {
      return iIsChunked;
    }

    /** Return the response body as a String
      Also skips response headers if they have not been read already
      MUST be called after responseStatusCode()
      @return response body of request as a String
    */
    String responseBody();

    /** Enables connection keep-alive mode
    */
    void connectionKeepAlive();

    /** Disables sending the default request headers (Host and User Agent)
    */
    void noDefaultRequestHeaders();

    // Inherited from Print
    // Note: 1st call to these indicates the user is sending the body, so if need
    // Note: be we should finish the header first
    virtual size_t write(uint8_t aByte) 
    {
      if (iState < eRequestSent) 
      {
        finishHeaders();
      };
      
      return iClient-> write(aByte);
    };
    
    virtual size_t write(const uint8_t *aBuffer, size_t aSize) 
    {
      if (iState < eRequestSent) 
      {
        finishHeaders();
      };
      return iClient->write(aBuffer, aSize);
    };
    
    // Inherited from Stream
    virtual int available();
    
    /** Read the next byte from the server.
      @return Byte read or -1 if there are no bytes available.
    */
    virtual int read();
    virtual int read(uint8_t *buf, size_t size);
    
    virtual int peek() 
    {
      return iClient->peek();
    };
    
    virtual void flush() 
    {
      iClient->flush();
    };

    // Inherited from Client
    virtual int connect(IPAddress ip, uint16_t port) 
    {
      return iClient->connect(ip, port);
    };
    
    virtual int connect(const char *host, uint16_t port) 
    {
      return iClient->connect(host, port);
    };
    
    virtual void stop();
    
    virtual uint8_t connected() 
    {
      return iClient->connected();
    };
    
    virtual operator bool() 
    {
      return bool(iClient);
    };
    
    virtual uint32_t httpResponseTimeout() 
    {
      return iHttpResponseTimeout;
    };
    
    virtual void setHttpResponseTimeout(uint32_t timeout) 
    {
      iHttpResponseTimeout = timeout;
    };
    
  protected:
    /** Reset internal state data back to the "just initialised" state
    */
    void resetState();

    /** Send the first part of the request and the initial headers.
      @param aURLPath  Url to request
      @param aHttpMethod  Type of HTTP request to make, e.g. "GET", "POST", etc.
      @return 0 if successful, else error
    */
    int sendInitialHeaders(const char* aURLPath,
                           const char* aHttpMethod);

    /* Let the server know that we've reached the end of the headers
    */
    void finishHeaders();

    /** Reading any pending data from the client (used in connection keep alive mode)
    */
    void flushClientRx();
   
    static const char* kContentLengthPrefix;
    static const char* kTransferEncodingChunked;
    
    typedef enum
    {
      eIdle,
      eRequestStarted,
      eRequestSent,
      eReadingStatusCode,
      eStatusCodeRead,
      eReadingContentLength,
      eSkipToEndOfHeader,
      eLineStartingCRFound,
      eReadingBody,
      eReadingChunkLength,
      eReadingBodyChunk
    } tHttpState;

    // Client we're using
    Client* iClient;
    // Server we are connecting to
    const char* iServerName;
    IPAddress iServerAddress;
    // Port of server we are connecting to
    uint16_t iServerPort;
    // Current state of the finite-state-machine
    tHttpState iState;
    // Stores the status code for the response, once known
    int iStatusCode;
    // Stores the value of the Content-Length header, if present
    int iContentLength;
    // How many bytes of the response body have been read by the user
    int iBodyLengthConsumed;
    // How far through a Content-Length header prefix we are
    const char* iContentLengthPtr;
    // How far through a Transfer-Encoding chunked header we are
    const char* iTransferEncodingChunkedPtr;
    // Stores if the response body is chunked
    bool iIsChunked;
    // Stores the value of the current chunk length, if present
    int iChunkLength;
    uint32_t iHttpResponseTimeout;
    bool iConnectionClose;
    bool iSendDefaultRequestHeaders;
    String iHeaderLine;
};
