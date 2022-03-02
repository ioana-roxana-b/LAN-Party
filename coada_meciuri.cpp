#include "coada_meciuri.hpp"

coada_meciuri::coada_meciuri()
{
    next=NULL;
}
coada_meciuri::coada_meciuri(Echipa a,coada_meciuri*n)
{
    team=a;
    next=NULL;
    if(next)
    {
        delete next;
    }
    next=new coada_meciuri;
    next=n;

}
coada_meciuri::~coada_meciuri()
{
    if(next)
    {
        delete next;
    }
    next=NULL;
}
void coada_meciuri::make_coada(coada_meciuri **head,coada_meciuri **tail,Echipa l)
{
    coada_meciuri *p=new coada_meciuri;
    p->team=l;
    if(*head==NULL)
    {
        p->next=NULL;
        *head=*tail=p;
    }
    else
    {
        p->next=NULL;
        (*tail)->next=p;
        *tail=p;
    }
}
void coada_meciuri::afisare(char**argv,coada_meciuri *head,int i)
{
    ofstream r(argv[3], ios::out | ios::app);
    r<<endl<<"--- ROUND NO:"<<i<<endl;
    while(head!=NULL)
    {
        r<<left<<setw(33)<<head->team.get_nume()<<"-"<<right<<setw(33)<<head->next->team.get_nume()<<endl;
        head=head->next->next;
    }
    r<<endl;
    r.close();
}
Echipa coada_meciuri::get_team()
{
    return team;
}
Echipa coada_meciuri::get_next_team()
{
    return next->team;
}
class coada_meciuri *coada_meciuri::get_next()
{
    return next;
}
void coada_meciuri::set_points(coada_meciuri**a)
{
    (*a)->team.set_points();
}
