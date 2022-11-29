#include "model/model.h"
#include "view/view.h"

void moveTime(){
    apartament.doDuty(school.countGrajdanin());
    school.doDuty(colhoz.lineup(), fabrica.lineup(), &gulag);
    colhoz.doDuty(*gulag.summon(), gulag.lineup());
    fabrica.doDuty(*gulag.summon(), gulag.lineup());
    gulag.doDuty(colhoz.lineup());
    apartament.doDuty();
}