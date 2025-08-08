#pragma once 
class IDocument{
    public:
        virtual void read() = 0;
        virtual ~IDocument() {}
};