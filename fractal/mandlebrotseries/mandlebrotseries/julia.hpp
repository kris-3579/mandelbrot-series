//
//  julia.hpp
//  mandlebrotseries
//
//  Created by Kristof Reid on 11/11/19.
//  Copyright © 2019 Kristof Reid. All rights reserved.
//

#ifndef julia_hpp
#define julia_hpp

#include <stdio.h>
#include <complex>

using namespace std;

class julia
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
#endif /* julia_hpp */
