#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "echipa.h"
using namespace std;

class coada_meciuri
{
    Echipa team;
    coada_meciuri *next;
public:
    coada_meciuri();
    coada_meciuri(Echipa,coada_meciuri*);
    ~coada_meciuri();
    void make_coada(coada_meciuri**,coada_meciuri**,Echipa);
    void afisare(char**,coada_meciuri*,int);
    class coada_meciuri *get_next();
    Echipa get_team();
    Echipa get_next_team();
    void set_points(coada_meciuri**);
};
