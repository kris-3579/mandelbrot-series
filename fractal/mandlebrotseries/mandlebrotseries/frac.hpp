//
//  frac.hpp
//  mandlebrotseries
//
//  Created by Kristof Reid on 11/7/19.
//  Copyright © 2019 Kristof Reid. All rights reserved.
//

#ifndef frac_hpp
#define frac_hpp

#include <stdio.h>

class mandle
{
public:
    long double map(long double value, long double in_max, long double out_max, long double out_min);
   
    void start();
    
    void draw_point(long double x, long double y, double n);
    
    int width;
    int height;
    long double x_max;
    long double x_min;
    long double y_max;
    long double y_min;
    int max_iterations;
    
    
};
#endif /* frac_hpp */
