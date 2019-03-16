#include "GL/glut.h" 
#include "../basicStructures.h"
#include "iostream"

#pragma once

void reshapeHandler(int w, int h ){

    glViewport(0 , 0 , w, h) ; 

    glMatrixMode(GL_PROJECTION) ; 
    glLoadIdentity() ; 

    // glOrtho(SCREEN_X_LOW , SCREEN_X_HIGH , SCREEN_Y_LOW , SCREEN_Y_HIGH , 10 , SCREEN_Z_HIGH) ; 
    // glFrustum(SCREEN_X_LOW , SCREEN_X_HIGH , SCREEN_Y_LOW , SCREEN_Y_HIGH , 10 , SCREEN_Z_HIGH ) ; 
    gluPerspective(28 , w/h , 10 , 1000) ; 

    glMatrixMode(GL_MODELVIEW) ; 
    glLoadIdentity() ; 

    CameraController::executeLookAt() ; 
}
