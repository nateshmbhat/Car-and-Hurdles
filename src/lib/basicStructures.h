//This file contains all the basic data structures (like custom structures) and custom macros that are going to be used in the project

#pragma once

// Screen boundaries
#define SCREEN_X_LOW -100
#define SCREEN_Y_LOW -100
#define SCREEN_X_HIGH 100
#define SCREEN_Y_HIGH 100
#define SCREEN_Z_LOW -500
#define SCREEN_Z_HIGH 1000

//Keyboard special keys constants
#define ARROW_UP 101
#define ARROW_DOWN 103
#define ARROW_LEFT 100
#define ARROW_RIGHT 102
#define MOUSE_UP 3   //using inside the MouseFunc handler
#define MOUSE_DOWN 4 //using inside the MouseFunc handler

//Various colors
#define colorRed() glColor3f(1, 0, 0);
#define colorGreen() glColor3f(0, 1, 0);
#define colorBlue() glColor3f(0, 0, 1);
#define colorYellow() glColor3f(1, 1, 0);
#define colorIndigo() glColor3f(0, 1, 1);
#define colorGrey(value) glColor3f(value, value, value); //value lies between 0 and 1

typedef struct
{
    float x, y, z;
} Point;



class CameraController
{
    CameraController(){}; //disable object creation here
    static Point up;
    static Point eye;
    static Point ref;
    static char upKey , downKey , leftKey , rightKey , modeKey ; 
    static int changeValue;
    static int current;

  public:
    const static int EYE = 0, TARGET = 1, UP = 2;
    static void changeMode(int);
    static void setNextMode();
    static void executeLookAt();
    static void incZ();
    static void incY();
    static void incX();
    static void decZ();
    static void decX();
    static void keyPressHandler(char) ; 
    static void decY();
    static void setChangeValue(const int &);
};

Point CameraController::up = {0, 1 , 0};
Point CameraController::eye = {0, 1, 400};
Point CameraController::ref = {0, 0, 0};
int CameraController::current = CameraController::EYE;
int CameraController::changeValue = 1;
char CameraController::upKey='w' ,  CameraController::downKey ='s' , CameraController::leftKey='a' , CameraController::rightKey='d' , CameraController::modeKey ='v' ; 

void CameraController::changeMode(int mode)
{ //current is the flag : EYE , TARGET , UP
    //sets the current vector that is active and enables that vector to change
    current = mode;
}

void CameraController::keyPressHandler(char c){
    if(c==modeKey) CameraController::setNextMode() ; 
    if(c==upKey) CameraController::incY()  ; 
    if(c==downKey) CameraController::decY()  ; 
    if(c==leftKey) CameraController::decX() ; 
    if(c==rightKey) CameraController::incX() ; 
}

void CameraController::setNextMode()
{
    current = (current + 1) % 3;
}

void CameraController::executeLookAt()
{
    gluLookAt(eye.x, eye.y, eye.z, ref.x, ref.y, ref.z, up.x, up.y, up.z);
}

void CameraController::setChangeValue(const int &val)
{
    // sets the amount by which coordinates change .
    changeValue = val;
}

// Increment or decrement the corresponding coordinates based on the current vector being controlled
void CameraController::incZ()
{
    glScalef(0.9, 0.9, 0.9);
}

void CameraController::decY()
{
    switch (current)
    {
    case 0:
        eye.y -= changeValue;
        break;
    case 1:
        ref.y -= changeValue;
        break;
    case 2:
        up.y -= changeValue;
        break;
    }
}

void CameraController::decX()
{
    switch (current)
    {
    case 0:
        eye.x -= changeValue;
        break;
    case 1:
        ref.x -= changeValue;
        break;
    case 2:
        up.x -= changeValue;
        break;
    }
}
void CameraController::incX()
{
    switch (current)
    {
    case 0:
        eye.x += changeValue;
        break;
    case 1:
        ref.x += changeValue;
        break;
    case 2:
        up.x += changeValue;
        break;
    }
}
void CameraController::incY()
{
    switch (current)
    {
    case 0:
        eye.y += changeValue;
        break;
    case 1:
        ref.y += changeValue;
        break;
    case 2:
        up.y += changeValue;
        break;
    }
}
void CameraController::decZ()
{
    glScalef(1.1, 1.1, 1.1);
}