#pragma once
#include<bits/stdc++.h>
using namespace std;

class IColleague;
class IMediator{
    public:
        virtual void registerColleague(IColleague* c) = 0;
        virtual void send(const string& from,const string& msg)  = 0 ;
        virtual void sendPrivate( const string& from,const string& to,const string& msg) = 0;
        virtual ~ IMediator(){}

};