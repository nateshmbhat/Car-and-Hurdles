// DRIVER PROGRAM 
#include<iostream> 
#include<iomanip> 
#include "lib/components/line.h"
#include "lib/components/smiley.h"
#include "lib/basicStructures.h"
#include<GL/glut.h>


void display(){
    // Just drawing random stuff for a trail run before Setting the stage for fun :)
    Point p = {0 , 0.5 , 0 } ; 
    Point q = {0.5 , 0.9 , 0 } ; 

    glClear(GL_COLOR_BUFFER_BIT ) ; 
    glClearColor(1,1,1, 0.5) ; 

    glColor3f(1 , 0 , 0 ) ; 

    drawSmiley() ; 
    drawLine(p , q) ; 
}



void initializeGlut(int argc , char ** argv) {
    // Initializes glut and open up a window
    glutInit(&argc, argv) ; 
    glutInitDisplayMode(GLUT_SINGLE )  ;
    glutInitWindowSize(800 , 600) ; 
    glutCreateWindow("Car And Hurdles") ; 
    glutDisplayFunc(display) ; 
}

int main(int argc , char ** argv){

    initializeGlut(argc , argv) ; 

    glutMainLoop() ; 

}