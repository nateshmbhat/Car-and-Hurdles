#include "GL/glut.h" 
#include "../basicStructures.h"
#include "iostream"

#pragma once

void reshapeHandler(int w, int h ){

    glViewport(0 , 0 , w, h) ; 

    glMatrixMode(GL_PROJECTION) ; 
    glLoadIdentity() ; 
    gluPerspective(120 ,(GLfloat)w/(GLfloat)h , 10 , 700 ) ; 

    glMatrixMode(GL_MODELVIEW) ; 
    glLoadIdentity() ; 

    // COordinate system from -100 to +100 on x and y axis 
    // glOrtho(SCREEN_X_LOW , SCREEN_X_HIGH , SCREEN_Y_LOW , SCREEN_Y_HIGH , SCREEN_Z_LOW , SCREEN_Z_HIGH ) ; 

    CameraController::executeLookAt() ; 
}
