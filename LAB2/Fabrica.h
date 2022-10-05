#include <iostream>
using namespace std;

int minint(int a, int b){
    if(a > b)
    return b;
    return a;
}

class Fabrica{
    private:
    int product, people, cement, lazy, iron, stone;
    public:
    Fabrica(){
        product = people = cement = lazy = iron = stone = 0;
    }
    void craftProduct(){
        int index = people * (rand()%5);
        lazy += index / 100;
        product += minint(people - lazy, iron);
        iron -= minint(people - lazy, iron);
        cout << people - lazy << " products were manufactured today" << endl;
    }
    void craftCement(){
        int index = people * (rand()%10);
        lazy += index / 100;
        cement += minint(people - lazy, stone);
        stone -= minint(people - lazy,stone);
        cout << people - lazy << " cement was packed today" << endl;
    }
    int *weighIron(){
        return &iron;
    }
    int *weighStone(){
        return &stone;
    }
    int *organizeProduct(){
        return &product;
    }
    int *packCement(){
        return &cement;
    }
    int *lineupTheLazy(){
        return &lazy;
    }
    int *checkOnPeople(){
        return &people;
    }
    void print(){
        cout << "The factory holds " << people << " people." << endl;
    }
};