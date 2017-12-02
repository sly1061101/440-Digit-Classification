//
//  digit_io.hpp
//  440-Digit-Classification
//
//  Created by Liuyi Shi on 12/1/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#ifndef digit_io_hpp
#define digit_io_hpp

#include <stdio.h>
#include <string>

namespace io {
    class digit_io{
    private:
        std::string filename_image;
        std::string filename_label;
        unsigned int total_num;
    public:
        unsigned int get_total_num(){
            return total_num;
        }
        
        digit_io(std::string filename_image_, std::string filename_label_);
        bool set_file(std::string filename_image_, std::string filename_label_);
        
        //get image and label of nth digit. n counts from 1
        bool get_data(unsigned nth, char image[28][28], char *label);
        
        //directly get feature and label value in the form of number
        bool get_feature(unsigned nth, int feature[784], int *label);
    };
}

#endif /* digit_io_hpp */
