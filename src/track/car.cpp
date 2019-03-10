#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

void renderCar()
{
    glColor3d(1, 1, 1);
}

void reshape()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    double w = glutGet(GLUT_WINDOW_WIDTH);
    double h = glutGet(GLUT_WINDOW_HEIGHT);
    double ar = w / h;
    glOrtho(-10 * ar, 10 * ar, -10, 10, -10, 10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    reshape();

    glPushMatrix();
    glLoadIdentity();
    glScaled(0.5, 0.5, 0.5);
    renderCar();

    glPopMatrix();

    glutSwapBuffers();
}

int main(int a, char **s)
{
    glutInit(&a, s);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Tree");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}