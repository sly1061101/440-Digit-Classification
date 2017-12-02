//
//  nearest_neighbor_classifier.cpp
//  440-Digit-Classification
//
//  Created by Liuyi Shi on 12/1/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#include "nearest_neighbor_classifier.hpp"
#include <queue>

float classifier::nearest_neighbor_classifier::distance(int feature1[784], int feature2[784]){
    float distance = 0;
    for(int i = 0; i<784; ++i){
        if(feature1[i] != feature2[i])
            distance++;
    }
    return distance;
}

class CompareDist
{
public:
    bool operator()(std::pair<unsigned int,float> lhs,std::pair<unsigned int,float> rhs) {
        return lhs.second>rhs.second;
    }
};

unsigned int classifier::nearest_neighbor_classifier::classify(int feature[784]){
    unsigned int result = 0;
    std::pair<unsigned int, float> digit_dist;
    std::priority_queue<std::pair<unsigned int, float>, std::vector<std::pair<unsigned int, float>>, CompareDist> p_queue;
    int feature_t[784];
    int label;
    for(int i = 0; i<training_digit.get_total_num(); ++i){
        training_digit.get_feature(i+1, feature_t, &label);
        digit_dist.first = label;
        digit_dist.second = distance(feature_t, feature);
        p_queue.push(digit_dist);
    }
    unsigned int digit_count[10] = {0};
    for(int i = 0; i<K; ++i){
        digit_dist = p_queue.top();
        p_queue.pop();
        digit_count[digit_dist.first]++;
    }
    unsigned int max = 0;
    for(int i = 0; i<10; ++i){
        if(digit_count[i] >= max){
            max = digit_count[i];
            result = i;
        }
    }
    return result;
}
