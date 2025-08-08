#pragma once
#include "ApplicationHandler.h"
#include<bits/stdc++.h>
using namespace std;
class TeamLeader: public ApplicationHandler{
    int daysCanApprove;
    public:
        TeamLeader(int days){
            this->daysCanApprove = days;
        }

        void approvalRequest(int days) override {
            if(days<=daysCanApprove){
                cout<<"leave period was below "<<daysCanApprove<<"days requested:"<<days<<"\n so it has approaved by team leader"<<endl;
            }
            else{
                cout<<"leave period was above "<<daysCanApprove<<"so it has transferred to manager"<<endl;
                next->approvalRequest(days);
            }
        }
};