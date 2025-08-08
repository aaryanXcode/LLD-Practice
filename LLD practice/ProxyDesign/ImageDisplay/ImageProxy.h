#pragma once
#include "ImageDisplay.h"

class ImageProxy:public IDisplay{
    string name;
    ImageDisplay* imageDisplay;
    public:
        ImageProxy(string name){
            this->name = name;
            this->imageDisplay = NULL;
        }

        void display() override{
            if(this->imageDisplay==NULL){
                this->imageDisplay = new ImageDisplay(name);
            }
            this->imageDisplay->display();
        }

        ~ImageProxy() {
            delete imageDisplay;
        }
};