#include "BST.hpp"

BST* BST::creare_bst(Echipa echipa)
{
    BST* node =new BST;
    node->team= echipa;
    node->l = NULL;
    node->r = NULL;
    return(node);
}
BST* BST::insert(BST*node, Echipa echipa)
{
    if (node == NULL)
        return creare_bst(echipa);
    if (echipa.get_points() > node->team.get_points())
        node->l = insert(node->l, echipa);
    else if (echipa.get_points() < node->team.get_points())
        node->r = insert(node->r, echipa);
    else if(echipa.get_points() == node->team.get_points())
    {
        if(echipa.get_nume()>node->team.get_nume())
            node->l = insert(node->l, echipa);
        else if(echipa.get_nume()<node->team.get_nume())
            node->r = insert(node->r, echipa);
    }
    return node;
}
void BST::afisare(char**argv,BST* root)
{
    ofstream d(argv[3], ios::out | ios::app);
    if (!root)
    {
        return;
    }
    afisare(argv,root->l);
    d<<left<<setw(33)<< root->team.get_nume()<<" -  "<<fixed<<setprecision(2)<< root->team.get_points()<<endl;
    afisare(argv,root->r);
    d.close();
}
void BST::afisare_fisier(ostream& d,BST* root)
{
    if (!root)
    {
        return;
    }
    afisare_fisier(d,root->l);
    d<< root->team<<endl;
    afisare_fisier(d,root->r);
}