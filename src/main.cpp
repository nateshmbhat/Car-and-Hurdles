// DRIVER PROGRAM
#include <iostream>
#include <iomanip>
#include "lib/components/tree.cpp"
#include "lib/basicStructures.h"
#include "lib/eventHandlers/mouse.h"
#include "lib/eventHandlers/keyboard.h"
#include "lib/eventHandlers/reshape.h"
#include <GL/glut.h>
#include "game.h"

using namespace std;


void display()
{
    // Just drawing random stuff for a trail run before Setting the stage for fun :)

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1, 1, 1, 0);

    Game::mainGameLoop() ; 

    glutSwapBuffers();
}

void idleHandler()
{
    glutPostRedisplay();
}

void initializeGlut(int argc, char **argv)
{
    // Initializes glut and open up a window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Car And Hurdles");
    glutDisplayFunc(display);
    glutReshapeFunc(reshapeHandler);
    glutKeyboardFunc(keyboardHandler);
    glutMouseFunc(mouseHandler);
    glutMotionFunc(mouseMotionHandler);
    glutIdleFunc(idleHandler);
    glutSpecialFunc(specialKeyHandler);
    // glEnable(GL_DEPTH_TEST);
}

int main(int argc, char **argv)
{
    initializeGlut(argc, argv);
    glutMainLoop();
}