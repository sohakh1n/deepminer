#ifndef MultiRobot_hpp
#define MultiRobot_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Robot.hpp"

class MultiRobot: public Robot {
public:
    MultiRobot(int x, int y);
    void Mine(std::vector<int>* values);
};

#endif /* MultiRobot_hpp */