#pragma once
#include<bits/stdc++.h>
#include"IReportAdapter.h"
#include "IReport.h"

//client
class Report:public IReport{
    IReportAdapter * reportAdapter;
    string rawData;
    public:
        Report(IReportAdapter* radp){
            this->reportAdapter = radp;
        }
        void printReport(string& rawData) override {
            cout << "Processed JSON: "
                << reportAdapter->getJsonReport(rawData)
                << endl;
        }
        // void getReport(IReportAdapter* report, string rawData) {
        //     cout << "Processed JSON: "
        //     << report->getJsonReport(rawData)
        //     << endl;
        // }
};