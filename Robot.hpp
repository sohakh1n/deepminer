
#ifndef Robot_hpp
#define Robot_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

class Robot {
public:
    Robot(int x, int y);
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();
    int GetX();
    int GetY();
    int GetCollected();
    void PrintPosition();
    void PrintCollected();
    std::string getType();
    virtual void Mine(std::vector<int>* values);
    void hello_world(){
        std::cout << "hello_world" << std::endl;
    }
    
protected:
    int collected;
    std::string type;
    
private:
    int x;
    int y;
};

#endif /* Robot_hpp */
