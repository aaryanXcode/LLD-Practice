#include "Report.h"
#include "XamlReportAdapter.h"
#include "XamlDataProvider.h"
using namespace std;

int main(){
    string rawData = "Aryan:101";

    // Create the adaptee
    XamlDataProvider* provider = new XamlDataProvider();

    // Create the adapter and pass the adaptee
    IReportAdapter* adapter = new XamlReportAdapter(provider);

     // Create the client and call getReport
    IReport* report = new Report(adapter);
    report->printReport(rawData);

    // Clean up
    delete provider;
    delete adapter;

    return 0;
}