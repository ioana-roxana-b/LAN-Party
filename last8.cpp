#include "last8.hpp"
using namespace std;

void last8 ::creare_lista( last8 **head)
{
    ifstream d("castigatori.out",ios::in);
    (*head)=NULL;
    last8 *p;
    (*head)=new last8;
    (*head)->next=NULL;
    Echipa *a;
    a=new Echipa[8];
    for(int i=0; i<8; i++)
    {
        p = new last8;
        d>> a[i];
        p->next =  (*head);
        p->team = a[i];
        (*head) = p;
    }
    d.close();
}
void last8::afisare_nume(ostream &devo, last8 *head)
{

    if(head!=NULL)
        while(head->next!=NULL)
        {
            devo<<head->team.get_nume()<<endl;
            head=head->next;
        }
}
void last8::afisare_lista(ostream &devo,last8*head)
{
    if(head!=NULL)
        while(head->next!=NULL)
        {
            devo<<head->team<<endl;
            head=head->next;
        }

}
Echipa last8::get_team()
{
    return team;
}
class last8 *last8::get_next()
{
    return next;
}

