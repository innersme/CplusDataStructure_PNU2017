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

class Node
{
    int data;
    Node *Next;
public:
    friend class List;
    Node(int _data);
};

class List
{
    // order;
    Node *top;
    Node *p;
    Node *q;
    // indegree
    int inde;
public:
    List();
    /* data 입력 */
    void Inp(int _data);
    /* data 제거 */
    void Del(int _data);
    // inde에 접근
    void indeplus(){inde++;}
    void indeminus(){inde--;}
    int getinde(){return inde;}
    void Print();
};

class Queue
{
    Node *p;
    Node *q;
public:
    
};
Node::Node(int _data)
{
    data = _data;
    Next = NULL;
}
List::List()
{
    p = top = NULL;
    inde = 0;
}

void List::Inp(int _data)
{
    Node *tmp = new Node(_data);
    if (top == NULL) {
        q = p = top = tmp;
    }
    else
    {
        p->Next = tmp;
        q = p;
        p = p->Next;
    }
}
/*
void List::Del(int _data)
{
    if (top->data == _data) {
        <#statements#>
    }
    else
    {
        
    }
}*/

void List::Print()
{
    Node *ntmp = top;
    if (ntmp == NULL) {
        cout << "/" <<endl;
    }
    else
    {
        /* +1 되어 나타남 */
        cout << ntmp->data + 1 << endl;
        ntmp = ntmp->Next;
        Print();
    }
}
int main()
{
    ifstream fin("/Users/innersme/C_study/CplusDataStructure_PNU2017/sampleData4/1.inp");
    
    int N, K;
    fin >> N;
    List *listarr = new List[N];
    fin >> K;
    int i = 0;
    /* st, de */
    int st = 0; int de = 0;
    while (i < K) {
        fin >> st >> de;
        listarr[st-1].Inp(de-1);
        listarr[de-1].indeplus();
        i++;
    }
    
    // 입력된 LinkedList 출력
    for (int i = 0 ; i < N ; i ++) {
        cout << "<< linked list " << i+1 << " >>"<< endl;
        listarr[i].Print();
        cout << "inde: "  ;
        int a = listarr[i].getinde();
        cout << a << endl;
    }
    listarr[0].Print();
    
    i = 0;
    while (listarr[i].getinde() != 0 ) {
        i++;
    }
    
    
    
    delete []listarr;
    return 0;
}
