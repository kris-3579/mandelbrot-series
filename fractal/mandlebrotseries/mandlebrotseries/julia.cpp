//
//  julia.cpp
//  mandlebrotseries
//
//  Created by Kristof Reid on 11/11/19.
//  Copyright © 2019 Kristof Reid. All rights reserved.
//

#include "julia.hpp"
#include <GLUT/GLUT.h>
#include <complex>

using namespace std;

long double julia::map(long double value, long double size, long double out_min, long double out_max)
{
    return out_min + (value /size) * (out_max - out_min);
}

void julia::draw_point(long double x, long double y, double n)
{
    int r;
    int g;
    int b;
    
    if (n < 250) {
        r = 25 * (250 - n + 1);
        g = 250 - 2* n + 1;
        b = 250 - n/2 + 1;
    } else if (n < 500) {
        
        r = 250 - 2* n + 1;
        g = 250 - n /2 + 1;
        b = 25 * (500 - n + 1);
        
    } else if (n < 750) {
        
        r = 250 - n/2 + 1;
        g = 25 * (750- n + 1);
        b = 250 - 2* n + 1;
        
    } else { // range is 64 - 127
        r = 255;
        g = 255;//(n - 750) * 4;
        b = 255;
    }
    glPointSize(0.5);
    glColor3ub(r, g, b);
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    
}

void julia::start()
{
    for (int x = 0; x < width; x += 1)
    {
        for (int y = 0; y < height; y+= 1)
        {
            
            long double a = map(x, width, x_min, x_max);
            long double b = map(y, height, y_min, y_max);
            
            complex<double> z (a, b);
            
            
            int n = 0;
            //complex<double> c (-0.4,-0.59);
            //complex<double> c (-0.54,-0.54);
            //complex<double> c (0.355,0.355);
            //complex<double> c (0,0.8);
            complex<double> c (0.8,0.6);
            
            
            
            while (abs(z) <= 2 && n < max_iterations)
            {
                z = z* z * z * z * z + c;
                n++;
                
                
            }
            
            draw_point(a,b,n);
            
            
        }
    }
    
}

