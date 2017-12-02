//
//  perceptron_classifier.cpp
//  440-Digit-Classification
//
//  Created by Liuyi Shi on 12/1/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#include "perceptron_classifier.hpp"

unsigned int classifier::perceptron_classifier::classify(int feature[784]){
    float sum_product;
    float max = -9999;
    unsigned int result;
    
    for(int i = 0; i<10; ++i){
        sum_product = 0;
        for(int j = 0; j<784; ++j){
            sum_product += w[i][j]*feature[j] + b[i];
        }
        if(sum_product >= max){
            max = sum_product;
            result = i;
        }
    }
    return result;
}

bool classifier::perceptron_classifier::train(int feature[784], int label, float alpha){
    int label_classified;
    label_classified = classify(feature);
    if(label_classified == label)
        return true;
    for(int i = 0; i<784; ++i){
        w[label][i] = w[label][i] + alpha*feature[i];
        w[label_classified][i] = w[label_classified][i] - alpha*feature[i];
    }
    b[label] += alpha;
    b[label_classified] -= alpha;
    return false;
}

float classifier::perceptron_classifier::train_all(float alpha){
    int feature[784];
    int label;
    int num_corrected = 0;
    for(int i = 0; i<training_digit.get_total_num(); ++i){
        training_digit.get_feature(i+1, feature, &label);
        if( train(feature, label, alpha) == true)
            num_corrected++;
    }
    return (float)num_corrected/training_digit.get_total_num();
}
