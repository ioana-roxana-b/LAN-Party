#include "player.h"

Player::Player()
{
    points=0;
}
Player::Player(string firstName, string secondName, int points)
{
    this->firstName=firstName;
    this->secondName=secondName;
    this->points=points;
}
Player::~Player()
{
}
ostream & operator << (ostream & dev, const Player &a)
{
    dev<<a.firstName<<" "<<a.secondName<<" "<<a.points<<endl;
    return dev;
}
istream & operator>>(istream & devi,Player &a)
{
    devi>>a.firstName;
    devi>>a.secondName;
    devi>>a.points;
    return devi;
}
int Player::get_points()
{
    return points;
}
void Player::set_points()
{
    points=points+1;
}