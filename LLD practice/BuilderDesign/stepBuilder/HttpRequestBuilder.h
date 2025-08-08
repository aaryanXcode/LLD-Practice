#pragma once
#include "IUrl.h"
#include "IMethod.h"
#include "IHeader.h"
#include "IBody.h"
#include "Optional.h"
class HttpRequestBuilder:public IUrl, public IMethod, public IHeader, public IBody, public Optional {

    HttpRequest req;
    public:
        IMethod& withUrl(string url) override{
            req.url = url;
            return *this;
        }

        IBody& withMethod(string method) override {
            req.method = method;
            return *this;
        }

        IHeader& withBody(string body) override {
            req.body = body;
            return *this;
        }

        Optional& withHeader(string key, string value) override {
            req.headers[key] = value;
            return *this;
        }

        Optional& withTimeout(int timeout) override {
            req.timeout = timeout;
            return *this;
        }

        HttpRequest build() override {
            if (req.url.empty()) {
                throw runtime_error("URL cannot be empty");
            }
            return req;
        }
        
        // Static method to start the building process
        static IUrl& getBuilder() {
            return *(new HttpRequestBuilder());
        }
};