#pragma once

#include <bits/stdc++.h>
#include <GL/glut.h>
#include "lib/components/car.h"
#include "lib/components/curtain.h"
#include "lib/components/tree.cpp"

class Game
{
    static float speed;
    static vector<Tree> trees;

  public:
    static void setSpeed(float x) { speed = x; }
    static float getSpeed() { return speed; }


    static void handleObjects()
    {
        for(int i=0 ;i < trees.size() ; i++)
            trees[i].renderTree(); 

        Car::renderCar();

        FrontCurtain::handleCurtainDisplay();
    }




    static void moveAllTreesForward()
    {
        for (int i = 0; i < trees.size(); i++)
            trees[i].incZ();
    }

    static void moveAllTreesBackward()
    {
        for (int i = 0; i < trees.size(); i++)
            trees[i].decZ();
    }

    static void moveAllTreesLeft()
    {
        for (int i = 0; i < trees.size(); i++)
            trees[i].decX();
    }

    static void moveAllTreesRight()
    {
        for (int i = 0; i < trees.size(); i++)
        {
            trees[i].incX();
        }
    }
};

float Game::speed = 0.0001;
vector<Tree> Game::trees ; 