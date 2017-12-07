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
    Node *tmp;
public:
    List();
    void Inp(int _data);
    void Print();
};
Node::Node(int _data)
{
    data = _data;
    Next = NULL;
}
List::List()
{
    tmp = top = NULL;
}

void List::Inp(int _data)
{
    Node *tmp = new Node(_data);
    if (top == NULL) {
        top = tmp;
    }
    else
    {
        top->Next = tmp;
    }
}
void List::Print()
{
    if (top->Next == NULL) {
        cout << "<< No data >>" <<endl;
    }
    else
    {
        cout << top->data << endl;
        top = top->Next;
        Print();
    }
}
int main()
{
    List list;
    list.Inp(3);
    list.Inp(8);
    list.Print();

    
    return 0;
}
