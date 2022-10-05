#include <iostream>
using namespace std;

class KGB{
    private:
    int age;
    public:
    KGB(){
        age = 20;
    }
    void fireColhoznicFromFabrica(int *gulag, int *people, int *lazy){
        *people -= *lazy;
        cout << "These " << *lazy << " fabrica colhoznics were lazy, a horrible fate awaits them." << endl;
        *gulag += *lazy;
        *lazy = 0;
    }
    void fireColhoznicFromColhoz(int *gulag, int *people, int *lazy){
        *people -= *lazy;
        cout << "These " << *lazy << " colhozn colhoznics were lazy, a horrible fate awaits them." << endl;
        *gulag += *lazy;
        *lazy = 0;
    }
    void askHimAboutHisAge(){
        cout << "The secret agent cannot disclose that information" << endl;
    }
};
