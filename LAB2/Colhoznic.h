#include <iostream>
using namespace std;

class Colhoznic{
    private:
    int age;
    public:
    Colhoznic(){
        age = 20;
    }
    void deliverProducts(int *source, int *destination){
        *destination += *source;
        *source = 0;
        age++;
    }
    void askHimAboutHisAge(){
        cout << "The colhoznic is " << age << " years old.";
    }
};
