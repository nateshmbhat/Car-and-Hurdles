#pragma once

#include "GL/glut.h" 
#include "../basicStructures.h"
#include "../components/tree.cpp"
#include "../../game.h"
#include "iostream"

void specialKeyHandler(int key , int b , int c){
    std::cout<<" key = " << key << " b = " << b << " c = " << c <<std::endl;
    Game::handleKeyPress(key) ; 
}

void keyboardHandler(unsigned char c , int  a, int b){
    switch(c){
        case 'v' : CameraController::setNextMode() ; break;
        case 'w' : CameraController::incY() ; break;
        case 's' : CameraController::decY() ; break;
        case 'a' : CameraController::decX() ; break;
        case 'd' : CameraController::incX() ; break; 
    }
    glutReshapeWindow(Game::getWindowWidth() , Game::getWindowHeight()) ; 
}