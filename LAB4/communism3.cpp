#include "Root.h"
#include <unistd.h>

int main(){
    srand((unsigned int) clock());
    Apartament apartament;
    Colhoz colhoz;
    Colhoznic colhoznic;
    Fabrica fabrica;
    Grajdanin grajdanin;
    Gulag gulag;
    Guard guard(gulag.lineupTheLazy(), gulag.report("people"));
    KGB kgb;
    School school;
    Teacher teacher;
    while(1){
        apartament.doDuty(colhoz.report("people"), fabrica.report("people"));
        colhoz.doDuty();
        kgb.doDuty(gulag.report("people"), colhoz.report("people"), colhoz.lineupTheLazy(), colhoz.askForTheTitle());
        colhoznic.doDuty(colhoz.report("carrots"), apartament.report("carrots"));
        colhoznic.doDuty(colhoz.report("iron"), fabrica.report("iron"));
        kgb.doDuty(gulag.report("people"), fabrica.report("people"), fabrica.lineupTheLazy(), fabrica.askForTheTitle());
        grajdanin.doDuty(apartament.report("toddlers"), apartament.report("children"), school.report("children"));
        school.doDuty();
        teacher.doDuty(school.report("people"), apartament.report("maxPeople"), apartament.report("people"));
        gulag.doDuty();
        colhoznic.doDuty(gulag.report("stone"), fabrica.report("stone"));
        fabrica.doDuty();
        colhoznic.doDuty(fabrica.report("product"), apartament.report("product"));
        colhoznic.doDuty(fabrica.report("cement"), apartament.report("cement"));
        guard.doDuty();
        apartament.expandApartment();
        colhoz.print();
        gulag.print();
        fabrica.print();
        cout << endl << endl;
        usleep(250000);
    }
    return 0;
}