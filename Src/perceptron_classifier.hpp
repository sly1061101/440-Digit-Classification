//
//  perceptron_classifier.hpp
//  440-Digit-Classification
//
//  Created by Liuyi Shi on 12/1/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#ifndef perceptron_classifier_hpp
#define perceptron_classifier_hpp

#include <stdio.h>
#include "classifier.hpp"

namespace classifier{
    class perceptron_classifier : public classifier{
    private:
        float w[10][784];
        float b[10];
    public:
        perceptron_classifier(io::digit_io training_digit_):classifier(training_digit_){
            srand(clock());
            for(int i = 0; i<10; ++i){
                b[i] = rand()%10;
                for(int j = 0; j<784; ++j){
                    w[i][j] = rand()%10;
                }
            }
        }
        
        unsigned int classify(int feature[784]);
        //use one certain feature and given alhpa to train the classifier for one time
        bool train(int feature[784], int label, float alpha);
        
        //use all training digits to train the classfier (one epoch)
        //return the accuracy during this training epoch
        float train_all(float alpha);
    };
}

#endif /* perceptron_classifier_hpp */
