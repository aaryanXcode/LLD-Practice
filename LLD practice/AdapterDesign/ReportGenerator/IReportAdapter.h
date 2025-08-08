#pragma once
#include<bits/stdc++.h>
using namespace std;
class IReportAdapter{
    public:
        virtual string getJsonReport(string& data) = 0;
        virtual ~IReportAdapter() {}
};