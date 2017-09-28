//
//  main.cpp
//  CplusDataStructure
//
//  Created by MJMacBook on 2017. 9. 29..
//  Copyright © 2017년 MJMacBook. All rights reserved.
//

#include <iostream>
#include "Rectangle.h"
using namespace std;

int main()
{
    Rectangle r,s;  //r과 s는 Class Rectangle의 객체들이다.
    Rectangle *t = &s;  // t는 클래스 객체 s에 대한 포인터이다.
    
    // 클래스 객체의 멤버에 접근하기 위해 점(.)을 사용한다.
    // 포인터를 통해 클래스 객체의 멤버에 접근하기 위해서 ->를 사용한다.
    
    if (r.GetHeight() * r.GetWidth() > t->GetWidth() * t->GetWidth()) {
        cout << "r";}
    else cout << "s";
    cout<< "has the greater area" << endl;
    
    return 0;
}

