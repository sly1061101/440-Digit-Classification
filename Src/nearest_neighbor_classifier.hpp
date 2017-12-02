//
//  nearest_neighbor_classifier.hpp
//  440-Digit-Classification
//
//  Created by Liuyi Shi on 12/1/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#ifndef nearest_neighbor_classifier_hpp
#define nearest_neighbor_classifier_hpp

#include <stdio.h>
#include "classifier.hpp"

namespace classifier{
    class nearest_neighbor_classifier : public classifier{
    private:
        unsigned int K;
    public:
        nearest_neighbor_classifier(io::digit_io training_digit_, unsigned K_):classifier(training_digit_),K(K_){}
        unsigned int classify(int feature[784]);
        float distance(int feature1[784], int feature2[784]);
    };
}
#endif /* nearest_neighbor_classifier_hpp */
