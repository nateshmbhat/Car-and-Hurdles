// DRIVER PROGRAM 
#include<iostream> 
#include<iomanip> 
#include "lib/components/line.h"
#include "lib/components/background.h"
#include "lib/components/smiley.h"
#include "lib/basicStructures.h"
#include<GL/glut.h>


using namespace std ; 

Point up = {0 , SCREEN_Y_HIGH , 0} ; 
Point eye = { 0 , 0 , 400  } ; 
Point ref = { 0 , 0,0 } ;
int holdKey = 0;


void display(){
    // Just drawing random stuff for a trail run before Setting the stage for fun :)
    glMatrixMode(GL_MODELVIEW) ; 
    glLoadIdentity() ; 
    gluLookAt(eye.x ,eye.y , eye.z , ref.x , ref.y , ref.z , up.x , up.y , up.z) ; 

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ; 
    glClearColor(1,1,1,0) ; 

    colorRed() ; 
    drawBackGround() ;     

    glutSwapBuffers() ; 
}


void reshapeHandler(int w, int h ){
    glMatrixMode(GL_PROJECTION) ; 
    glLoadIdentity() ; 

    // COordinate system from -100 to +100 on x and y axis 
    glOrtho(SCREEN_X_LOW , SCREEN_X_HIGH , SCREEN_Y_LOW , SCREEN_Y_HIGH , SCREEN_Z_LOW , SCREEN_Z_HIGH ) ; 

    glMatrixMode(GL_MODELVIEW) ; 
    glLoadIdentity() ; 

    gluLookAt(eye.x ,eye.y , eye.z , ref.x , ref.y , ref.z , up.x , up.y , up.z) ; 
}


void mouseHandler(int v , int u , int x , int y ){
    cout<< " v ,u,x , y = " << v << " " << u <<" " << x <<" " <<y<<endl; 

    if(v==MOUSE_UP){
       switch (holdKey)
       {
           case 0 : eye.z-=1 ; break; 
           case 1 : ref.z-=1 ; break; 
           case 2 : up.z-=1 ; break; 
       }
   }
   else if (v==MOUSE_DOWN){
       switch(holdKey){

        case 0 : eye.z+=1 ; break; 
        case 1 : ref.z+=1 ; break; 
        case 2 : up.z+=1 ; break; 

       }
   }

    glutPostRedisplay() ; 
}

void mouseMotionHandler(int v , int u ){
    cout<< " v ,u = " << v << " " << u << endl; 
}

void idleHandler(){
    glutPostRedisplay() ; 
}



void specialKeyHandler(int key , int b , int c){
   std::cout<<" key = " << key << " b = " << b << " c = " << c <<std::endl;
   if(key==ARROW_DOWN){
       switch (holdKey)
       {
           case 0 : eye.y-=5 ; break; 
           case 1 : ref.y-=5 ; break; 
           case 2 : up.y-=5 ; break; 
       }
   }
    if(key==ARROW_UP){
       switch (holdKey)
       {
           case 0 : eye.y+=5 ; break; 
           case 1 : ref.y+=5 ; break; 
           case 2 : up.y+=5 ; break; 
       }
   }
    if(key==ARROW_LEFT){
       switch (holdKey)
       {
           case 0 : eye.x-=5 ; break; 
           case 1 : ref.x-=5 ; break; 
           case 2 : up.x-=5 ; break; 
       }
   }

 if(key==ARROW_RIGHT){
       switch (holdKey)
       {
           case 0 : eye.x+=5 ; break; 
           case 1 : ref.x+=5 ; break; 
           case 2 : up.x+=5 ; break; 
       }
   }
}



void keyboardHandler(unsigned char c , int  a, int b){
    if(c=='v')(holdKey=(holdKey+1)%3) ;     

    glutPostRedisplay() ;
}


void initializeGlut(int argc , char ** argv) {
    // Initializes glut and open up a window
    glutInit(&argc, argv) ; 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB)  ;
    glutInitWindowSize(800 , 600) ; 
    glutCreateWindow("Car And Hurdles") ; 
    glutDisplayFunc(display) ; 
    glutReshapeFunc(reshapeHandler) ; 
    glutKeyboardFunc(keyboardHandler) ; 
    glutMouseFunc(mouseHandler) ; 
    glutMotionFunc(mouseMotionHandler) ; 
    glutIdleFunc(idleHandler) ; 
    glutSpecialFunc(specialKeyHandler) ; 
    glEnable(GL_DEPTH_TEST) ; 
}


int main(int argc , char ** argv){

    initializeGlut(argc , argv) ; 
    glutMainLoop() ; 
}