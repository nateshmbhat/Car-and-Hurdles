#pragma once

#include <GL/glut.h>
#include<time.h>

class Tree
{
    float x, y, z;
    float changeAmount, speed;
    int scalex, scaley, scalez;
    double colorBase[3]  ;  
    double colorTop[3]  ;  

  public:
    Tree(float sp):speed(sp)
    {
        z = -400 ; 
        x = -25 ;
        x += rand()%50 ; 
        changeAmount = 1;
        scalex = scaley = scalez = 1;
        colorBase[0] = 0.51 , colorBase[1]=  0, colorBase[2] = 0 ; 
        colorTop[1] = 1 ; 
    }

    float getX(){return x ; }
    float getY(){return y ; }
    float getZ(){return z ; }

    void changeTreeColorToRed(){
        colorTop[0] = 1 ; 
        colorTop[1] = 0 ;
    }

    void setSpeed(float s){
        speed =s ; 
    }
    float getSpeed(){
        return speed ; 
    }
    void incX()
    {
        x += changeAmount;
    }

    void decX()
    {
        x -= changeAmount;
    }

    void incZ()
    {
        z += changeAmount;
    }

    void decZ()
    {
        z -= changeAmount;
    }

    void incY()
    {
        y += changeAmount;
    }

    void decY()
    {
        y -= changeAmount;
    }

    void makeTreeMovement()
    {
        z += speed;
    }

    void renderTree()
    {
        glColor3dv(colorBase) ; 
        glPushMatrix();
        glTranslatef(x, y, z);
        glScalef(scalex, scaley, scalez);
        glBegin(GL_TRIANGLE_FAN);
        glVertex3d(0, 0, 0);
        glVertex3d(-1, -4, -1);
        glVertex3d(1, -4, -1);
        glVertex3d(1, -4, 1);
        glVertex3d(-1, -4, 1);
        glEnd();
        glColor3dv(colorTop)  ;
        glutSolidSphere(2, 10, 10);
        glPopMatrix();
    }
};