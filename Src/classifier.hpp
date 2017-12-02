//
//  classifier.hpp
//  440-Digit-Classification
//
//  Created by Liuyi Shi on 12/1/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#ifndef classifier_hpp
#define classifier_hpp

#include <stdio.h>
#include "digit_io.hpp"

namespace classifier{
    class classifier{
    protected:
        io::digit_io training_digit;
    public:
        classifier(io::digit_io training_digit_):training_digit(training_digit_){}
        virtual unsigned int classify(int feature[784]) = 0;
    };
}

#endif /* classifier_hpp */
