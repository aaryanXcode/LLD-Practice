#pragma once
#include<bits/stdc++.h>
using namespace std;
class HttpRequest {
    private:
        string url;
        string method;
        map<string, string> headers;
        map<string,string> queryParams;
        string body;
        int timeout; // in seconds

        // Private constructor - can only be accessed by the Builder
        HttpRequest() { }
    public:
        friend class HttpRequestBuilder;
        void execute() {
            cout << "Executing " << method << " request to " << url << endl;
            
            if (!queryParams.empty()) {
                cout << "Query Parameters:" << endl;
                for (const auto& param : queryParams) {
                    cout << "  " << param.first << "=" << param.second << endl;
                }
            }

            cout << "Headers:" << endl;
            for (const auto& header : headers) {
                cout << "  " << header.first << ": " << header.second << endl;
            }
            
            if (!body.empty()) {
                cout << "Body: " << body << endl;
            }
            
            cout << "Timeout: " << timeout << " seconds" << endl;
            cout << "Request executed successfully!" << endl;
        }
};