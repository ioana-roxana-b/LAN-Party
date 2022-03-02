#include "echipa.h"

Echipa::Echipa()
{
    nr_jucatori=0;
    jucatori=NULL;
}
Echipa::Echipa(int n, string nume, Player* a)
{
    nr_jucatori=n;
    this->nume=nume;
    jucatori=NULL;
    if(jucatori)
    {
        delete []jucatori;
    }
    jucatori=new Player[n];
    for(int i=0; i<n; i++)
        jucatori[i]=a[i];
}
Echipa::~Echipa()
{
    if(jucatori)
    {
        delete []jucatori;
    }
    jucatori=NULL;
}
Echipa::Echipa(const Echipa &a)
{
    nr_jucatori=a.nr_jucatori;
    nume=a.nume;
    jucatori=NULL;
    if(jucatori)
    {
        delete []jucatori;
    }
    jucatori=new Player[a.nr_jucatori];
    for(int i=0; i<a.nr_jucatori; i++)
        jucatori[i]=a.jucatori[i];

}
Echipa &Echipa::operator=(const Echipa&a)
{
    nr_jucatori=a.nr_jucatori;
    nume=a.nume;
    jucatori=NULL;
    if(jucatori!=NULL)
    {
        delete []jucatori;
    }
    jucatori=new Player[a.nr_jucatori];
    for(int i=0; i<a.nr_jucatori; i++)
        jucatori[i]=a.jucatori[i];
    return *this;
}
ostream & operator << (ostream &dev, const Echipa &a)
{
    dev<<a.nr_jucatori<<" "<<a.nume;
    dev<<endl;
    for(int i=0; i<a.nr_jucatori; i++)
        dev<<a.jucatori[i];
    return dev;
}
istream & operator >>(istream &devi,Echipa &a)
{
    devi>>a.nr_jucatori;
    getline(devi,a.nume);
    if (a.nume[a.nume.length()-1] == ' ')
        a.nume.erase(a.nume.length()-1,a.nume.length());
    a.nume.erase(0,1);
    a.jucatori=new Player[a.nr_jucatori];
    for(int i=0; i<a.nr_jucatori; i++)
        devi>>a.jucatori[i];
    return devi;
}
double Echipa::get_points()
{
    double media=0;
    for(int i=0; i<nr_jucatori; i++)
        media+=jucatori[i].get_points();
    media=media/nr_jucatori;
    return media;
}
string Echipa::get_nume()
{
    return nume;
}
void Echipa::set_points()
{
    for(int i=0; i<nr_jucatori; i++)
    {
        jucatori[i].set_points();
    }
}
