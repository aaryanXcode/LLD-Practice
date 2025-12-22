#pragma once
template<typename K>
class IEvictionPolicy{
    public:
        virtual void keyAccessed(K) = 0;
        virtual K evictKey() = 0;
    virtual ~IEvictionPolicy(){}
};

