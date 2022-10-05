#include <iostream>
using namespace std;

class School{
    private:
    int people, children;
    public:
    School(){
        people = children = 0;
    }
    void educateChildren(){
        people += children;
        children = 0;
    }
    int *enrolChildren(){
        return &children;
    }
    int *graduatePeople(){
        return &people;
    }
};
