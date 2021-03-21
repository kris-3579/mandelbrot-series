//
//  main.cpp
//  mandlebrotseries
//
//  Created by Kristof Reid on 11/7/19.
//  Copyright © 2019 Kristof Reid. All rights reserved.
//
#include <GLUT/GLUT.h>
#include "frac.hpp"

#include "julia.hpp"

#include <iostream>
const int h = 700;
const int w = 700;
double fps = 0.1;
int choose = 1;
//julia set viewing window

long double x_left = -2.0;
long double x_right = 2.0;
long double y_top = 2.0;
long double y_bottom = -2.0;


//mandelbrot viewing window
/*
long double x_left = -2.0;
long double x_right = 1.0;
long double y_top = 1.5;
long double y_bottom = -1.5;
*/
mandle fractal;
julia jul;
void timer(int);
void init();
void reshape_callback(int, int);
void display_callback();

int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(w, h);
    glutCreateWindow("Fractal");
    glutDisplayFunc(display_callback);
    glutReshapeFunc(reshape_callback);
    glutTimerFunc(0, timer, 0);
    init();
    glutMainLoop();
    return 0;
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    
    fractal.width = w;
    fractal.height = h;
    fractal.x_min = x_left;
    fractal.x_max= x_right;
    fractal.y_max= y_top;
    fractal.y_min = y_bottom;
    fractal.max_iterations = 1000;
    
    
    jul.width = w;
    jul.height = h;
    jul.x_min = x_left;
    jul.x_max= x_right;
    jul.y_max= y_top;
    jul.y_min = y_bottom;
    jul.max_iterations = 1000;
    
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/fps, timer,  0);
    
    
    
}

void display_callback()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //fractal.start();
    /*
    jul.start();
    jul.x_min = jul.x_min / 2;
    jul.x_max = jul.x_max / 2;
    jul.y_max = jul.y_max / 2;
    jul.y_min = jul.y_min / 2;
    glOrtho(jul.x_min, jul.x_max, jul.y_max, jul.y_min, -1.0, 1.0);
    */
    jul.start();
    glutSwapBuffers();
}

void reshape_callback(int width, int height)
{
    
    glViewport(0, 0, (GLsizei) width, (GLsizei) height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    //glOrtho(x_left, x_right, y_top, y_bottom, -1.0, 1.0);
    glOrtho(jul.x_min, jul.x_max, jul.y_max, jul.y_min, -1.0, 1.0);
    
    glMatrixMode(GL_MODELVIEW);
}
