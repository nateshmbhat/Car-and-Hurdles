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
        glTranslated(SCREEN_X_LOW, 0 , 0) ; 
        glutWireTeapot(100) ; 
    glPopMatrix() ; 

    glPushMatrix() ; 
        colorGrey(0.8) ; 
        glTranslated(SCREEN_X_HIGH, 0 , 0) ; 
        glutWireCube(100) ; 
    glPopMatrix() ; 

    glFlush() ; 
}