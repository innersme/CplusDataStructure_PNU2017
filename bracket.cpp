//
//  bracket.cpp
//  CplusDataStructure_PNU2017
//
//  Created by MJMac on 2017. 11. 2..
//  Copyright © 2017년 innersme. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

class Node{
    friend class Stack;
private:
    char    data;
    Node    *Next;
    Node(char data);
};

Node::Node(char data){
    this->data = data;
    this->Next = NULL;
}

class Stack{
private:
    Node *top;
public:
    Stack();
    //~Stack();
    bool isEmpty();
    void Push(char data);
    char pop();
    char show();
};

Stack::Stack()
{
    this->top = NULL;
}

/*Stack::~Stack(){
    Node * top = this->top;
    while(top){
        Node *newNode = top;
        top = top->Next;
        delete newNode;
    }
}*/

bool Stack::isEmpty()
{
    if (this->top == NULL) {
        return 1;
    }
    else return 0;
}

void Stack::Push(char data)
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

char Stack::pop()
{
    char data;
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

char Stack::show()
{
    if (this->top == NULL) {
        return 0;
    }
    else
    {
        return this->top->data;
    }
    
}

bool isTrue(string str)
{
    bool flag =0;
    int i =1;
    Stack stack;
    stack.Push(str[0]);
    if (str.length() == 1) {
        return flag;
    }
    while (i < str.length()) {
        char tmp = str[i];
        //str.erase(0,1);
        if (tmp == ']') {
            if(stack.pop() == '[')
            {
                i++;
            }
            else return flag;}
        else if (tmp == ')' ) {
            if(stack.pop() == '(')
            {
                i++;
            }
            else return flag;}
        else if (tmp == '}') {
            if(stack.pop() == '{')
            {
                i++;
            }
            else return flag;}
        else
        {
            stack.Push(tmp);
            i++;
        }
    }
    if (stack.isEmpty() == 0) {
        return flag;
    }
    flag = 1;
    return flag;
}

int main()
{
    ifstream fin("bracket.inp");
    
    int i = 0;
    string str[10000];
    
    if (fin.is_open()) {
        while (!fin.eof()) {
            getline(fin, *(str+i));
            i++;
        }
    }
    
    int N = atoi(str[0].c_str());
    i = 1;
    ofstream fout("bracket.out");
    fout << N << endl;
    while(1)
    {
        if (i == N+1 ) {
            break;
        }
        else
        {
            if (isTrue(str[i])) {
                fout << "true" << endl;
            }
            else
            {
                fout << "false" <<  endl;
            }
            i++;
        }
    }
    
    return 0;
    
}
