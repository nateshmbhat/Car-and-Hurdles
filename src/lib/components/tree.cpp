#pragma once

#include <GL/glut.h>

class Tree
{
    float x, y, z;
    float changeAmount, speed;
    int scalex, scaley, scalez;

  public:
    Tree()
    {
        x = y = z = 0;
        changeAmount = 1;
        speed = 0.0001;
        scalex = scaley = scalez = 1;
    }

    void incX()
    {
        x+=changeAmount;
    }

    void decX()
    {
        x-=changeAmount;
    }

    void incZ()
    {
        z+=changeAmount;
    }

    void decZ()
    {
        z-=changeAmount;
    }

    void incY()
    {
        y+=changeAmount;
    }

    void decY()
    {
        y-=changeAmount;
    }

    void makeTreeMovement()
    {
        z+= speed ; 
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