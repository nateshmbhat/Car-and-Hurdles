#include<iostream> 
#include<iomanip> 
#include "./hurdle.h" 
#include<GL/glut.h>


class Car{ //assuming as a rectangle for now
    private :
        float width , height ;

    public : 
        float getWidth(){return width ; }
        float getHeight(){return height; }
        void setWidth(float w){width = w ; } 
        void setHeight(float h){height = h ; } 

};