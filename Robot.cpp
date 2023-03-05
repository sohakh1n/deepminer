

#include "Robot.hpp"
using namespace std;

Robot::Robot(int x, int y) {
    this->x = x;
    this->y = y;
    this->collected = 0;
    this->type = "ROBOT";
}

void Robot::MoveUp() {
    if (this->y == 0) {
        this->y = 4;
    } else {
        this->y--;
    }
}

void Robot::MoveDown() {
    if (this->y == 4) {
        this->y = 0;
    } else {
        this->y++;
    }
}

void Robot::MoveLeft() {
    if (this->x == 0) {
        this->x = 4;
    } else {
        this->x--;
    }
}

void Robot::MoveRight() {
    if (this->x == 4) {
        this->x = 0;
    } else {
        this->x++;
    }
}

int Robot::GetX() {
    return x;
}

int Robot::GetY() {
    return y;
}

int Robot::GetCollected() {
    return collected;
}

void Robot::PrintPosition() {
    std::cout << "x: " << this->x << " y: " << this->y << std::endl;
}

void Robot::PrintCollected() {
    std::cout << "Collected: " << this->collected << std::endl;
}

void Robot::Mine(std::vector<int>* values) {
    std::cout << "Robot mines!" << std::endl;
}

std::string Robot::getType() {
    return type;
}
