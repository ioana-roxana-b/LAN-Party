#include <iostream>
#include <string>
#include <algorithm>
#pragma once
#include "player.h"
using namespace std;

class Echipa
{
private:
    int nr_jucatori;
    string nume;
    Player *jucatori;
public:
    Echipa();
    Echipa(int, string, Player*);
    ~Echipa();
    Echipa(const Echipa &);
    Echipa &operator=(const Echipa&);
    friend ostream & operator << (ostream &, const Echipa &);
    friend istream & operator >>(istream &, Echipa &);
    double get_points();
    void set_points();
    string get_nume();
};
