//
//  graph.cpp
//  CplusDataStructure_PNU2017
//
//  Created by MJMacBook on 2017. 12. 5..
//  Copyright © 2017년 MJMacBook. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


/* node */
class Node
{
    int data;
    Node *Next;

public:
    friend class List;
    friend class Stack;
    Node(int _data);
};

Node::Node(int _data)
{
    data = _data;
    Next = NULL;
}

/* list */
class List
{
    // order;
    Node *top;
    Node *p;
    Node *q;
    Node *cur;
    // indegree
    int inde;
    bool isVisited;
public:
    List();
    /* data 입력 */
    void Inp(int _data);
    // inde에 접근
    int Next(int data);
    friend class Graph;
    friend class Stack;
};

/* stack */
class Stack{
private:
    Node *top;
public:
    Stack();
    //~Stack();
    bool isEmpty();
    void Push(int data);
    int pop();
    int show();
};

class Graph
{
    int V;
    int E;
    List *listarr;
    int *visit;
    
public:
    Graph(int V);
    void addEdge(int v, int w);
    void showV(int v);
    bool dovisit(int v);
    void printall();
    void indep(int v){listarr[v].inde++;}
    void indem(int v){listarr[v].inde--;}
    int getinde(int v){return listarr[v].inde;}
};


List::List()
{
    cur = p = q = top = NULL;
    inde = 0;
}

void List::Inp(int _data)
{
    Node *tmp = new Node(_data);
    if (top == NULL) {
        cur = q = p = top = tmp;
    }
    else
    {
        p->Next = tmp;
        q = p;
        p = p->Next;
    }
}
int List::Next(int _data)
{
    int tmpdata = -1;
    if (top == NULL) {
        return -1;
    }
    else
    {
        Node *tmp = top;
        while (tmpdata == _data) {
            tmp->data = tmpdata;
            tmp = tmp->Next;
        }
        return tmp->Next->data;
    }
}
Stack::Stack()
{
    this->top = NULL;
}

bool Stack::isEmpty()
{
    if (this->top == NULL) {
        return 1;
    }
    else return 0;
}

void Stack::Push(int data)
{
    Node *newNode = new Node(data);
    if (this->top == NULL) {
        this->top = newNode;
    }
    else{
        newNode->Next = this->top;
        this->top = newNode;
    }
};

int Stack::pop()
{
    int data;
    Node *tmpNode;
    if (this->isEmpty()) {
        return 0;
    }
    else{
        data = this->top->data;
        tmpNode = this->top;
        this->top = this->top->Next;
        delete tmpNode;
        //delete this->top;
        return data;
    }
};

Graph::Graph(int V)
{
    this->V = V;
    this->E = 0;
    listarr = new List[V];
    visit = new int[V];
    for (int i = 0 ; i < V; i++) {
        visit[i] = 0;
    }
}

void Graph::addEdge(int _v, int _w)
{
    listarr[_v].Inp(_w);
    E++;
}

bool Graph::dovisit(int _v)
{
    if (this->visit[_v] == 0) {
        this->visit[_v] = 1;
        cout << _v << endl;
        return 1;
    }
    return 0;
}

void Graph::printall()
{
    cout << " << GRAPH >> " << endl;
    for (i = 0; <#condition#>; <#increment#>) {
        <#statements#>
    }
    cout << "Node" << this-
}

int main()
{
    ifstream fin("/Users/innersme/C_study/CplusDataStructure_PNU2017/sampleData4/1.inp");
    
    int N, K;
    fin >> N;
    Graph G(N);
    fin >> K;
    int i = 0;
    /* st, de */
    int st = 0; int de = 0;
    while (i < K) {
        fin >> st >> de;
        G.addEdge(st-1, de-1);
        i++;
    }
    
    return 0;
}
