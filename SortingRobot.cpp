
#include "SortingRobot.hpp"
#include <algorithm>

SortingRobot::SortingRobot(int x, int y) : Robot(x, y) {
    this->type = "SORTING_ROBOT";
}

void SortingRobot::Mine(std::vector<int>* values) {
    std::cout << "Sorting Robot mines!"<< std::endl;
    // Andere Sortierreihenfolge: std::greater<int>()
    std::sort(values->begin(), values->end(), std::less<int>());
    collected += values->back();
    values->pop_back();
}
