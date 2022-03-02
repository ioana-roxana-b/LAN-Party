#include "stiva_invinsi.hpp"
invins::invins()
{
    next=NULL;
}
invins::invins(Echipa echipa,invins*n)
{
    team=echipa;
    next=NULL;
    if(next)
    {
        delete next;
    }
    next=n;
}
void invins::make_invinsi(invins** head,Echipa l)
{
    invins * newNode=new invins;
    newNode->team=l;
    newNode->next=*head;
    *head=newNode;
}
void invins::afisare(char**argv,invins*head)
{
    ofstream r(argv[3],ios::out);
    //devo<<"Invinsi: "<<endl;
    if(head!=NULL)
        while(head!=NULL)
        {
            r<<head->team.get_nume()<<endl;
            head=head->next;
        }
    r<<endl;
    r.close();
}
void invins::sterge_stiva(invins **top)
{
    invins *temp;
    while (*top!=NULL)
    {
        temp=(*top);
        *top=(*top)->next;
        delete temp;
        temp=NULL;
    }
}
