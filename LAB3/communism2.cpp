#include <iostream>
#include "Buildings.h"
#include "People.h"
#include <unistd.h>
using namespace std;

int main(){
    srand((unsigned int) clock());
    Apartament apartament;
    Colhoz colhoz;
    Colhoznic colhoznic;
    Fabrica fabrica;
    Grajdanin grajdanin;
    Guard guard;
    Gulag gulag;
    KGB kgb;
    School school;
    Teacher teacher;
    while(1){
        apartament.makeChildren();
        apartament.sendToColhoz(colhoz.checkonPeople());
        apartament.sendToFabrica(fabrica.checkonPeople());
        colhoz.growCarrots();
        colhoz.mineIron();
        kgb.fireColhoznic(gulag.checkonPeople(), colhoz.checkonPeople(), colhoz.lineupTheLazy(), colhoz.askForTheirTitle());
        colhoznic.deliverProducts(colhoz.countCarrots(), apartament.checkCarrotsAmmount());
        colhoznic.deliverProducts(colhoz.weighIron(), fabrica.weighIron());
        fabrica.craftProduct();
        kgb.fireColhoznic(gulag.checkonPeople(), fabrica.checkonPeople(), fabrica.lineupTheLazy(), fabrica.askForTheirTitle());
        grajdanin.growChildren(apartament.countChildren(), apartament.countToddlers());
        grajdanin.sendChildrenToSchool(apartament.countChildren(), school.countChildren());
        school.educateChildren();
        teacher.sendThemHome(school.checkonPeople(), apartament.inspectApartmentCapacity(), apartament.checkonPeople());
        gulag.gatherStone();
        colhoznic.deliverProducts(gulag.countStone(), fabrica.weighStone());
        fabrica.craftCement();
        colhoznic.deliverProducts(fabrica.organizeProduct(), apartament.checkProductAmmount());
        colhoznic.deliverProducts(fabrica.packCement(), apartament.checkCementAmmount());
        guard.killPrisoner(gulag.checkonPeople(), gulag.lineupTheLazy());
        apartament.expandApartment();
        apartament.print();
        apartament.printmax();
        colhoz.print();
        gulag.print();
        fabrica.print();
        cout << endl << endl;
        usleep(1000000);
    }
    return 0;
}