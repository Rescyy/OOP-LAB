#include "Root.h"

class People : public Root{
    protected:
    int *lazy, *hunger, *unrest, *age, *deceased, *educated;
    public:
    void checkHealth(){
        if((chanceAgeDeath**age) + (chanceInfantDeath/ *age) + (*hunger / HungerFromCarrots)> rand()%100)
            *deceased = 1;
        *age += 1;
    }
    void isLazy(int workIntensity){
        if(workIntensity * (*hunger / HungerFromCarrots + 1) > rand()%100 && *lazy < LazyThreshold){
            *lazy += 1;
        }
    }
    void isUpset(){
        if(unrestHungerThreshold <= *hunger && *unrest < UnrestThreshold){
            *unrest += *hunger / HungerFromCarrots;
            if(*unrest > UnrestThreshold)*unrest = UnrestThreshold;
        }
        else if(*hunger >= pardonHungerThreshold && *unrest >= 0)
            *unrest -= 1;
    }
    void isHungry(){
        if(*hunger < HungerThreshold)
        *hunger += 1;
    }
    int isFed(int ration){
        if(ration * HungerFromCarrots > *hunger){
            ration = *hunger / HungerFromCarrots;
        }
        *hunger -= ration * HungerFromCarrots;
        return ration;
    }
    void kill(){
        *deceased = 1;
    }
    int *askForTheirAge(){
        return age;
    }
    int *checkPulse(){
        return deceased;
    }
    int *verifyDiscipline(){
        return lazy;
    }
    int *verifyLoyalty(){
        return unrest;
    }
    int *askIfTheyWannaEat(){
        return hunger;
    }
    int *askForDiploma(){
        return educated;
    }
    void enrolInSchool(){
        *educated = 1;
    }
};

class Grajdanin : public People{
    private:
    public:
    Grajdanin(){
        educated = new int;
        *educated = 0;
        lazy = new int;
        *lazy = 0;
        hunger = new int;
        *hunger = 0;
        unrest = new int;
        *unrest = 0;
        age = new int;
        *age = ageForGraduation;
        deceased = new int;
        *deceased = 0;
        title = "Grajdanin";
    }
    Grajdanin(int initage){
        educated = new int;
        *educated = 0;
        lazy = new int;
        *lazy = 0;
        hunger = new int;
        *hunger = 0;
        unrest = new int;
        *unrest = 0;
        age = new int;
        *age = initage;
        deceased = new int;
        *deceased = 0;
        title = "Grajdanin";
    }
};

class Colhoznic : public People{
    public:
    Colhoznic(Grajdanin grajdanin){
        title = "Colhoznic";
        age = grajdanin.askForTheirAge();
        deceased = grajdanin.checkPulse();
        lazy = grajdanin.verifyDiscipline();
        unrest = grajdanin.verifyLoyalty();
        hunger = grajdanin.askIfTheyWannaEat();
    }
    void doDuty(int *source, int *destination){
        *destination += *source;
        *source = 0;
    }
    float carrotProduced(){
        return (carrotProducedPerPerson*
        cutfunc(maxLazy-*lazy)*
        (maxUnrest-*unrest)*
        5*log2(*age)) / 1000;
    }
    float ironProduced(){
        return (ironProducedPerPerson*
        cutfunc(maxLazy-*lazy)*
        (maxUnrest-*unrest)*
        5*log2(*age)) / 1000;
    }
    float productProduced(){
        return (productProducedPerPerson*
        cutfunc(maxLazy-*lazy)*
        (maxUnrest-*unrest)*
        5*log2(*age)) / 1000;
    }
    float cementProduced(){
        return (cementProducedPerPerson*
        cutfunc(maxLazy-*lazy)*
        (maxUnrest-*unrest)*
        5*log2(*age)) / 1000;
    }
    float stoneProduced(){
        return (stoneProducedPerPerson*
        cutfunc(maxLazy-*lazy)*
        5*log2(*age)) / 100; 
    }
};

class Guard : public People{
    public:
    Guard(Grajdanin grajdanin){
        lazy = grajdanin.verifyDiscipline();
        unrest = grajdanin.verifyLoyalty();
        hunger = grajdanin.askIfTheyWannaEat();
        age = grajdanin.askForTheirAge();
        deceased = grajdanin.checkPulse();
        title = "Guard";
    }
};

class KGB : public People{
    public:
    KGB(Grajdanin grajdanin){
        lazy = grajdanin.verifyDiscipline();
        unrest = grajdanin.verifyLoyalty();
        hunger = grajdanin.askIfTheyWannaEat();
        age = grajdanin.askForTheirAge();
        deceased = grajdanin.checkPulse();
        title = "Secret Agent";
    }
};

class Teacher : public People{
    public:
    Teacher(Grajdanin grajdanin){
        lazy = grajdanin.verifyDiscipline();
        unrest = grajdanin.verifyLoyalty();
        hunger = grajdanin.askIfTheyWannaEat();
        age = grajdanin.askForTheirAge();
        deceased = grajdanin.checkPulse();
        title = "Teacher";
    }
};