#pragma once
#include "HttpRequest.h"
class Optional {
public:
    virtual ~Optional() {}
    virtual Optional& withTimeout(int timeout) = 0;
    virtual HttpRequest build() = 0;
};
