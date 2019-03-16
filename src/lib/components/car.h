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
    static float getX(){return x ; }
    static float getY(){return y ; }
    static float getZ(){return z ; }

    static void goRight()
    {
        x+=changeAmount;
    }

    static void goLeft()
    {
        x-=changeAmount;
    }

    static void goForward()
    {
        z-=changeAmount;
    }

    static void goBackward()
    {
        z+=changeAmount;
    }

    static void goUp()
    {
        y+=changeAmount;
    }

    static void goDown()
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

float Car::x = 0, Car::y, Car::z = 300 , Car::changeAmount = 1;
int Car::scalex = 1, Car::scaley = 1, Car::scalez = 1;
