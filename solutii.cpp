#include "solutii.hpp"

void cerinta3(char**argv,last8 *&last)
{
    int nr_echipe;
    Echipa l, winner;
    coada_meciuri *head = NULL, *tail = NULL, aux, *adresa = NULL;
    castigator *win = NULL, aux2;
    invins *lose = NULL, aux3;
    int iter = 2, j = 2;
    last8 auxlast;
    ifstream fin("date_coada.out", ios::in);
    fin >> nr_echipe;
    for (int i = 0; i < nr_echipe; i++)
    {
        fin >> l;
        aux.make_coada(&head, &tail, l);
    }
    aux.afisare(argv, head, 1);
    for (int i = 0; i < nr_echipe; i++)
    {
        if (head != NULL)
        {
            if ((head->get_team()).get_points() > (head->get_next_team()).get_points())
            {
                aux.set_points(&head);
                aux2.make_castigatori(&win, head->get_team());
                aux3.make_invinsi(&lose, head->get_next_team());
            }
            else if (((head->get_team()).get_points() <= (head->get_next_team()).get_points()))
            {
                aux3.make_invinsi(&lose, head->get_team());
                adresa = head->get_next();
                aux.set_points(&adresa);
                aux2.make_castigatori(&win, head->get_next_team());
            }
            head = head->get_next()->get_next();
        }
        nr_echipe = nr_echipe - 1;
    }
    aux2.afisare(argv, win, 1);
    aux3.sterge_stiva(&lose);
    ofstream out("castigatori.out", ios::out);
    aux2.afisare_echipe(out, win);
    out.close();
    while (nr_echipe != 1)
    {
        if(nr_echipe == 8)
        {
            auxlast.creare_lista(&last);
        }
        ifstream in("castigatori.out", ios::in);
        if (!in)
            cout << "Eroare la deschidere!" << endl;
        for (int i = 0; i < nr_echipe; i++)
        {
            in >> winner;
            aux.make_coada(&head, &tail, winner);
        }
        in.close();
        aux.afisare(argv, head, iter);
        iter++;
        aux2.sterge_stiva(&win);
        for (int j = 0; j < nr_echipe; j++)
        {
            if (head != NULL)
            {
                if ((head->get_team()).get_points() > (head->get_next_team()).get_points())
                {
                    aux.set_points(&head);
                    aux2.make_castigatori(&win, head->get_team());
                    aux3.make_invinsi(&lose, head->get_next_team());
                }
                else if (((head->get_team()).get_points() <= (head->get_next_team()).get_points()))
                {
                    aux3.make_invinsi(&lose, head->get_team());
                    adresa = head->get_next();
                    aux.set_points(&adresa);
                    aux2.make_castigatori(&win, head->get_next_team());
                }
                head = head->get_next()->get_next();
            }
        }
        ofstream out("castigatori.out", ios::out);
        aux2.afisare_echipe(out, win);
        out.close();
        aux2.afisare(argv, win, j);
        j++;
        aux2.sterge_stiva(&win);
        aux3.sterge_stiva(&lose);
        nr_echipe = nr_echipe / 2;
    }
}
void cerinta4(last8 *&last,char**argv)
{
    ofstream out("castigatori.out", ios::out);
    BST auxbst, *frunza=NULL;
    while (last!=NULL)
    {
        frunza=auxbst.insert(frunza,last->get_team());
        last=last->get_next();
    }
    auxbst.afisare(argv,frunza);
    auxbst.afisare_fisier(out,frunza);
    out.close();;
}
void cerinta5(AVL *nod, char**argv)
{
    ifstream in("castigatori.out", ios::in);
    Echipa *team;
    team=new Echipa[8];
    AVL auxavl;
    for(int i=0; i<8; i++)
    {
        in>>team[i];
        nod = auxavl.insert(nod, team[i]);
    }
    auxavl.afisare(argv,nod,3);
    in.close();
}
