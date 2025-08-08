#pragma once
class Pizza {
    public:
        virtual void getPrice() = 0;
        virtual void prepare() = 0;
        virtual ~Pizza(){}
};