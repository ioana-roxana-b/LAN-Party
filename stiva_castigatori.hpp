#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "echipa.h"
using namespace std;
class castigator
{
    Echipa team;
    castigator *next;
public:
    castigator();
    castigator(Echipa,castigator*);
    void make_castigatori(castigator**,Echipa);
    void afisare(char**,castigator*,int);
    void afisare_echipe(ostream&,class castigator*);
    void sterge_stiva(castigator **);
};
