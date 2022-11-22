#include "Buildings.h"
#include <unistd.h>

int main(){
    srand((unsigned int) clock());
    Apartament apartament;
    Colhoz colhoz;
    Fabrica fabrica;
    Gulag gulag;
    School school;
    while(1){
        //cout << "apartament1\n";
        apartament.doDuty(school.countGrajdanin());
        //cout << "school\n";
        school.doDuty(colhoz.lineup(), fabrica.lineup(), &gulag);
        //cout << "colhoz\n";
        colhoz.doDuty(*gulag.summon(), gulag.lineup());
        //cout << "fabrica\n";
        fabrica.doDuty(*gulag.summon(), gulag.lineup());
        //cout << "gulag\n";
        gulag.doDuty(colhoz.lineup());
        //cout << "apartament2\n";
        apartament.doDuty();
        cout << "maxPeople:       " << maxPeople << endl;
        cout << "totalPeople:     " << totalPeople << endl;
        cout << "toddlers:        " << apartament.toddlers() << endl;
        cout << "children:        " << school.countGrajdanin()->size() << endl;
        cout << "colhoznics:      " << colhoz.lineup()->size() << endl;
        cout << "factory workers: " << fabrica.lineup()->size() << endl;
        cout << "teacher:         " << school.teachersDay()->size() << endl;
        cout << "kgb agents:      " << gulag.summon()->size() << endl;
        cout << "guards:          " << gulag.call()->size() << endl;
        cout << "prisoners:       " << gulag.lineup()->size() << endl;
        cout << "carrots:         " << carrots << endl;
        cout << "iron:            " << iron << endl;
        cout << "product:         " << product << endl;
        cout << "cement:          " << cement << endl;
        cout << "stone:           " << stone << endl;
        cout << endl;
        usleep(1000000);

    }
    return 0;
}