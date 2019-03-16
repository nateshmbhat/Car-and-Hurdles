#pragma once

#include <GL/glut.h>
#include<time.h>

class Tree
{
    float x, y, z;
    float changeAmount, speed;
    int scalex, scaley, scalez;

  public:
    Tree(float sp):speed(sp)
    {
        z = -400 ; 
        x = -25 ;
        x += rand()%50 ; 
        changeAmount = 1;
        scalex = scaley = scalez = 1;
    }

    float getX(){return x ; }
    float getY(){return y ; }
    float getZ(){return z ; }

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
        glColor3d(0.51, 0, 0);
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
        glColor3d(0, 1, 0);
        glutSolidSphere(2, 10, 10);
        glPopMatrix();
    }
};