#include <math.h>
#include <iostream>
#include <array>
#include "parameters.h"
#include <vector>
using namespace std;

int minint(int a, int b){
    if(a > b)
    return b;
    return a;
}

int cutfunc(int a){
    if(a < 0) return 0;
    else return a;
}

void randomEvent(){
    
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