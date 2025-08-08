#pragma once
#include "IHeader.h"
#include<string.h>
using namespace std;
class IBody{
    public:
        virtual IHeader& withBody(string body) = 0;
        virtual ~IBody(){}
};