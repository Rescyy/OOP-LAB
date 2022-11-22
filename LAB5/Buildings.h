#include "People.h"

class Buildings : public Root{
    protected:
    int people;
    public:
};

class Economy : public Buildings{
    protected:
    vector<Colhoznic> colhoznic;
    public:
    virtual void deleteRecords(){
        if(colhoznic.size()){
            auto vec = colhoznic.begin();
            while(vec != colhoznic.end()){
                if(*vec->checkPulse()){
                    colhoznic.erase(vec);
                }else
                vec++;
            }
        }
    }
    virtual void sendToGulag(vector<KGB> kgb, vector<Colhoznic> *prisoners){
        int t, i = 0;
        auto vec1 = colhoznic.begin();
        if(kgb.size())
        for(auto vec3 = kgb.begin(); vec3 != kgb.end(); vec3++){
            t = prisonersSentPerKGB;
            if(vec1 == colhoznic.end())break;
            while(t && colhoznic.end() != vec1){
                if(unrestLimitToGulag < *vec1->verifyLoyalty() || lazyLimitToGulag < *vec1->verifyDiscipline()){
                    *vec1->verifyDiscipline() = 0;
                    prisoners->push_back(*vec1);
                    i++;
                    colhoznic.erase(vec1);
                    t--;
                }else
                vec1++;
            }
        }
        if(i)
        cout << i << " people have been sent to gulag\n";
    }
    vector<Colhoznic> *lineup(){
        return &colhoznic;
    }
};

class Gulag : public Economy{
    private:
    vector<Guard> guard;
    vector<KGB> kgb;
    public:
    Gulag(){
        title = "Gulag";
    }
    void produceStone(){
        float init = stone;
        for(auto vec = colhoznic.begin(); vec != colhoznic.end(); vec++){
            stone += vec->stoneProduced();
            vec->isLazy(stoneProductionIntensity);
        }
        if(stone - init)
        cout << stone - init << " stone has been produced\n";
    }
    void deleteRecords(){
        auto vec1 = colhoznic.begin();
        while(vec1 != colhoznic.end()){
            if(*vec1->checkPulse()){
                colhoznic.erase(vec1);
            }else
            vec1++;
        }
        auto vec2 = guard.begin();
        while(vec2 != guard.end()){
            if(*vec2->checkPulse()){
                guard.erase(vec2);
            }else
            vec2++;
        }
        auto vec3 = kgb.begin();
        while(vec3 != kgb.end()){
            if(*vec3->checkPulse()){
                kgb.erase(vec3);
            }else
            vec3++;
        }
    }
    void increaseDemandForPrisoners(vector<Colhoznic> *lcolhoznic){
        if(product < cement){
            unrestLimitToGulag++;
            lazyLimitToGulag++;
        }else{
            unrestLimitToGulag--;
            lazyLimitToGulag--;
        }
    }
    void executeUseless(){
        int i = 0;
        for(auto vec = colhoznic.begin(); vec != colhoznic.end(); vec++){
            if(*vec->verifyDiscipline() >= lazyExecutionLimit){
                vec->kill();
                i++;
            }
        }
        if(i)
        cout << i << " people have been executed in gulag\n";
    }
    void doDuty(vector<Colhoznic> *lcolhoznic){
        //cout << "deleteRecords\n";
        deleteRecords();
        //cout << "produceStone\n";
        produceStone();
        //cout << "executeUseless\n";
        executeUseless();
        //cout << "increaseDemandForPrisoners\n";
        increaseDemandForPrisoners(lcolhoznic);
    }
    vector<Guard> *call(){
        return &guard;
    }
    vector<KGB> *summon(){
        return &kgb;
    }
};

class Colhoz : public Economy{
    public:
    Colhoz(){
        title = "Colhoz";
    }
    void produceCarrots(){
        float init = carrots;
        for(auto vec = colhoznic.begin(); vec != colhoznic.end(); vec++){
            if(carrots)
            carrots += vec->carrotProduced();
            vec->isLazy(carrotProductionIntensity);
            vec->isUpset();
        }
        if(carrots-init)
        cout << carrots - init << " carrots have been grown\n";
    }
    void produceIron(){
        float init = iron;
        for(auto vec = colhoznic.begin(); vec != colhoznic.end(); vec++){
            iron += vec->ironProduced();
            vec->isLazy(ironProductionIntensity);
            vec->isUpset();
        }
        if(iron-init)
        cout << iron - init << " iron has been mined\n";
    }
    void doDuty(vector<KGB> kgb, vector<Colhoznic> *prisoners){
        //cout << "deleteRecords\n";
        deleteRecords();
        if(colhoznic.size()){
            if(totalPeople > carrots / HungerFromCarrots || product > cement){
                //cout << "produceCarrots\n";
                produceCarrots();
            }
            else{
                //cout << "produceIron\n";
                produceIron();
            }
            //cout << "sendToGulag\n";
            sendToGulag(kgb, prisoners);
        }
    }
};

class Fabrica : public Economy{
    public:
    Fabrica(){
        title = "Fabrica";
    }
    void produceProduct(){
        float temp, init = product;
        for(auto vec = colhoznic.begin(); vec != colhoznic.end(); vec++){
            temp = vec->productProduced();
            if(temp*ironForProduct <= iron){
                iron -= temp*ironForProduct;
                product += temp*ironForProduct;
                vec->isLazy(productProductionIntensity);
                vec->isUpset();
            }
        }
        if(product-init)
        cout << product - init << " products have been produced\n";
    }
    void produceCement(){
        float temp, init = cement;
        for(auto vec = colhoznic.begin(); vec != colhoznic.end(); vec++){
            temp = vec->cementProduced();
            if(temp*stoneForCement <= stone){
                stone -= temp*stoneForCement;
                cement += temp*stoneForCement;
                vec->isLazy(cementProductionIntensity);
                vec->isUpset();
            }
        }
        if(cement-init)
        cout << cement - init << " cement has been produced\n";
    }
    void doDuty(vector<KGB> kgb, vector<Colhoznic> *prisoners){
        //cout << "deleteRecords\n";
        deleteRecords();
        if(iron > stone){
            //cout << "produceProduct\n";
            produceProduct();
        }else{
        //cout << "produceCement\n";
        produceCement();
        }
        //cout << "sendToGulag\n";
        sendToGulag(kgb, prisoners);
    }
};

class Civil : public Buildings{
    protected:
    vector<Grajdanin> grajdanin;
    public:
    vector<Grajdanin> *countGrajdanin(){
        return &grajdanin;
    }
};

class Apartament : public Civil{
    private:
    public:
    Apartament(){
        grajdanin.resize(initialPopulation);
        title = "Apartament";
    }
    void feedPeople(){
        int init = carrots;
        int ration = carrots / totalPeople;
        if(ration == 0)return;
        for(auto vec = grajdanin.begin(); vec != grajdanin.end(); vec++){
            carrots -= vec->isFed(ration);
        }
    }
    void expandApartment(){
        float costProduct = (pow((maxPeople - 2*initialPopulation) / 10, apartamentCostBase) * productApartament);
        float costCement = (pow((maxPeople - 2*initialPopulation) / 10, apartamentCostBase) * cementApartament);
        if(product > costProduct && cement > costCement){
            product -= costProduct;
            cement -= costCement;
            maxPeople += 10;
            cout << "The apartament has been expanded to " << maxPeople << " max capacity\n";
        }
    }
    void reproduce(){
        int eligible = 0;
        for(auto vec = grajdanin.begin(); vec != grajdanin.end(); vec++){
            if(*vec->askForTheirAge() >= ageForGraduation && *vec->askIfTheyWannaEat() == 0)
                eligible++;
        }
        int min = minint(eligible/2, maxPeople - totalPeople);
        for(int i = 0; i < min; i++){
            grajdanin.push_back(Grajdanin(1));
        }
        totalPeople += min;
        if(min)
        cout << min << " people have been born this year\n";
    }
    void sendToSchool(vector<Grajdanin>* ucenik){
        int i = 0;
        for(auto vec = grajdanin.begin(); vec != grajdanin.end(); vec++){
            if(*vec->askForTheirAge() <= ageForGraduation &&
            *vec->askForTheirAge() >= ageForSchool &&
            !*vec->askForDiploma()){
                vec->enrolInSchool();
                ucenik->push_back(*vec);
                i++;
            }
        }
        if(i)
        cout << i << " pupils were sent to school\n";
    }
    void buryDead(){
        int init = grajdanin.size();
        auto vec = grajdanin.begin();
        while(vec != grajdanin.end()){
            if(*vec->checkPulse()){
                grajdanin.erase(vec);
            }else
            vec++;
        }
        if(init - grajdanin.size())
        cout << init - grajdanin.size() << " people died this year\n";
        totalPeople = grajdanin.size();
    }
    void burnCalories(){
        for(auto vec = grajdanin.begin(); vec != grajdanin.end(); vec++){
            vec->isHungry();
        }
    }
    void checkPopulationHealth(){
        for(auto vec = grajdanin.begin(); vec != grajdanin.end(); vec++){
            vec->checkHealth();
        }
    }
    int toddlers(){
        int i = 0;
        for(auto vec = grajdanin.begin(); vec != grajdanin.end(); vec++){
            if(*vec->askForTheirAge() < ageForSchool)i++;
        }
        return i;
    }
    void doDuty(vector<Grajdanin> *ucenik){
        //report();
        //cout << "buryDead\n";
        buryDead();
        //cout << "reproduce\n";
        reproduce();
        //cout << "sendToSchool\n";
        sendToSchool(ucenik);
        //cout << "burnCalories\n";
        burnCalories();
        //cout << "feedPeople\n";
        feedPeople();
        //cout << "checkPopulationHealth\n";
        checkPopulationHealth();
    }
    void doDuty(){
        //cout << "expandApartment\n";
        expandApartment();
    }
};

class School : public Civil{
    private:
    vector<Teacher> teacher;
    public:
    School(){
        title = "School";
    }
    void teachStudents(){
        int t;
        auto vec1 = grajdanin.begin();
        for(auto vec2 : teacher){
            t = studentsTaughtPerTeacher;
            while(t && vec1 != grajdanin.end()){
                t--;
                vec1->isLazy(learningIntensity);
                vec1->isUpset();
                *vec1->verifyDiscipline() -= 1;
                *vec1->verifyLoyalty() -= 1;
                vec1++;
            }
        }
    }
    int randomChoice(){
        int ran = rand()%tot;
        if(ran < chanceForColhoz){
            return 0;
        }
        ran -= chanceForColhoz;
        if(ran < chanceForFabrica){
            return 1;
        }
        ran -= chanceForFabrica;
        if(ran < chanceForGuard){
            return 2;
        }
        ran -= chanceForGuard;
        if(ran < chanceForKGB){
            return 3;
        }
        return 4;
    }
    void deleteRecords(){
        auto vec1 = grajdanin.begin();
        while(vec1 != grajdanin.end()){
            if(*vec1->checkPulse()){
                grajdanin.erase(vec1);
            }else
            vec1++;
        }
        auto vec2 = teacher.begin();
        while(vec2 != teacher.end()){
            if(*vec2->checkPulse()){
                teacher.erase(vec2);
            }else
            vec2++;
        }
    }
    void report(){
        for(auto vec = grajdanin.begin(); vec != grajdanin.end(); vec++){
            cout << "School " << *vec->askForTheirAge() << " "
            << *vec->verifyDiscipline() << " "
            << *vec->verifyLoyalty() << " "
            << *vec->askIfTheyWannaEat() << endl;
        }
    }
    void doDuty(vector<Colhoznic> *colhoz, vector<Colhoznic> *fabrica, Gulag *gulag){
        //report();
        //cout << "deleteRecords\n";
        deleteRecords();
        int ran, i = 0;
        auto vec = grajdanin.begin();
        //cout << "teachStudents\n";
        teachStudents();
        //cout << "graduateStudents\n";
        while(vec != grajdanin.end()){
            if(*vec->askForTheirAge() > ageForGraduation){
                i++;
                ran = randomChoice();
                if(!gulag->summon()->size())ran = 3;
                if(ran == 0){
                    colhoz->push_back(Colhoznic(*vec));
                    //cout << " toColhoz ";
                }
                if(ran == 1){
                    fabrica->push_back(Colhoznic(*vec));
                    //cout << " toFabrica ";
                }
                if(ran == 2){
                    gulag->call()->push_back(Guard(*vec));
                    //cout << " toGulag ";
                }
                if(ran == 3){
                    gulag->summon()->push_back(KGB(*vec));
                    //cout << " toKGB ";
                }
                if(ran == 4){
                    //cout << " toTeacher ";
                    teacher.push_back(Teacher(*vec));
                }
                grajdanin.erase(vec); 
            }else
            vec++;
        }
        if(i)
        cout << i << " students graduated school\n";
    }
    vector<Teacher> *teachersDay(){
        return &teacher;
    }
};