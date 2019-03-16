#pragma once
#include <iostream>
#include <string>
#include <GL/glut.h>
#include "../basicStructures.h"

using namespace std;

class FrontCurtain
{
    static float curtainy;
    static bool done;
    static void raiseCurtain()
    {
        curtainy += 1;
    }
    static void drawString(string s)
    {
        glRasterPos2f(-50, 0 + curtainy);
        for (int i = 0; i < s.length(); i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, s[i]);
        }
    }

  public:
    static void drawStringSeperate(string s, float x, float y)
    {
        glRasterPos2f(x, y);
        for (int i = 0; i < s.length(); i++)
        {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, s[i]);
        }
    }

    static void handleCurtainDisplay()
    {

        if (SCREEN_Y_LOW + curtainy > 100)
            return;

        drawStringSeperate("ECO CAR : Play while you save the environment .. ", -20, 100);
        drawStringSeperate("Key map : use keybaord to control the car", -10, 200);

        glColor3f(0.5, 0.5, 1);
        glRectf(SCREEN_X_LOW, SCREEN_Y_LOW + curtainy, SCREEN_X_HIGH, SCREEN_Y_HIGH); //curtain

        glColor3f(1, 0, 0);
        glRectf(SCREEN_X_LOW, SCREEN_Y_LOW + curtainy, SCREEN_X_HIGH, SCREEN_Y_LOW + curtainy + 30); //curtain
        // glRectf(SCREEN_X_LOW , SCREEN_Y_LOW +curtainy , SCREEN_X_HIGH , (SCREEN_Y_LOW + 100) +curtainy) ;

        glColor3f(0, 0, 0);
        drawString("The ATeam: Natesh M Bhat , Mohammad Sadiq");

        raiseCurtain();
    }
};

float FrontCurtain::curtainy = 0.01;
bool FrontCurtain::done = false;
