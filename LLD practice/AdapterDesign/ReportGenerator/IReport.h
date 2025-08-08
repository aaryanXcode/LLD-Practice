#pragma once
class IReport{
    public:
        virtual void printReport(string& rawData) = 0;
        virtual ~IReport(){}
};