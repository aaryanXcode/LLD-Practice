#pragma once
#include "ModelTrainer.h"
class DecisionTreeTrainer:public ModelTrainer{
    void filter() override{
        cout<<"filtering data"<<endl;
    }    
    void preprocessing()override{
        cout<<"preprocessing data"<<endl; 
    }
    void train() override{
        cout<<"training decision tree"<<endl;
    }
    void evaluate() override {
        cout<<"evaluate result of decision tree"<<endl;
    }
};