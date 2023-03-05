#include "World.hpp"

World::World() {
    field = grid();
    std::default_random_engine generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(1, 9);
    // 5 x 5 x 10
    
    //Ein Feld durchmischen: https://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
    
    for (int x = 0; x < 5; x++) {
        field.push_back(vector<vector<int> >());
        for (int y = 0; y < 5; y++) {
            field.at(x).push_back(vector<int>(10));
            for (int z = 0; z < 10; z++) {
                field.at(x).at(y).at(z) = distribution(generator);
            }
        }
    }
}

void World::PrintWorld() {
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            for (int z = 0; z < field.at(x).at(y).size(); z++) {
                cout << field.at(x).at(y).at(z) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

vector<int>* World::GetZValues(int x, int y) {
    return &field.at(x).at(y);
}

int World::GetSumOfValues() {
    int sum = 0;
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            for (int z = 0; z < field.at(x).at(y).size(); z++) {
                sum += field.at(x).at(y).at(z);
            }
        }
    }
    
    return sum;
}

bool World::CheckIfEmpty(){
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            if(!field.at(x).at(y).empty()){
                //cout << "not empty" << endl;
                return false;
            }
                
        }
    }
    
    return true;
}
