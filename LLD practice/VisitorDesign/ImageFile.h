#pragma once
#include "IVisitor.h"
#include "Document.h"
class ImageFile:public Document{
    
    public:
        ImageFile( ){
        }
        void accept(IVisitor* visitor) override {
            visitor->visit(this);
        }

        ~ImageFile(){}
};