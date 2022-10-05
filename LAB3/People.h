#include <iostream>
using namespace std;

class People{
    protected:
    int age;
    char *title;
    public:
    void askThemAboutTheirAge(){
        cout << "The " << title << " is " << age << " years old." << endl;
    }
    char *askForTheirTitle(){
        return title;
    }
};

class Colhoznic : public People{
    public:
    Colhoznic(){
        age = 20;
        title = (char*) malloc(11*sizeof(char));
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
        title = (char*) malloc(11*sizeof(char));
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
        title = (char*) malloc(13*sizeof(char));
        title = "Secret Agent";
    }
    void fireColhoznic(int *gulag, int *people, int *lazy, char *title){
        *people -= *lazy;
        cout << *lazy << " " << title << " colhoznics were lazy, a horrible fate awaits them." << endl;
        *gulag += *lazy;
        *lazy = 0;
    }
};

class Teacher : public People{
    public:
    Teacher(){
        title = (char*) malloc(11*sizeof(char));
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