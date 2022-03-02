#include "lista.h"
Lista::Lista()
{
    next=NULL;
}
Lista::Lista(Echipa echipa,Lista*n)
{
    team=echipa;
    next=NULL;
    if(next)
    {
        delete next;
    }
    next=new Lista;
    next=n;
}
void Lista::creare_lista(Lista **head,char **argv)
{
    ifstream d(argv[2],ios::in);
    (*head)=NULL;
    Lista *p;
    (*head)=new Lista;
    (*head)->next=NULL;
    Echipa *a;
    int nr_echipe;
    d>>nr_echipe;
    a=new Echipa[nr_echipe];
    for(int i=0; i<nr_echipe; i++)
    {
        p = new Lista;
        d>> a[i];
        p->next =  (*head);
        p->team = a[i];
        (*head) = p;
    }
    d.close();
}
void Lista::afisare_nume(char**argv,Lista *head)
{
    ofstream r(argv[3],ios::out);
    if(head!=NULL)
        while(head->next!=NULL)
        {
            r<<head->team.get_nume()<<endl;
            head=head->next;
        }
    r.close();
}
void Lista::afisare_lista(Lista *head)
{
    ofstream out("date_coada.out",ios::app);
    while(head->next!=NULL)
    {
        out<<head->team<<endl;
        head=head->next;
    }
    out.close();
}
double Lista::scor_min(Lista *head)
{

    double minim=DBL_MAX;
    while(head!=NULL)
    {
        if (head->team.get_points() < minim)
        {
            minim = head->team.get_points();
        }
        head = head->next;
    }
    return minim;
}
int putere(int n)
{
    int putere_max=1;
    while(putere_max<=n)
    {
        putere_max=putere_max*2;
    }
    putere_max=putere_max/2;
    return putere_max;
}
void Lista::elimin_nod(Lista **head,char**argv)
{
    int nr_echipe;
    ifstream d(argv[2], ios::in);
    d>>nr_echipe;
    int k=putere(nr_echipe);
    Lista* temp1;
    Lista* temp2;
    while(nr_echipe!=k)
    {
        if(*head!=NULL)
        {
            temp1 = *head;
            while (temp1->team.get_points() != scor_min(temp1))
            {
                temp2 = temp1;
                temp1 = temp1->next;
            }
            if (temp1 == *head)
            {
                *head = (*head)->next;
                delete temp1;
            }
            else
            {
                if (temp1->next == NULL)
                {
                    delete temp1;
                }

                else
                {
                    temp2->next = temp1->next;
                    delete temp1;
                }
            }
        }
        nr_echipe--;
    }
    ofstream out("date_coada.out",ios::out);
    out<<nr_echipe<<endl;
    out.close();
}
void Lista::afisare_ramase(Lista*head,char**argv)
{
    ofstream r(argv[3],ios::out);
    elimin_nod(&head,argv);
    afisare_lista(head);
    while(head->next!=NULL)
    {
        r<<head->team.get_nume()<<endl;
        head=head->next;
    }
}
Echipa Lista::get_team()
{
    return team;
}
