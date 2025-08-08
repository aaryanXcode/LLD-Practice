#pragma once
#include "IVisitor.h"
#include "Document.h"
class TextFile:public Document{
    
    public:
        TextFile(){
            
        }
        void accept(IVisitor* visitor) override {
            visitor->visit(this);
        }

        ~TextFile(){
            
        }
};