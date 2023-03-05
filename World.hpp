
#ifndef World_hpp
#define World_hpp

#include <vector>
#include <random>
#include <iostream>

using namespace std;

typedef vector<vector<vector<int> > > grid;


class World {
public:
    World();
    void PrintWorld();
    // TODO: GetZ() schreiben -> returnt Vector<int>
    std::vector<int>* GetZValues(int x, int y);
    bool CheckIfEmpty();
    int GetSumOfValues();
    
private:
    grid field;
};

#endif /* World_hpp */
