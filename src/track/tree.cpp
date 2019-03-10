#include <bits/stdc++.h>
#include <GL/glut.h>

using namespace std;

void renderTree()
{

    glColor3d(0.51, 0, 0);
    glBegin(GL_TRIANGLE_FAN);
        glVertex3d(0, 0, 0);
        glVertex3d(-1, -4, -1);
        glVertex3d(1, -4, -1);
        glVertex3d(1, -4, 1);
        glVertex3d(-1, -4, 1);
    glEnd();

    glColor3d(0, 1, 0);
    glutSolidSphere(2, 10, 10);
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

    renderTree();

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