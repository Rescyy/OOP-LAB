#include <iostream>
using namespace std;

int mininti(int a, int b){
    if(a > b)
    return b;
    return a;
}

class Apartament{
    private:
    int cement, product, carrots, people, maxPeople, toddlers, children;
    public:
    Apartament(){
        cement = 0;
        product = 0;
        people = 10;
        maxPeople = 10;
        toddlers = 0;
    }
    int *countChildren(){
        return &children;
    }
    int *checkonPeople(){
        return &people;
    }
    int *countToddlers(){
        return &toddlers;
    }
    int inspectApartmentCapacity(){
        return maxPeople;
    }
    int *checkCementAmmount(){
        return &cement;
    }
    int *checkProductAmmount(){
        return &product;
    }
    int *checkCarrotsAmmount(){
        return &carrots;
    }
    void expandApartment(){
        int min = minint(cement, product);
        maxPeople += min;
        cement -= min;
        product -= min;
    }
    void sendToColhoz(int *destination){
        if(people){
        *destination += 1;
        people -= 1;
        }
    }
    void sendToFabrica(int *destination){
        if(people){
        *destination += 1;
        people -= 1;
        }
    }
    void makeChildren(){
        int min = mininti(3*people/5, carrots);
        toddlers += min;
        carrots -= min;
        cout << min << " children were born today." << endl;
    }
    void print(){
        cout << "The maximum capacity of the apartment is " << maxPeople << "." << endl;
    }
};