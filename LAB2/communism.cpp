#include <iostream>
#include <unistd.h>
#include "Colhoz.h"
#include "Fabrica.h"
#include "Apartament.h"
#include "Colhoznic.h"
#include "Gulag.h"
#include "Grajdanin.h"
#include "KGB.h"
#include "Guard.h"
#include "Teacher.h"
#include "School.h"
using namespace std;

int main(){
    srand((unsigned int) clock());
    Apartament apartament = Apartament();
    Colhoz colhoz = Colhoz();
    Colhoznic colhoznic = Colhoznic();
    Fabrica fabrica = Fabrica();
    Grajdanin grajdanin = Grajdanin();
    Guard guard = Guard();
    Gulag gulag = Gulag();
    KGB kgb = KGB();
    School school = School();
    Teacher teacher = Teacher();
    while(1){
        apartament.makeChildren();
        apartament.sendToColhoz(colhoz.checkOnPeople());
        apartament.sendToFabrica(fabrica.checkOnPeople());
        colhoz.growCarrots();
        colhoz.mineIron();
        kgb.fireColhoznicFromColhoz(gulag.lineupPrisoners(), colhoz.checkOnPeople(), colhoz.lineupTheLazy());
        colhoznic.deliverProducts(colhoz.countCarrots(), apartament.checkCarrotsAmmount());
        colhoznic.deliverProducts(colhoz.countIron(), fabrica.weighIron());
        fabrica.craftProduct();
        kgb.fireColhoznicFromFabrica(gulag.lineupPrisoners(), fabrica.checkOnPeople(), fabrica.lineupTheLazy());
        grajdanin.growChildren(apartament.countChildren(), apartament.countToddlers());
        grajdanin.transportChildren(apartament.countChildren(), school.enrolChildren());
        school.educateChildren();
        grajdanin.transportChildren(school.graduatePeople(), apartament.checkonPeople());
        gulag.gatherStone();
        colhoznic.deliverProducts(gulag.countStone(), fabrica.weighStone());
        fabrica.craftCement();
        colhoznic.deliverProducts(fabrica.organizeProduct(), apartament.checkProductAmmount());
        colhoznic.deliverProducts(fabrica.packCement(), apartament.checkCementAmmount());
        guard.killPrisoner(gulag.lineupPrisoners(), gulag.prepareTheLazy());
        apartament.expandApartment();
        apartament.print();
        colhoz.print();
        gulag.print();
        fabrica.print();
        cout << endl << endl;
        usleep(1000000);
    }
    return 0;
}