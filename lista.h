#include "echipa.h"
#include <fstream>
#include <iostream>
#include <float.h>
using namespace std;
class Lista
{
private:
    Echipa team;
    Lista  *next;
public:
    Lista();
    Lista(Echipa,Lista*);
    void creare_lista(Lista **,char**);
    void afisare_nume(char**,Lista*);
    void afisare_lista(Lista*);
    void elimin_nod(Lista **,char**);
    double scor_min(Lista *);
    void afisare_ramase(Lista*,char**);
    Echipa get_team();
};

typedef class Lista element;
