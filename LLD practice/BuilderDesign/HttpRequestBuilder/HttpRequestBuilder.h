#pragma once
#include "HttpRequest.h"
class HttpRequestBuilder{
    HttpRequest h;

    public:
        HttpRequestBuilder& withUrl(string url){
            h.url = url;
            return *this;
        }

        HttpRequestBuilder& withQueryParams(const string& key, const string& value) {
            h.queryParams[key] = value;
            return *this;
        }

        HttpRequestBuilder& withHeader(const string& key, const string& value) {
            h.headers[key] = value;
            return *this;
        }

        HttpRequestBuilder& withMethod(string method){
            h.method = method;
            return *this;
        }

        
        HttpRequestBuilder& withBody(const string& body) {
            h.body = body;
            return *this;
        }
        
        HttpRequestBuilder& withTimeout(int timeout) {
            h.timeout = timeout;
            return *this;
        }

        HttpRequest build(){
            if(h.body.empty()){
                throw runtime_error("body should not be empty");
            }
            if(h.method.empty()){
                throw runtime_error("method should not be empty");
            }
            if(h.headers.empty()){
                throw runtime_error("headers should not be empty");
            }
            if(h.url.empty()){
                throw runtime_error("url should not be empty");
            }
            return h;
        }
};