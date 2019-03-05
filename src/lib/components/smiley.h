#include <math.h>


#ifndef _CAH_COMPONENT_SMILEY
#define _CAH_COMPONENT_SMILEY

void drawSmiley()
{
    int i;
    float x, y;
    glPointSize(2.0);
    for (i = 0; i <= 360; i++)
    {
        glBegin(GL_POINTS);
        x = (cos((2 * i * 3.14) / 360)) * .6;
        y = (sin((2 * i * 3.14) / 360)) * .6;
        glVertex2f(x, y);
        glEnd();
    }

    for (i = 240; i < 300; i++)
    {
        glBegin(GL_POINTS);
        x = cos((2 * i * 3.14) / 360) * .3;
        y = sin((2 * i * 3.14) / 360) * .3;
        glVertex2f(x, y);
        glEnd();
    }
    glPointSize(10.0);
    glBegin(GL_POINTS);
    glVertex2f(-.25, .2);
    glVertex2f(.25, .2);
    glEnd();

}

#endif