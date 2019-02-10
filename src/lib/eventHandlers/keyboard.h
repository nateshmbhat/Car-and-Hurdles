#include "GL/glut.h" 
#include "../basicStructures.h"
#include "iostream"

#pragma once

void specialKeyHandler(int key , int b , int c){
    std::cout<<" key = " << key << " b = " << b << " c = " << c <<std::endl;
    if(key==ARROW_UP){ CameraController::incY() ; }
    if(key==ARROW_DOWN){ CameraController::decY() ;}
    if(key==ARROW_RIGHT){ CameraController::incX() ; }
    if(key==ARROW_LEFT){ CameraController::decX() ; }

}

void keyboardHandler(unsigned char c , int  a, int b){
    if(c=='v')CameraController::setNextMode() ; 
}