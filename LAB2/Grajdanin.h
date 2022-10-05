#include <iostream>
using namespace std;

class Grajdanin{
    private:
    int age;
    public:
    Grajdanin(){
        age = 20;
    }
    void growChildren(int *children, int *toddlers){
        *children += *toddlers;
        *toddlers = 0;
    }
    void askHimAboutHisAge(){
        cout << "This grajdanin is" << age << "years old.";
    }
    void transportChildren(int *source, int *destination){
        *destination += *source;
        *source = 0;
    }
};
