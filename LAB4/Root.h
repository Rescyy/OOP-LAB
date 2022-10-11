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
    string askForTheTitle(){
        return title;
    }
    virtual void doDuty(){
    };
};

class Buildings : public Root{
    protected:
    int people;
    public:
    virtual void print(){
        cout << "The " << title << " holds " << people << " people." << endl;
    }
    virtual int *report(string a) = 0;
};

class Economy : public Buildings{
    protected:
    int lazy;
    public:
    int *lineupTheLazy(){
        return &lazy;
    }
    virtual void produceResource() = 0;
    void doDuty(){
        produceResource();
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
    void produceResource(){
        int index = people * (rand()%20);
        lazy = index / 50;
        stone += people - lazy;
        cout << people - lazy << " stone was mined today" << endl;
    }
    int *report(string a){
        if(a == "people")
            return &people;
        if(a == "stone")
            return &stone;
        else
            cout << "I don't know what the s**a bl** " << a << " is!!!";
            return NULL;
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
    void produceResource(){
        int index = people * (rand()%5);
        lazy = index / 100;
        carrots += people - lazy;
        cout << people - lazy << " carrots were grown today" << endl;
        index = people * (rand()%10);
        lazy += index / 100;
        iron += people - lazy;
        cout << people - lazy << " iron was mined today" << endl;
    }
    int *report(string a){
        if(a == "people")
            return &people;
        if(a == "iron")
            return &iron;
        else if(a == "carrots")
            return &carrots;
        else
            cout << "I don't know what the s**a bl**t " << a << " is!!!";
        return NULL;
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
    int *report(string a){
        if(a == "people")
            return &people;
        if(a == "iron")
            return &iron;
        else if(a == "stone")
            return &stone;
        else if(a == "product")
            return &product;
        else if(a == "cement")
            return &cement;
        else
            cout << "I don't know what the s**a bl**t " << a << " is!!!";
        return NULL;
    }
    void produceResource(){
        int index = people * (rand()%5);
        lazy = index / 100;
        cout << minint(people - lazy, iron) << " products were manufactured today" << endl;
        product += minint(people - lazy, iron);
        iron -= minint(people - lazy, iron);
        index = people * (rand()%10);
        lazy += index / 100;
        cout << minint(people - lazy, stone) << " cement was packed today" << endl;
        cement += minint(people - lazy, stone);
        stone -= minint(people - lazy,stone);
    }
};

class Civil : public Buildings{
    protected:
    int children;
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
    void print(){
        cout << "The " << title << " holds " << people << " people." << endl;
        cout << "The maximum capacity of the " << title << " is " << maxPeople << " people." << endl;
    }
    void expandApartment(){
        int min = minint(cement, product);
        maxPeople += min;
        cement -= min;
        product -= min;
        print();
    }
    void doDuty(int *destination1, int *destination2){
        int min = minint(people / 2, carrots);
        toddlers += min;
        carrots -= min;
        cout << min << " children were born today." << endl;
        min = people / 5;
        *destination1 += min;
        people -= min;
        *destination2 += min;
        people -= min;
    }
    int *report(string a){
        if(a == "people")
            return &people;
        if(a == "toddlers")
            return &toddlers;
        else if(a == "carrots")
            return &carrots;
        else if(a == "product")
            return &product;
        else if(a == "cement")
            return &cement;
        else if(a == "children")
            return &children;
        else if(a == "maxPeople")
            return &maxPeople;
        else
            cout << "I don't know what the s**a bl**t " << a << " is!!!";
        return NULL;
    }
};

class School : public Civil{
    public:
    School(){
        people = 0;
        children = 0;
        title = "School";
    }
    void doDuty(){
        people += children;
        children = 0;
    }
    int *report(string a){
        if(a == "people")
            return &people;
        if(a == "children")
            return &children;
        else
            return NULL;
    }
};

class People : public Root{
    protected:
    int age;
    public:
    virtual void askThemAboutTheirAge(){
        cout << "The " << askForTheTitle() << " is " << age << " years old." << endl;
    }
};

class Colhoznic : public People{
    public:
    Colhoznic(){
        age = 20;
        title = "Colhoznic";
    }
    void doDuty(int *source, int *destination){
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
    void doDuty(int *source, int *candid, int *destination){
        *candid += *source;
        *source = 0;
        *destination += *candid;
        *candid = 0;
        age++;
    }
};

class Persecutor : public People{
    protected:
    int *lazy, *people;
};

class Guard : public Persecutor{
    public:
    Guard(int *plazy, int *ppeople){
        lazy = plazy;
        people = ppeople;
        age = 20;
        title = "Guard";
    }
    void doDuty(){
        cout << *lazy << " prisoners were executed due to their laziness." << endl;
        if(*people > *lazy){
            *people -= *lazy;
            *lazy = 0;
            age++;
        }
    }
};

class KGB : public People{
    public:
    KGB(){
        age = 20;
        title = "Secret Agent";
    }
    void doDuty(int *gulag, int *people, int *lazy, string title){
        *people -= *lazy;
        cout << *lazy << " " << title << " colhoznics were lazy, a horrible fate awaits them." << endl;
        *gulag += *lazy;
        *lazy = 0;
    }
    void askThemAboutTheirAge(){
        cout << askForTheTitle() << " cannot give you their age.";
    }
    void threaten(){
        cout << "Alright, I am " << age << ".";
    }
};

class Teacher : public People{
    public:
    Teacher(){
        title = "Teacher";
        age = 20;
    }
    void doDuty(int *source, int *maxPeople, int *destination){
        if(*source > *maxPeople - *destination){
        *source -= *maxPeople - *destination;
        cout << "Graduates sent home " << *maxPeople - *destination << endl;
        *destination = *maxPeople;
        }else{
        *destination += *source;
        cout << "Graduates sent home " << *source << endl;
        *source = 0;
        }
    }
};