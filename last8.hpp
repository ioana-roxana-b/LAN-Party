#include "echipa.h"
#include <iostream>
#include <float.h>
#include <fstream>
using namespace std;
class last8
{
private:
    Echipa team;
    class last8  *next;
public:
    void creare_lista(last8 **);
    static void afisare_nume(ostream &,last8*);
    void afisare_lista(ostream &,last8*);
    Echipa get_team();
    last8 *get_next();
};
