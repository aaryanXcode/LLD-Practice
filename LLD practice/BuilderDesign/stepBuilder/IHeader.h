#pragma once
#include "Optional.h"
#include<bits/stdc++.h>
class IHeader{
    public:
        virtual Optional& withHeader(string key, string value) = 0;
};