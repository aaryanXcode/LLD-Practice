#pragma once
class ApplicationHandler{
    protected:
        ApplicationHandler* next;
    public:
        ApplicationHandler(){
            this->next = nullptr;
        }
        void setNextHandler(ApplicationHandler* h){
            this->next = h;
        }

        virtual void approvalRequest(int days) =0;
        virtual ~ApplicationHandler(){};
};