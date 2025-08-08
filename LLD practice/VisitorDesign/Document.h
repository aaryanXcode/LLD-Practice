#pragma once

class IVisitor;
class Document{
    public:
        virtual void accept(IVisitor* visitor) = 0 ;
        virtual ~Document(){}
};