#include "GL/glut.h" 
#include "../basicStructures.h"
#include "iostream"

#pragma once

void reshapeHandler(int w, int h ){

    glViewport(0 , 0 , w, h) ; 
    Game::setWindowWidth(w) ; 
    Game::setWindowHeight(h) ; 

    glMatrixMode(GL_PROJECTION) ; 
    glLoadIdentity() ; 

    gluPerspective(28 , w/h , 10 , 10000) ; 

    glMatrixMode(GL_MODELVIEW) ; 
    glLoadIdentity() ; 

    CameraController::executeLookAt() ; 
}
