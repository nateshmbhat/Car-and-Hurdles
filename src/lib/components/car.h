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
    static void incX()
    {
        x+=changeAmount;
    }

    static void decX()
    {
        x-=changeAmount;
    }

    static void incZ()
    {
        z+=changeAmount;
    }

    static void decZ()
    {
        z-=changeAmount;
    }

    static void incY()
    {
        y+=changeAmount;
    }

    static void decY()
    {
        y-=changeAmount;
    }

    static void renderCar()
    {
        // @m-zaink change the car to something good looking
        glPushMatrix();
        glColor3f(0,1,1) ; 
        glTranslatef(x, y, z);
        glScalef(scalex, scaley, scalez);
        glutWireSphere(10, 50, 50); //assuming this is car.
        glPopMatrix();
    }
};

float Car::x = 0, Car::y, Car::z, Car::changeAmount;
int Car::scalex = 1, Car::scaley = 1, Car::scalez = 1;
