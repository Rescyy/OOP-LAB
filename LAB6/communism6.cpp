#include "controller/controller.h"
#include <unistd.h>

int main(){
    srand((unsigned int) clock());
    while(1){
        moveTime();
        displayInformation();
        usleep(1000000);
    }
    return 0;
}