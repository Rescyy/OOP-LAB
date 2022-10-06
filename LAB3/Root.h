#include <iostream>
#include <array>
using namespace std;

int minint(int a, int b){
    if(a > b)
    return b;
    return a;
}

class Root{
    protected:
    string title;
    public:
    string askForTheirTitle(){
        return title;
    }
};

class Buildings : public Root{
    protected:
    int people;
    public:
    int *checkonPeople(){
        return &people;
    }
    void print(){
        cout << "The " << title << " holds " << people << " people." << endl;
    }
};

class Economy : public Buildings{
    protected:
    int lazy;
    public:
    int *lineupTheLazy(){
        return &lazy;
    }
};

class Gulag : public Economy{
    private:
    int stone;
    public:
    Gulag(){
        people = 0;
        stone = 0;
        lazy = 0;
        title = "Gulag";
    }
    void gatherStone(){
        int index = people * (rand()%20);
        lazy += index / 50;
        stone += people - lazy;
        cout << people - lazy << " stone was mined today" << endl;
    }
    int *countStone(){
        return &stone;
    }
};

class Colhoz : public Economy{
    private:
    int carrots, iron;
    public:
    Colhoz(){
        carrots = 0;
        people = 0;
        iron = 0;
        lazy = 0;
        title = "Colhoz";
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
    int *weighIron(){
        return &iron;
    }
    int *countCarrots(){
        return &carrots;
    }
};

class Fabrica : public Economy{
    private:
    int product, cement, iron, stone;
    public:
    Fabrica(){
        product = 0;
        people = 0;
        cement = 0;
        lazy = 0;
        iron = 0;
        stone = 0;
        title = "Fabrica";
    }
    void craftProduct(){
        int index = people * (rand()%5);
        lazy += index / 100;
        product += minint(people - lazy, iron);
        iron -= minint(people - lazy, iron);
        cout << minint(people - lazy, iron) << " products were manufactured today" << endl;
    }
    void craftCement(){
        int index = people * (rand()%10);
        lazy += index / 100;
        cement += minint(people - lazy, stone);
        stone -= minint(people - lazy,stone);
        cout << minint(people - lazy, stone) << " cement was packed today" << endl;
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
};

class Civil : public Buildings{
    protected:
    int children;
    public:
    int *countChildren(){
        return &children;
    }
};

class Apartament : public Civil{
    private:
    int cement, product, carrots, maxPeople, toddlers;
    public:
    Apartament(){
        cement = 0;
        product = 0;
        people = 10;
        maxPeople = 10;
        toddlers = 0;
        title = "Apartament";
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
        *destination += people / 5;
        people -= people / 5;
    }
    void sendToFabrica(int *destination){
        *destination += people / 4;
        people -= people / 4;
    }
    void makeChildren(){
        int min = minint(people / 2, carrots);
        toddlers += min;
        carrots -= min;
        cout << min << " children were born today." << endl;
    }
    void printmax(){
        cout << "The maximum capacity of the apartment is " << maxPeople << " people." << endl;
    }
};

class School : public Civil{
    public:
    School(){
        people = 0;
        children = 0;
        title = "School";
    }
    void educateChildren(){
        people += children;
        children = 0;
    }
};

class People : public Root{
    protected:
    int age;
    public:
    void askThemAboutTheirAge(){
        cout << "The " << title << " is " << age << " years old." << endl;
    }
};

class Colhoznic : public People{
    public:
    Colhoznic(){
        age = 20;
        title = "Colhoznic";
    }
    void deliverProducts(int *source, int *destination){
        *destination += *source;
        *source = 0;
        age++;
    }
};

class Grajdanin : public People{
    public:
    Grajdanin(){
        age = 20;
        title = "Grajdanin";
    }
    void growChildren(int *children, int *toddlers){
        *children += *toddlers;
        *toddlers = 0;
        age++;
    }
    void sendChildrenToSchool(int *source, int *destination){
        *destination += *source;
        *source = 0;
        age++;
    }
};

class Guard : public People{
    public:
    Guard(){
        age = 20;
        title = "Guard";
    }
    void killPrisoner(int *prisoners, int *lazy){
        cout << *lazy << " prisoners were executed due to their laziness." << endl;
        *prisoners -= *lazy;
        *lazy = 0;
        age++;
    }
};

class KGB : public People{
    public:
    KGB(){
        age = 20;
        title = "Secret Agent";
    }
    void fireColhoznic(int *gulag, int *people, int *lazy, string title){
        *people -= *lazy;
        cout << *lazy << " " << title << " colhoznics were lazy, a horrible fate awaits them." << endl;
        *gulag += *lazy;
        *lazy = 0;
    }
};

class Teacher : public People{
    public:
    Teacher(){
        title = "Teacher";
        age = 20;
    }
    void sendThemHome(int *source, int maxPeople, int *destination){
        if(*source > maxPeople - *destination){
        *source -= maxPeople - *destination;
        cout << "Graduates sent home " << maxPeople - *destination << endl;
        *destination = maxPeople;
        }else{
        *destination += *source;
        cout << "Graduates sent home " << *source << endl;
        *source = 0;
        }
    }
};