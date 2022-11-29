void displayInformation(){
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
}