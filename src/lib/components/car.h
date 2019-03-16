#pragma once

#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

class Car
{
    static float x, y, z;
    static float changeAmount;
    static int scalex, scaley, scalez;

  public:
    static float getX() { return x; }
    static float getY() { return y; }
    static float getZ() { return z; }

    static void goRight()
    {
        x += changeAmount;
    }

    static void goLeft()
    {
        x -= changeAmount;
    }

    static void goForward()
    {
        z -= changeAmount;
    }

    static void goBackward()
    {
        z += changeAmount;
    }

    static void goUp()
    {
        y += changeAmount;
    }

    static void goDown()
    {
        y -= changeAmount;
    }

    static void designCar()
    {

        // Back WindShield  
        glColor3d(0, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(12, 12, 20);
        glVertex3d(-12, 12, 20);
        glVertex3d(-12, -4, 20);
        glVertex3d(12, -4, 20);
        glEnd();

        // Back Look
        glColor3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(15, 15, 20);
        glVertex3d(-15, 15, 20);
        glVertex3d(-15, -15, 20);
        glVertex3d(15, -15, 20);
        glEnd();

        // Roof
        glColor3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(15, 15, -20);
        glVertex3d(15, 15, 20);
        glVertex3d(-15, 15, 20);
        glVertex3d(-15, 15, -20);
        glEnd();

        // Car Panoromic View
        glColor3d(0, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(0, 15, -8);
        glVertex3d(14, 15, 0);
        glVertex3d(14, 15, 18);
        glVertex3d(-14, 15, 18);
        glVertex3d(-14, 15, 0);
        glEnd();

        glFlush();
    }

    static void renderCar()
    {
        // @m-zaink change the car to something good looking
        glPushMatrix();
        glColor3f(0, 1, 1);
        glTranslatef(x, y, z);
        // glScalef(scalex, scaley, scalez);
        glScalef(0.1, 0.1, 1);
        // glutWireSphere(10, 50, 50); //assuming this is car.
        designCar();
        glPopMatrix();
    }
};

float Car::x = 0, Car::y, Car::z = 300, Car::changeAmount = 1;
int Car::scalex = 1, Car::scaley = 1, Car::scalez = 1;
