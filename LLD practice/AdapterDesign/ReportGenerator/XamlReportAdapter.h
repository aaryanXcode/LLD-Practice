#pragma once
#include "IReportAdapter.h"
#include "XamlDataProvider.h"
#include<bits/stdc++.h>
using namespace std;
class XamlReportAdapter:public IReportAdapter{
    //an adapter should have a adaptee
    XamlDataProvider* provider;
    public:
        XamlReportAdapter(XamlDataProvider* dp){
            this->provider = dp;
        }
        string getJsonReport(string& data) override {
                // 1. Get XML from the adaptee
            string xml = provider->getXmlData(data);

            // 2. Naïvely parse out <name> and <id> values
            size_t startName = xml.find("<name>") + 6;
            size_t endName   = xml.find("</name>");
            string name      = xml.substr(startName, endName - startName);

            size_t startId = xml.find("<id>") + 4;
            size_t endId   = xml.find("</id>");
            string id      = xml.substr(startId, endId - startId);

            // 3. Build and return JSON
             return "{\"name\":\"" + name + "\", \"id\":" + id + "}";
        }

    

};