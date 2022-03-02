#include "AVL.hpp"

int AVL::Height(AVL* root)
{
    if (root == NULL) return -1;
    else return root->h;
}
AVL *AVL::RightRotation( AVL *z)
{
    AVL *y = z->l;
    AVL *T3 = y->r;
    y->r = z;
    z->l = T3;
    z->h = max(Height(z->l), Height(z->r))+1;
    y->h = max(Height(y->l), Height(y->r))+1;
    return y;
}
AVL *AVL::LeftRotation(AVL *z)
{
    AVL *y = z->r;
    AVL *T2 = y->l;
    y->l = z;
    z->r = T2;
    z->h = max(Height(z->l), Height(z->r))+1;
    y->h = max(Height(y->l), Height(y->r))+1;
    return y;
}
AVL* AVL::LRRotation(AVL*Z)
{
    Z->l= LeftRotation(Z->l);
    return RightRotation(Z);
}
AVL* AVL::RLRotation(AVL*Z)
{
    Z->r = RightRotation(Z->r);
    return LeftRotation(Z);
}
int max(int a,int b)
{
    return ((a>b)?a:b);
}
AVL* AVL::insert(AVL* node, Echipa key)
{
    if (node == NULL)
    {
        node= new AVL;
        node->team = key;
        node->h = 0;
        node ->l = node->r = NULL;
        return node;
    }
    if (key.get_points() < node->team.get_points())
        node->l = insert(node->l, key);
    else if (key.get_points() > node->team.get_points())
        node->r = insert(node->r, key);
    else if(key.get_points() == node->team.get_points())
    {
        if(key.get_nume() < node->team.get_nume())
            node->l = insert(node->l, key);
        else if(key.get_nume() > node->team.get_nume())
            node->r = insert(node->r, key);
    }
    else return node;
    node->h = 1 + max(Height(node->l), Height(node->r));
    int balance = (Height(node->l) - Height(node->r));
    if (balance > 1 && key.get_points() < node->l->team.get_points())
        return RightRotation(node);
    if (balance < -1 && key.get_points() > node->r->team.get_points())
        return LeftRotation(node);
    if (balance > 1 && key.get_points() > node->l->team.get_points())
        return RLRotation(node);
    if (balance < -1 && key.get_points() < node->r->team.get_points())
        return LRRotation(node);

    if (balance > 1 && key.get_points() == node->l->team.get_points() && key.get_nume() < node->l->team.get_nume())
        return RightRotation(node);
    if (balance < -1 && key.get_points() == node->r->team.get_points() && key.get_nume()>node->r->team.get_nume())
        return LeftRotation(node);
    if (balance > 1 && key.get_points() == node->l->team.get_points() && key.get_nume()>node->l->team.get_nume())
        return RLRotation(node);
    if (balance < -1 && key.get_points() == node->r->team.get_points() && key.get_nume()<node->r->team.get_nume())
        return LRRotation(node);

    return node;
}
void AVL::afisare(char**argv,AVL *t,int level)
{
    ofstream devo(argv[3], ios::out | ios::app);
    if(level==1)
    {
        devo<<t->team.get_nume()<<endl;
    }
    else
    {
        afisare(argv, t->r,level-1);
        afisare(argv, t->l,level-1);
    }
    devo.close();
}
