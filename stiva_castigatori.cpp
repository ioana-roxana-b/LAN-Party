#include "stiva_castigatori.hpp"

castigator::castigator()
{
    next=NULL;
}
castigator::castigator(Echipa echipa,castigator*n)
{
    team=echipa;
    next=NULL;
    if(next)
    {
        delete next;
    }
    next=n;
}
void castigator::make_castigatori(castigator** head,Echipa l)
{
    castigator* newNode=new castigator ;
    newNode->team=l;
    newNode->next=*head;
    *head=newNode;
}
void castigator::afisare(char**argv,castigator*head,int j)
{
    ofstream r(argv[3],ios::app);
    r<<"WINNERS OF ROUND NO:"<<j<<endl;
    while(head!=NULL)
    {
        r<<left<<setw(33)<<head->team.get_nume()<<" -  "<<fixed<<setprecision(2)<<head->team.get_points()<<endl;
        head=head->next;
    }
    r.close();
}
void castigator::afisare_echipe(ostream&devo,castigator* head)
{
    while(head!=NULL)
    {
        devo<<head->team<<endl;
        head=head->next;
    }
    devo<<endl;
}
void castigator::sterge_stiva(castigator **top)
{
    castigator *temp;
    while (*top!=NULL)
    {
        temp=(*top);
        *top=(*top)->next;
        delete temp;
        temp=NULL;
    }
}
