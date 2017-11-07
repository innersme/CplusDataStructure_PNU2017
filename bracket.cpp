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

#define bracketO {||[||( ;

using namespace std;

class Node{
    friend class Stack;
private:
    char  data;
    Node    *Next;
    Node(int data);
};

Node::Node(int data){
    this->data = data;
}

class Stack{
private:
    Node *top;
    int length;
public:
    Stack();
    ~Stack();
    void Push(char data);
    char pop();
    char show();
    int getLength();
};

Stack::Stack()
{
    this->top = NULL;
    this->length = 0;
}

Stack::~Stack(){
    Node * top = this->top;
    while(top){
        Node *newNode = top;
        top = top->Next;
        delete newNode;
    }
}

void Stack::Push(char data)
{
    if (this->top == NULL) {
        this->top = new Node(data);
    }
    else{
        Node *newNode = this->top;
        this->top = new Node(data);
        this->top->Next = newNode;
    }
    length++;
    
};

char Stack::pop()
{
    char data = this->top->data;
    delete this->top;
    this->top = this->top->Next;
    
    length--;
    
    return data;
};

char Stack::show()
{
    return this->top->data;
}

int Stack::getLength(){
    return length;
}

bool isTrue(string str)
{
    bool flag =0; int i =0;
    int strNum = str.length();
    Stack stack;
    
    while (i < strNum) {
        if (str[i] == ']') {
            if(stack.show() == '[')
            {
                stack.pop();i++;
            }
            else return flag;}
        else if (str[i] == ')') {
            if(stack.show() == '(')
            {
                stack.pop();i++;
            }
            else return flag;}
        else if (str[i] == '}') {
            if(stack.show() == '{')
            {
                stack.pop();i++;
            }
            else return flag;}
        else
        {
            stack.Push(str[i]);
            i++;
        }
    }
    if (i == strNum && stack.getLength() == 0) {
        flag = 1;
    }
    
    return flag;
}


int main()
{
    ifstream fin("/Users/innersme/C_study/CplusDataStructure/CplusDataStructure/sampleData2/2.inp");
    
    int N;
    int i = 0;
    string str[10000];
    bool *boolist = new bool[N];
    
    if (fin.is_open()) {
        while (!fin.eof()) {
            getline(fin, *(str+i));
            i++;
        }
    }
    
    N = atoi(str[0].c_str());
    
    
    cout << isTrue(str[3]);
    
    
    
    delete []boolist;
    return 0;
    
}
