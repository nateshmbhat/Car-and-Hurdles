#include <iostream>
#include<GL/glut.h>
#include "../src/lib/components/smiley.h"
#include<bits/stdc++.h>

using namespace std  ;

class FrontCurtain{
    static float curtainy ;
    static bool done ; 
    static void raiseCurtain(){
        curtainy+=0.001 ; 
    }
    static void drawString(string s){
        glRasterPos2f(-0.8,0+curtainy) ;
        for(int i= 0 ;i < s.length() ; i++){
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15 , s[i]) ;
        }
    }

public :

    static void drawStringSeperate(string s , float x , float y ){
        glRasterPos2f(x,y ) ;
        for(int i= 0 ;i < s.length() ; i++){
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15 , s[i]) ;
        }
    }

    static void handleCurtainDisplay(){

        drawStringSeperate("ECO CAR : Play while you save the environment .. ", -0.8 , 0) ; 
        drawStringSeperate("Key map : use keybaord to control the car", -0.8 , 0.2) ; 

        glColor3f(0.5 ,0.5 , 1) ;
        glRectf(-1 , -1+curtainy , 1 , 1) ; //curtain
        glColor3f(1,0,0) ; 
        glRectf(-1 , -1 +curtainy , 1 , -0.8 +curtainy) ;  

        glColor3f(0,0,0) ;
        drawString("The ATeam: Natesh M Bhat , Mohammad Sadiq") ; 

        raiseCurtain() ;
    }
};


float FrontCurtain::curtainy = 0.01 ;
bool FrontCurtain::done = false ; 

void reshape(int w, int h){
    glViewport(0,0,w, h) ;
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT) ;
    glClearColor(1,1,1,1) ;

    FrontCurtain::handleCurtainDisplay() ;

    glFlush() ;
}

void idleFunction(){
    glutPostRedisplay() ;
}


int main(int argc , char * *argv)
{
    glutInit(&argc , argv) ;
    glutInitDisplayMode(GLUT_SINGLE| GLUT_DEPTH) ;
    glutInitWindowSize(600,600) ; 
    glutCreateWindow("Eco Car") ;
    glutDisplayFunc(display) ;
    glutIdleFunc(idleFunction) ;
    glutMainLoop() ;
}
