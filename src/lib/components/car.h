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

    static void renderDesign()
    {
        glEnable(GL_DEPTH_TEST);

        // Left Side
        glColor3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(-17.5, -15, 30);
        glVertex3d(-17.5, -15, -55);
        glVertex3d(-17.5, -10, -60);
        glVertex3d(-17.5, 10, -60);
        glVertex3d(-17.5, 10, -40);
        glVertex3d(-17.5, 20, -30);
        glVertex3d(-17.5, 20, 25);
        glVertex3d(-17.5, 15, 30);
        glEnd();

        // Left Window Glasses
        glColor3d(0, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-17.8, 5, 25);
        glVertex3d(-17.8, 5, -35);
        glVertex3d(-17.8, 10, -37);
        glVertex3d(-17.8, 18, -28);
        glVertex3d(-17.8, 18, 22);
        glVertex3d(-17.8, 15, 25);
        glEnd();

        // Right Side
        glColor3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(17.5, -15, 30);
        glVertex3d(17.5, -15, -55);
        glVertex3d(17.5, -10, -60);
        glVertex3d(17.5, 10, -60);
        glVertex3d(17.5, 10, -40);
        glVertex3d(17.5, 20, -30);
        glVertex3d(17.5, 20, 25);
        glVertex3d(17.5, 15, 30);
        glEnd();

        // Right Window Glasses
        glColor3d(0, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(17.8, 5, 25);
        glVertex3d(17.8, 5, -35);
        glVertex3d(17.8, 10, -37);
        glVertex3d(17.8, 18, -28);
        glVertex3d(17.8, 18, 22);
        glVertex3d(17.8, 15, 25);
        glEnd();

        // Back Truck Cover
        glColor3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(-17.5, -15, 30);
        glVertex3d(-17.5, 15, 30);
        glVertex3d(17.5, 15, 30);
        glVertex3d(17.5, -15, 30);
        glEnd();

        // Back Windshield
        glColor3d(0, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-17.5, 15, 30);
        glVertex3d(-17.5, 20, 25);
        glVertex3d(17.5, 20, 25);
        glVertex3d(17.5, 15, 30);
        glEnd();

        // Roof
        glColor3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(-17.5, 20, 25);
        glVertex3d(-17.5, 20, -30);
        glVertex3d(17.5, 20, -30);
        glVertex3d(17.5, 20, 25);
        glEnd();

        // Front Windshield
        glColor3d(0, 0, 0);
        glBegin(GL_POLYGON);
        glVertex3d(-17.5, 20, -30);
        glVertex3d(17.5, 20, -30);
        glVertex3d(17.5, 10, -40);
        glVertex3d(-17.5, 10, -40);
        glEnd();

        // Front Bonnet
        glColor3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(-17.5, 10, -40);
        glVertex3d(-17.5, 10, -60);
        glVertex3d(17.5, 10, -60);
        glVertex3d(17.5, 10, -40);
        glEnd();

        // Front Grill
        glColor3d(0, 0, 1);
        glBegin(GL_POLYGON);
        glVertex3d(-17.5, 10, -60);
        glVertex3d(-17.5, -15, -60);
        glVertex3d(17.5, -15, -60);
        glVertex3d(17.5, 10, -60);
        glEnd();

        // Left Stop Light
        glColor3d(1, 0, 0);
        glBegin(GL_QUADS);
        glVertex3d(-15, -5, 31);
        glVertex3d(-10, -5, 31);
        glVertex3d(-10, 0, 31);
        glVertex3d(-15, 0, 31);
        glEnd();

        // Right Stop Light
        glColor3d(1, 0, 0);
        glBegin(GL_QUADS);
        glVertex3d(15, -5, 31);
        glVertex3d(10, -5, 31);
        glVertex3d(10, 0, 31);
        glVertex3d(15, 0, 31);
        glEnd();

        // Symbol in the middle
        glColor3d(0, 1, 0);
        glBegin(GL_QUADS);
        glVertex3d(0, 0, 31);
        glVertex3d(3, 5, 31);
        glVertex3d(0, -10, 31);
        glVertex3d(-3, 5, 31);
        glEnd();

        glDisable(GL_DEPTH_TEST);

        glFlush();
    }

    static void renderCar()
    {
        // @m-zaink change the car to something good looking
        glPushMatrix();
        glColor3f(0, 1, 1);
        glTranslatef(x, y, z);
        glScalef(scalex, scaley, scalez);
        glScalef(0.1, 0.1, 0.5);
        renderDesign();
        glPopMatrix();
    }
};

float Car::x = 0, Car::y, Car::z = 300, Car::changeAmount = 1;
int Car::scalex = 1, Car::scaley = 1, Car::scalez = 1;
