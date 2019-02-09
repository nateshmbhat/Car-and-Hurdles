//This file contains all the basic data structures (like custom structures) and custom macros that are going to be used in the project
#ifndef _CAH_BASIC_STRUCTURES_ 
#define _CAH_BASIC_STRUCTURES_

// Screen boundaries 
#define SCREEN_X_LOW -100 
#define SCREEN_Y_LOW -100
#define SCREEN_X_HIGH 100
#define SCREEN_Y_HIGH 100 
#define SCREEN_Z_LOW -500
#define SCREEN_Z_HIGH 500


//Keyboard special keys constants 
#define ARROW_UP 101
#define ARROW_DOWN 103
#define ARROW_LEFT 100
#define ARROW_RIGHT 102
#define MOUSE_UP 3 //using inside the MouseFunc handler
#define MOUSE_DOWN 4 //using inside the MouseFunc handler


//Various colors 
#define colorRed() glColor3f(1 , 0 , 0) ; 
#define colorGreen() glColor3f(0 , 1 , 0) ; 
#define colorBlue() glColor3f(0 , 0, 1) ; 
#define colorYellow() glColor3f(1 , 1 , 0) ; 
#define colorIndigo() glColor3f(0 , 1, 1) ; 
#define colorGrey(value) glColor3f(value , value , value) ;  //value lies between 0 and 1


typedef struct{
    float x, y , z ;
} Point ; 

#endif