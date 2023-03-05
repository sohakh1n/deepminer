#include "Game.hpp"


using namespace std;

int main(int argc, const char * argv[]) {
    Game* game = new Game();
    
    /*while (1) {
        char direction;
        cout << "Current robot position: ";
        robot->PrintPosition();
        cout << endl;
        cout << "Enter a direction (wasd): ";
        cin >> direction;
        switch (direction) {
            case 'w':
                robot->MoveUp();
                break;
            case 's':
                robot->MoveDown();
                break;
            case 'a':
                robot->MoveLeft();
                break;
            case 'd':
                robot->MoveRight();
                break;
                
            default:
                break;
        }

        robot->Mine(gameWorld.GetZValues(robot->GetX(), robot->GetY()));
        
        gameWorld.PrintWorld();
        robot->PrintCollected();
        
        if (robot == robot1) {
            robot = robot2;
        } else {
            robot = robot1;
        }
    }*/
    
    return 0;
}
