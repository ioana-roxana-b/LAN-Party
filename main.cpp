#include "solutii.hpp"

int main(int argc, char* argv[])
{
    ifstream c(argv[1], ios::in);
    ifstream d(argv[2], ios::in);
    ofstream r(argv[3], ios::out | ios::app);

    Lista a,*p;
    Echipa l,winner;
    last8 auxlast, *last=NULL;
    BST *frunza=NULL, auxbst;
    AVL *nod=NULL, auxavl;
    int task[5];
    for (int i = 0; i < 5 ; i++)
    {
        c >> task[i];
        switch (i)
        {
        case 0:
        {
            if (task[0]== 1)
            {
                a.creare_lista(&p, argv);
                a.afisare_nume(argv, p);
            }
            break;
        }
        case 1:
        {
            if (task[1]== 1)
            {
                a.afisare_ramase(p, argv);
            }
            break;
        }
        case 2:
        {
            if (task[2]== 1)
            {
                cerinta3(argv,last);
            }
            break;
        }
        case 3:
        {
            if (task[3] == 1)
            {
                r<<endl<<"TOP 8 TEAMS:"<<endl;
                cerinta4(last,argv);
            }
            break;
        }
        case 4:
        {
            if (task[4]== 1)
            {
                r << endl << "THE LEVEL 2 TEAMS ARE:" << endl;
                cerinta5(nod,argv);
            }
            break;
        }
        default:
        {
            cout << "Error! " << endl;
            break;
        }
        }
    }
    r.close();
    c.close();
    d.close();
    return 0;
}
