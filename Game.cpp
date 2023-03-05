#include "Game.hpp"

Game::Game() {
    srand(time(NULL));
    
    //TODO: In Game Klasse auslagern
    World* gameWorld = new World();
    gameWorld->PrintWorld();
    int sumOfValues = gameWorld->GetSumOfValues();
    cout << "Game World sum: " << sumOfValues << endl;

    Robot* robot1 = new MultiRobot(0, 0);
    robot1->PrintPosition();
    
    Robot* robot2 = new SortingRobot(2,3);
    
    Robot* robot3 = new MultiRobot(1, 0);
    Robot* robot4 = new SortingRobot(1,3);
    Robot* robot5 = new SortingRobot(2,1);
    Robot* robot6 = new SortingRobot(2,1);
    
    //Robot* robot = robot2;
    
    
    //Robot1
    std::cout << "Robot 1" << std::endl;
    std::thread th0(&Game::MoveAndMine, this, ref(gameWorld), ref(robot1));

    //Robot2
        
    std::cout << "Robot 2" << std::endl;
    std::thread th1(&Game::MoveAndMine, this, ref(gameWorld), ref(robot2));
    
    //Robot3
    std::cout << "Robot 3" << std::endl;
    std::thread th2(&Game::MoveAndMine, this, ref(gameWorld), ref(robot3));

    //Robot4
    std::cout << "Robot 4" << std::endl;
    std::thread th3(&Game::MoveAndMine, this, ref(gameWorld), ref(robot4));
    
    //Robot5
    std::cout << "Robot 5" << std::endl;
    std::thread th4(&Game::MoveAndMine, this, ref(gameWorld), ref(robot5));

    //Robot6
    std::cout << "Robot 6" << std::endl;
    std::thread th5(&Game::MoveAndMine, this, ref(gameWorld), ref(robot6));
    
    th0.join();
    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    
    std::cout << "End scores: " << std::endl;
    cout << "Robot 1: ";
    robot1->PrintCollected();
    cout << "Robot 2: ";
    robot2->PrintCollected();
    cout << "Robot 3: ";
    robot3->PrintCollected();
    cout << "Robot 4: ";
    robot4->PrintCollected();
    cout << "Robot 5: ";
    robot5->PrintCollected();
    cout << "Robot 6: ";
    robot6->PrintCollected();
    
    int robotSum = robot1->GetCollected() + robot2->GetCollected() + robot3->GetCollected() + robot4->GetCollected() + robot5->GetCollected() + robot6->GetCollected();
    cout << "Sum of world: " << sumOfValues << " sum of robots: " << robotSum << endl;
}

void Game::MoveAndMine(World* gameWorld, Robot* robot){
    while(1){
        int direction = rand() % 4;
       
        switch (direction) {
            case 0:
                robot->MoveUp();
                break;
            case 1:
                robot->MoveDown();
                break;
            case 2:
                robot->MoveLeft();
                break;
            case 3:
                robot->MoveRight();
                break;
                
            default:
                break;
        }
        
        m.lock();
        if (gameWorld->CheckIfEmpty()) {
            m.unlock();
            return;
        }
        
        if(!gameWorld->GetZValues(robot->GetX(), robot->GetY())->empty())
            robot->Mine(gameWorld->GetZValues(robot->GetX(), robot->GetY()));
        m.unlock();
        
        m_cout.lock();
        std::cout << "Robot address: " << robot << endl;
        std::cout << "X: " << robot->GetX() << ", Y: " << robot->GetY() << std::endl;
        
        // VORSICHT! Bei PrintWorld() muss der Mutex m gelockt werden!
        //gameWorld->PrintWorld();
        robot->PrintCollected();
        m_cout.unlock();
        
        std::this_thread::sleep_for(1ms);
        //ODER
        //std::this_thread::yield();
    }
}
