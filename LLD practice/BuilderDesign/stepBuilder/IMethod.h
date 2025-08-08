#pragma once
#include "IBody.h"
#include<bits/stdc++.h>
using namespace std;
class IMethod{
    public:
        virtual IBody& withMethod(string method) = 0;
};