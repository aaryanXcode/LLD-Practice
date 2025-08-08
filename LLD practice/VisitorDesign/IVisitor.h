#pragma once 

class TextFile;
class ImageFile;

class IVisitor{
    public:
        virtual void visit(TextFile* txt) = 0 ;
        virtual void visit(ImageFile* imag) = 0 ;
};