#pragma once 
#include "IMethod.h"
class IUrl{
    public:
        virtual IMethod& withUrl(string url) =0 ;
        virtual ~IUrl(){}
};