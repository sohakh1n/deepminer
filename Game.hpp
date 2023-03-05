#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <iostream>
#include <ctime>
#include <mutex>
#include <thread>
#include "Robot.hpp"
#include "World.hpp"
#include "SortingRobot.hpp"
#include "MultiRobot.hpp"

class Game {
public:
    Game();
    
private:
    void MoveAndMine(World* gameWorld, Robot* robot);
    mutex m;
    mutex m_cout;
};

#endif /* Game_hpp */
