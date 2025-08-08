
#include "ImageProxy.h"
int main(){
    IDisplay* display = new ImageProxy("demo.jpg");
    display->display();  // first time: loads and displays
    display->display();  // second time: only displays
    delete display;      // clean up
    return 0;
}