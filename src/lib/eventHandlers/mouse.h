#include "GL/glut.h" 
#include "../basicStructures.h"
#include "iostream"

#pragma once

using namespace std ;

void mouseHandler(int v , int u , int x , int y ){
    cout<< " v ,u,x , y = " << v << " " << u <<" " << x <<" " <<y<<endl; 

    if(v==MOUSE_UP) CameraController::decZ() ; 
    else if (v==MOUSE_DOWN) CameraController::incZ() ; 
}

void mouseMotionHandler(int v , int u ){
    cout<< " v ,u = " << v << " " << u << endl; 
}

