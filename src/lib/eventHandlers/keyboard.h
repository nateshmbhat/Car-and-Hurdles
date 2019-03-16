#pragma once

#include "GL/glut.h" 
#include "../basicStructures.h"
#include "../components/tree.cpp"
#include "iostream"

void specialKeyHandler(int key , int b , int c){
    std::cout<<" key = " << key << " b = " << b << " c = " << c <<std::endl;
    // if(key==ARROW_UP) Game::moveAllTreesForward() ; 
    // if(key==ARROW_DOWN) Game::moveAllTreesBackward() ; 
    // if(key==ARROW_LEFT) Game::moveAllTreesLeft() ; 
    // if(key==ARROW_RIGHT) Game::moveAllTreesRight() ; 
}

void keyboardHandler(unsigned char c , int  a, int b){
    if(c=='v')CameraController::setNextMode() ; 
}