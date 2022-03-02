#include "echipa.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class BST
{
    Echipa team;
    BST *l,*r;
public:
    BST* creare_bst(Echipa);
    BST* insert(BST*, Echipa);
    void afisare(char**,BST*);
    void afisare_fisier(ostream&,BST* );
};

