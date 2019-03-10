#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

void renderCar()
{
    // Right Side
    glColor3d(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3d(5, 0, -1);
    glVertex3d(2, 1, -0.5);
    glVertex3d(-3, 1, -0.5);
    glVertex3d(-3.5, 0.5, -1);
    glVertex3d(-3, -1, -0.5);
    glVertex3d(4, -1, -0.5);
    glEnd();

    // Left Side
    glColor3d(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3d(5, 0, 1);
    glVertex3d(2, 1, 0.5);
    glVertex3d(-3, 1, 0.5);
    glVertex3d(-3.5, 0.5, 1);
    glVertex3d(-3, -1, 0.5);
    glVertex3d(4, -1, 0.5);
    glEnd();

    // Top Chassis
    glColor3d(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3d(-3, -1, -1);
    glVertex3d(-3, -1, 1);
    glVertex3d(4, -1, -1);
    glVertex3d(-4, -1, 1);
    glEnd();

    // Bottom Chassis
    glColor3d(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3d(-3, 1, -1);
    glVertex3d(-3, 1, 1);
    glVertex3d(2, 1, -1);
    glVertex3d(-2, 1, 1);
    glEnd();

    // Front WindShield
    glColor3d(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3d(5, 0, -1);
    glVertex3d(2, 1, -0.5);
    glVertex3d(2, 1, 0.5);
    glVertex3d(5, 0, 1);
    glEnd();

    // Front Bottom Part
    glColor3d(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3d(5, 0, -1);
    glVertex3d(4, -1, -0.5);
    glVertex3d(4, -1, 0.5);
    glVertex3d(5, 0, 1);
    glEnd();

    // Rear Windshield
    glColor3d(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3d(-3.5, 0.5, -1);
    glVertex3d(-3, 1, -0.5);
    glVertex3d(-3, 1, 0.5);
    glVertex3d(-3.5, 0.5, 1);
    glEnd();

    // Read Bottom Part
    glColor3d(0, 0, 1);
    glBegin(GL_POLYGON);
    glVertex3d(-3.5, 0.5, -1);
    glVertex3d(-3, -1, -0.5);
    glVertex3d(-3, -1, 0.5);
    glVertex3d(-3.5, 0.5, 1);
    glEnd();
    
    glFlush();
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

    renderCar();

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