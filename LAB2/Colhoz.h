#include <iostream>
using namespace std;

class Colhoz{
    private:
    int carrots, people, iron, lazy;
    public:
    Colhoz(){
        carrots = people = iron = lazy = 0;
    }
    void growCarrots(){
        int index = people * (rand()%5);
        lazy += index / 100;
        carrots += people - lazy;
        cout << people - lazy << " carrots were grown today" << endl;
    }
    void mineIron(){
        int index = people * (rand()%10);
        lazy += index / 100;
        iron += people - lazy;
        cout << people - lazy << " iron was mined today" << endl;
    }
    int *countIron(){
        return &iron;
    }
    int *countCarrots(){
        return &carrots;
    }
    int *checkOnPeople(){
        return &people;
    }
    int *lineupTheLazy(){
        return &lazy;
    }
    void print(){
        cout << "The colhoz holds " << people << " people." << endl;
    }
};
