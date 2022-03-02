#include "echipa.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
class AVL
{
    int h;
    Echipa team;
    struct AVL *l,*r;
public:
    int Height(AVL* );
    AVL *RightRotation( AVL *);
    AVL *LeftRotation(AVL *);
    AVL* LRRotation(AVL*Z);
    AVL* RLRotation(AVL*Z);
    AVL* insert(AVL*, Echipa);
    void afisare(char**,AVL*,int);
    friend int max(int,int);

};
