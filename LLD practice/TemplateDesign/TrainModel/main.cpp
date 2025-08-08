#include<bits/stdc++.h>
#include "ModelTrainer.h"
#include "NeuralNetworkTrainer.h"
#include "DecisionTreeTrainer.h"
using namespace std;

int main(){
    ModelTrainer* neuralnetwork = new NeuralNetworkTrainer();
    neuralnetwork->templatepipeline("c:/downloads/neuralnetwork/");

    ModelTrainer* decisionTree = new DecisionTreeTrainer();
    decisionTree->templatepipeline("c:/downloads/decisiontree/");
}