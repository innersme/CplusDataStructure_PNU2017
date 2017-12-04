#include <iostream>
#include <fstream>
using namespace std;

class Node {
private:
    int k;    // k-way
    double *deli;    //deli[k-1]
    Node *(*Child);    //child[k]
    int n;    //
    bool leaf;    //
    
public:
    Node(int _k, bool _leaf); //
    Node *search(double n);
    friend class Tree;
};

class Tree
{
private:
    Node *root;
    Node *Cur;
    int k;
    
public:
    Tree(int _k);
    Node *search(double value);
    void insert(double value);
};

Node::Node(int _k, bool _leaf)
{
    k = _k;
    leaf = _leaf;
    deli = new double [k - 1];
    Child = new Node* [k];
    for(int i=0;i<k;++i)
        Child[i]=NULL;
    n = 0;
}

Node *Node::search(double key)
{
    int i = 0;
    while (i < n && key > deli[i])
        i++;
    if (deli[i] == key)
    {
        return this;
    }
    
    if (leaf == true)
    {
        return NULL;
    }
    if(Child[i]!=NULL)
        return Child[i]->search(key);
    else
        return NULL;
}

Tree::Tree(int _k)
{
    root = NULL;
    Cur = root;
    k = _k;
}

void Tree::insert(double value)
{
    if (root == NULL)
    {
        root = new Node(k, true);
        root->deli[0] = value;
        root->n = 1;
    }
    
    else
    {
        Cur = root;
        while (1)
        {
            if (Cur->n != Cur->k-1)
            {
                int i = Cur->n-1;
                while (i >= 0 &&Cur->deli[i] > value)
                {
                    Cur->deli[i+1] = Cur->deli[i];
                    i--;
                }
                Cur->deli[i+1] = value;
                Cur->n++;
                break;
            }
            else
            {
                Node *tmp = new Node(k, true);
                int i = 0;
                while(i < Cur->n && Cur->deli[i] < value)
                    i++;
                if (Cur->leaf == false && Cur->Child[i] != NULL) {
                    Cur = Cur->Child[i];
                }
                else
                {
                    Cur->Child[i] = tmp;
                    Cur->leaf = false;
                    Cur = Cur->Child[i];
                }

            }
        }
    }
}


Node* Tree::search(double v)
{
    //  NULL return
    if (root == NULL)
        return NULL;
    //
    else return root->search(v);
}

int main()
{
    ifstream fin("tree.inp");
    int k;
    int m;

    fin >> k >> m;
    double *ms = new double[m];
    for (int i = 0; i < m; i++)
    {
        fin >> ms[i];
    }
    
    int n;
    fin >> n;
    double *ns = new double[n];
    for (int i = 0; i < n; i++)
    {
        fin >> ns[i];
    }
    Tree t(k);
    for (int i = 0; i < m; i++)
    {
        t.insert(ms[i]);
    }
    double va = 0;
    
    ofstream fout("tree.out");
    fout << n <<endl;
    for (int i = 0; i < n; i++)
    {
        va = ns[i];
        (t.search(va)) ? fout << "1" : fout << "0" ;
        fout << endl;
    }
    
    delete[]ns;
    delete[]ms;
    
    return 0;
}


