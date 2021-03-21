//
//  frac.cpp
//  mandlebrotseries
//
//  Created by Kristof Reid on 11/7/19.
//  /Users/kristofreid/Desktop/opengl/fractal/mandlebrotseriesCopyright © 2019 Kristof Reid. All rights reserved.
//

#include "frac.hpp"
#include <GLUT/GLUT.h>
#include <complex>

using namespace std;



long double mandle::map(long double value, long double size, long double out_min, long double out_max)
{
    return out_min + (value /size) * (out_max - out_min);
}

void mandle::draw_point(long double x, long double y, double n)
{
    int r;
    int g;
    int b;
    
    if (n < 16) {
        r = 16 * (16 - n);
        g = 0;
        b = 16 * n - 1;
    } else if (n < 32) {
        r = 0;
        g = 16 * (n - 16);
        b = 16 * (32 - n) - 1;
    } else if (n < 64) {
        r = 8 * (n - 32);
        g = 8 * (64 - n) - 1;
        b = 0;
    } else { // range is 64 - 127
        r = 255 - (n - 64) * 4;
        g = 0;
        b = 0;
    }
    glPointSize(0.5);
    glColor3ub(r, g, b);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    
}

void mandle::start()
{
        for (int x = 0; x < width; x += 1)
        {
            for (int y = 0; y < height; y+= 1)
            {
                
                long double a = map(x, width, x_min, x_max);
                long double b = map(y, height, y_min, y_max);
                
                complex<double> tmp_cmp(a, b);
                
                
                int n = 0;
                complex<double> z = 0;
                
                
                while (abs(z) <= 2 && n < max_iterations)
                {
                    z = z * z + tmp_cmp;
                    n++;
                    
                    
                }
                
                draw_point(a,b,n);
                
                
            }
        }
    
}


