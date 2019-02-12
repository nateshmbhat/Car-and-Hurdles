#include<iostream> 
#include<iomanip> 
#include "../basicStructures.h"
#include<GL/glut.h>

#pragma once

// The whole screen is divided into 2 columns for the car to be moved around.

void drawBackGround(){
    // Draws two columns on the screen which are of different colors
    glPushMatrix() ; 
        colorIndigo() ; 
        glutWireTeapot(200) ; 
    glPopMatrix() ; 

    glPushMatrix() ; 
        colorGrey(0.8) ; 
        glutWireCube(100) ; 
    glPopMatrix() ; 

    glFlush() ; 
}