header_files = case.hpp
data_files := main.cpp Robot.cpp World.cpp SortingRobot.cpp MultiRobot.cpp Game.cpp $(header_files) 
object_files = main.o Robot.o World.o SortingRobot.o MultiRobot.o Game.o
Game: $(object_files)
	g++ $(object_files) -o Game 

$(object_files): $(data_files)
	g++ -pthread -std=c++17 -c $(data_files)

Test:
	g++ -pthread -std=c++17 tests.cpp Robot.cpp World.cpp SortingRobot.cpp MultiRobot.cpp Game.cpp -o Test

run:
	./Game
