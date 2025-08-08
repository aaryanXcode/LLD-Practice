#pragma once
#include "ModelTrainer.h"
class NeuralNetworkTrainer:public ModelTrainer{
    void filter() override{
        cout<<"filtering data"<<endl;
    }    
    void preprocessing()override{
        cout<<"preprocessing data"<<endl; 
    }
    void train() override{
        cout<<"training neural network tree"<<endl;
    }
    void evaluate() override {
        cout<<"evaluate result of neural network tree"<<endl;
    }
};