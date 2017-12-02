//
//  main.cpp
//  440-Digit-Classification
//
//  Created by Liuyi Shi on 11/28/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#include <stdio.h>
#include "digit_io.hpp"
#include "perceptron_classifier.hpp"

int main(){
    io::digit_io training_file("trainingimages","traininglabels");
    io::digit_io test_file("testimages","testlabels");

    classifier::perceptron_classifier c(training_file);
    
    int feature[784];
    int label;
    
    float alpha;
    int num_epoch = 20;
    for(int t = 0; t<num_epoch; ++t){
        alpha = num_epoch/(float)(num_epoch+t);
        printf("%f\n",c.train_all(alpha));
    }
    
    int num_corrected = 0;
    for(int i = 0; i<test_file.get_total_num(); ++i){
        test_file.get_feature(i+1, feature, &label);
        if( c.classify(feature) == label)
            num_corrected++;
    }
    printf("testing accuracy:%f\n",(float)num_corrected/test_file.get_total_num());
    
    return 0;
}
