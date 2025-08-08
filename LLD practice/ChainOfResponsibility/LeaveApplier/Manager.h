#pragma once
#include "ApplicationHandler.h"
#include<bits/stdc++.h>
using namespace std;
class Manager: public ApplicationHandler{
    int daysCanApprove;

    public:
        Manager(int days){
            this->daysCanApprove = days;
        }

        void approvalRequest(int days) override {
            if(days<=daysCanApprove){
                cout<<"leave period was below "<<daysCanApprove<<"days requested:"<<days<<"\n so it has approaved by manager"<<endl;
            }
            else{
                cout<<"leave period was above "<<daysCanApprove<<"so it has transferred to hr"<<endl;
                next->approvalRequest(days);
            }
        }

};