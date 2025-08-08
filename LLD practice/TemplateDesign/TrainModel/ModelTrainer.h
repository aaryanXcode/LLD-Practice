#pragma once 
#include<bits/stdc++.h>
using namespace std;
class ModelTrainer{
    public:
        // The template method — final so subclasses can’t change the sequence
        void templatepipeline(const string& dataPath){
            load(dataPath);
            filter();
            preprocessing();
            train();
            evaluate();
            save(dataPath);
        }
    protected:
        void load(const string& dataPath){
            cout << "[Common] Loading dataset from " << dataPath << "\n";
        }
        virtual void filter() =0;
        virtual void preprocessing () =0;
        virtual void train() = 0;
        virtual void evaluate() = 0;
        void save(const string& dataPath){
            cout << "[Common] Loading dataset from " << dataPath << "\n";
        }

};