#pragma once
#include "ApplicationHandler.h"
#include<bits/stdc++.h>
using namespace std;
class Hr: public ApplicationHandler{
    int daysCanApprove;
    public:
        Hr(int days){
            this->daysCanApprove = days;
        }

        void approvalRequest(int days) override {
            if(days<=daysCanApprove){
                cout<<"leave has been approved by hr"<<endl;
            }
            else{
                cout<<"leave above:"<<daysCanApprove<<" is not allowed"<<endl;
                next->approvalRequest(days);
            }
        }

};