#include <iostream>
using namespace std; 

class Guard{
    private:
    int age;
    public:
    Guard(){
        age = 20;
    }
    void killPrisoner(int *prisoners, int *lazy){
        cout << *lazy << " prisoners were executed due to their laziness." << endl;
        *prisoners -= *lazy;
        *lazy = 0;
        age++;
    }
    void askHimAboutHisAge(){
        cout << "The guard is " << age << " years old.";
    }
};