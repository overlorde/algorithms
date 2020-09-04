#include <bits/stdc++.h>
using namespace std;
#define pow2(n) (1<<(n))

using namespace std;

struct avl{
    int d;
    struct avl *l;
    struct avl *r;
}*r;

class avl_tree{
    public:
    int height(avl *);
    int difference(avl *);
    avl *rr_rotat(avl *);
    avl *ll_rotat(avl *);
    avl *lr_rotat(avl *);
    avl *balance(avl *);
    avl *insert(avl *,int);

    void inorder(avl *);
    void preorder(avl *);
    void postorder(avl *);
    
    avl_tree()
    {
        r = NULL;
    }
};

int avl_tree::height(avl *t)
{
    int h  = 0;

    if(t != NULL)
    {
        int l_height = height(t->l);
        int r_height = height(t->r);

        int max_height = max(l_height,r_height);
        h = max_height+1;
    }
    return h;
}


int avl_tree::difference(avl* t)
{
    int l_height = height(t->l);
    int r_height = height(t->r);
    return l_height-r_height;
}

avl *avl_tree::rr_rotat(avl *parent)
{
    avl *t;
    t = parent->r;
    parent->r = t->l;
    t->l = parent;
    cout<<"Right-Right Rotation"<<endl;
    return t;
}

avl *avl_tree::ll_rotat(avl *parent)
{
    avl *t;
    t = parent->l;
    parent->l = t->r;

    t->r = parent;
    cout<<"Left left Rotation";
    return t;
}

avl *avl_tree::lr_rotat(avl *t)
{
    avl *t;
    t = parent->l;
    parent->l  = rr_rotat(t);
    cout<<"Left rught rotation\n";
    return ll_rotat(parent);
}

avl *avl_tree::rl_rotat(avl *parent)
{
    avl *t;
    t = parent->l;
    parent->r = ll_rotat(t);
    cout<<"right left rotation\n";
    return rr_rotate(parent);
}

avl *avl_tree::balance(avl *t)
{
    int bal_factor = differencr(t);
    if(bal_factor>1)
    {
        if(difference(t-1) > 0)
        {
            t = ll_rotat(t);
        }
        else{
            t = lr_rotat(t);
        }
    }else if(bal_factor <-1)
    {
        if(difference(t->r)>0)
        {
            t = rl_rotat(t);
        }
        else{
            t = rr_rotat(t);
        }
    }
    return t;
}


avl *avl_tree::insert(avl *r,int v)
{
    if(r == NULL)
    {
        r = new avl;
        r->d = v;
        r->l = NULL;
        r->r = NULL;
        return r;
    }else if(v<r->d){
        r = balance(r);
    }
}

