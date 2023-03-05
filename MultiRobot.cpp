#include "MultiRobot.hpp"
#include <algorithm>

MultiRobot::MultiRobot(int x, int y) : Robot(x, y) {
    this->type = "MULTI_ROBOT";

}

void MultiRobot::Mine(std::vector<int>*values) {
    std::cout << "Mutli Robot mines!"<< std::endl;
    // Andere Sortierreihenfolge: std::greater<int>()
    int value = (*values).size();
    std::cout << value << std::endl;
    //collected += values[9] + values[8] + values[7];

    int counter = 0;
    while(!values->empty() && counter < 3){
       collected += values->back();
       values->pop_back(); 
       counter++;
    }
}
