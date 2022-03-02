#include <string>
#include <iostream>
using namespace std;

class Player
{
private:
    string firstName;
    string secondName;
    int points;
public:
    Player();
    Player(string,string,int);
    ~Player();
    friend ostream & operator << (ostream &, const Player &);
    friend istream & operator>>(istream &,Player &);
    int get_points();
    void set_points();
};