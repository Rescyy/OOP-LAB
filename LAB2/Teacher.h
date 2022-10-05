#include <iostream>
using namespace std;

class Teacher{
    private:
    int age;
    public:
    Teacher(){
        age = 20;
    }
    void askHimAboutHisAge(){
        cout << "The teacher is " << age << " years old.";
    }
    void sendThemHome(int *source, int maxPeople, int *destination){
        int sent;
        if(*source > maxPeople - *destination){
        sent = maxPeople - *destination;
        *source -= sent;
        *destination = sent;
        }else{
        *destination += *source;
        *source = 0;
        }
    }
};
