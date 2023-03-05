#define CATCH_CONFIG_MAIN
#include "case.hpp"
#include "Game.hpp"

Robot robot1(1,1);
MultiRobot robot2(0,0);
SortingRobot robot3(4,4);

World game_world();


TEST_CASE("check robot type", "[robot_type]") {
        REQUIRE(robot1.getType()=="ROBOT");
        REQUIRE(robot2.getType()=="MULTI_ROBOT");
        REQUIRE(robot3.getType()=="SORTING_ROBOT");
}

TEST_CASE("check robot movement", "[movement_check]") {
        robot1.MoveUp();
        robot1.MoveLeft();
        robot1.MoveDown();
        robot1.MoveRight();
        REQUIRE(robot1.GetX()==1);
        REQUIRE(robot1.GetY()==1);
        robot2.MoveUp();
        robot2.MoveLeft();
        robot2.MoveDown();
        robot2.MoveRight();
        REQUIRE(robot2.GetX()==0);
        REQUIRE(robot2.GetY()==0);
        robot3.MoveUp();
        robot3.MoveLeft();
        robot3.MoveDown();
        robot3.MoveRight();
        REQUIRE(robot3.GetX()==4);
        REQUIRE(robot3.GetY()==4);
}

TEST_CASE("check robot collect" "[collect_check]") {
        REQUIRE(robot1.GetCollected()==0);
        REQUIRE(robot2.GetCollected()==0);
        REQUIRE(robot3.GetCollected()==0);
}


