

#ifndef SortingRobot_hpp
#define SortingRobot_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Robot.hpp"

class SortingRobot: public Robot {
public:
    SortingRobot(int x, int y);
    void Mine(std::vector<int>* values);
};

#endif /* SortingRobot_hpp */
