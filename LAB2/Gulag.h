#include <iostream>
using namespace std;

class Gulag{
    private:
    int prisoners, stone, lazy;
    public:
    Gulag(){
        prisoners = stone = 0;
    }
    void gatherStone(){
        int index = prisoners * (rand()%20);
        lazy += index / 50;
        stone += prisoners - lazy;
        cout << prisoners - lazy << " stone was mined today" << endl;
    }
    int *lineupPrisoners(){
        return &prisoners;
    }
    int *countStone(){
        return &stone;
    }
    int *prepareTheLazy(){
        return &lazy;
    }
    void print(){
        cout << "The gulag holds " << prisoners << " prisoners." << endl;
    }
};
