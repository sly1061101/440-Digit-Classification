//
//  digit_io.cpp
//  440-Digit-Classification
//
//  Created by Liuyi Shi on 12/1/17.
//  Copyright © 2017 Liuyi Shi. All rights reserved.
//

#include "digit_io.hpp"

io::digit_io::digit_io(std::string filename_image_, std::string filename_label_){
    set_file(filename_image_, filename_label_);
}

bool io::digit_io::set_file(std::string filename_image_, std::string filename_label_){
    FILE *pf;
    char dummy[2];
    unsigned int num = 0;
    
    pf = fopen(filename_label_.c_str(), "r");
    
    if(pf == nullptr){
        printf("Digit file error!\n");
        return false;
    }
    
    while(fread(dummy, sizeof(char), 2, pf) == 2){
        if(dummy[1] == '\n')
            num++;
        else{
            printf("Digit file error!\n");
            fclose(pf);
            return false;
        }
    }
    
    fclose(pf);
    
    filename_image = filename_image_;
    filename_label = filename_label_;
    total_num = num;
    return true;
}

bool io::digit_io::get_data(unsigned nth, char image[28][28], char *label){
    if(nth <1 || nth > total_num)
        return false;
    
    FILE *pf_image;
    FILE *pf_label;
    
    unsigned int current_num = 1;
    
    pf_image = fopen(filename_image.c_str(), "r");
    pf_label = fopen(filename_label.c_str(), "r");
    
    char dummy[999];
    
//    while(current_num < nth){
//        if(fread(dummy, sizeof(char), 29*28, pf_image) != 29*28){
//            fclose(pf_image);
//            fclose(pf_label);
//            return false;
//        }
//        if(fread(dummy, sizeof(char), 2, pf_label) != 2 ){
//            fclose(pf_image);
//            fclose(pf_label);
//            return false;
//        }
//        current_num++;
//    }
    fseek(pf_label, 2*sizeof(char)*nth, 0);
    fseek(pf_image, 29*28*sizeof(char)*nth, 0);
    
    //read label
    if( fread(label, sizeof(char), 1, pf_label) != 1){
        fclose(pf_image);
        fclose(pf_label);
        return false;
    }
    //read image line by line
    for(int i = 0; i<28; i++){
        //read 28 pixels
        if(fread(image[i], sizeof(char), 28, pf_image) != 28){
            fclose(pf_image);
            fclose(pf_label);
            return false;
        }
        //read the '\n' into dummy, actually skipping it.
        if(fread(dummy, sizeof(char), 1, pf_image) != 1){
            fclose(pf_image);
            fclose(pf_label);
            return false;
        }
    }
    fclose(pf_image);
    fclose(pf_label);
    return true;
}

bool io::digit_io::get_feature(unsigned nth, int feature[784], int *label){
    char image[28][28];
    char label_char;
    if(get_data(nth, image, &label_char) == false)
        return false;
    *label = label_char - '0';
    for(int i = 0; i<28; ++i){
        for(int j = 0; j<28; ++j){
            feature[i*28+j] = (image[i][j] == ' ')?0:1;
        }
    }
    return true;
}
