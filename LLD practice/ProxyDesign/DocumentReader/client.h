#pragma once
#include<bits/stdc++.h>
using namespace std;
class Client{
    string clientName;
    bool isPremium;
    string password;
    public:
        Client(string cn, bool premium, string password){
            this->isPremium = premium;
            this->clientName = cn;
            this->password = password;
        }

        bool hasAccess(const string& inputPassword) const {
            return isPremium && inputPassword == password;
        }

        bool isSubscribed() const {
            return isPremium;
        }

        string getName() const {
            return clientName;
        }
};