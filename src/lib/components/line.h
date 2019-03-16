#pragma once

#include<GL/glut.h>
#include"../basicStructures.h"

#ifndef _CAH_COMPONENT_LINE
#define _CAH_COMPONENT_LINE

void drawLine(Point p , Point q){
    glBegin(GL_LINES) ; 
    glVertex3f(p.x , p.y , p.z) ; 
    glVertex3f(q.x , q.y , q.z) ; 
    glEnd() ; 
    glFlush() ; 
}

#endif