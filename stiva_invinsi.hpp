#include <iostream>
#include <fstream>
#include <string>
#include "echipa.h"
using namespace std;
class invins
{
    Echipa team;
    invins *next;
public:
    invins();
    invins(Echipa,invins*);
    void make_invinsi(invins**,Echipa);
    void afisare(char**,invins*);
    void sterge_stiva(invins**);

};
