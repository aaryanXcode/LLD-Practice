#include "TextFile.h"
#include "ImageFile.h"
#include "SizeCalCulatorVisitor.h"
#include "CompressionVisitor.h"

int main(){
    IVisitor* size = new SizeCalCulatorVisitor();
    IVisitor* compression = new CompressionVisitor();
    Document* text = new TextFile();
    text->accept(size);
    text->accept(compression);

    Document* image = new ImageFile();
    image->accept(size);
    image->accept(compression);


    
}