//
//  Rectangle.cpp
//  CplusDataStructure
//
//  Created by MJMacBook on 2017. 9. 29..
//  Copyright © 2017년 MJMacBook. All rights reserved.
//

#include "Rectangle.h"

// 접두어로 사용되는 Rectangle:: 는 GetHeight()와 GetWidth()가
// Rectangle class의 멤버 함수라는 것을 나타낸다.

int Rectangle::GetHeight() {return height;}
int Rectangle::GetWidth() {return width;}

void Polynomial::NewTerm(const double theCoeff, const int theExp)
{ // 새로운 항을 termArray끝에 첨가한다.
    if (terms == capacity) {
        // termArray의 크기를 두 배로 확장
        capacity *= 2;
        term *temp = new term[capacity];    //새로운 배열
        copy(termArray, termArray + terms, temp);
        delete [] termArray;        // 그전 메모리를 반환
        termArray = temp;
    }
    termArray[terms].coef = theCoeff;
    termArray[terms++].exp = theExp;
}

bool Rectangle::operator==(const Rectangle &s)
{
    if (this == &s) {
        return true;
        if ((xLow == s.xLow) && (yLow == s.yLow) && (height == s.height) && (width == s.width)) {
            return true;
        }
        else return false;
    }
}

ostream& operator << (ostream& os, Rectangle &r)
{
    os << "Position is: " <<
}

Rectangle::Rectangle(int x = 0, int y = 0, int h =0, int w = 0)
: xLow(x), yLow(y), height(h), width(w)
{}

Polynomial Polynomial::Add(Polynomial b)
{// *this와 b를 더한 결과를 반환한다.
    Polynomial c;
    int aPos = 0, bPos = 0;
    while ((aPos < terms) && (bPos < b.terms)) {
        if (termArray[aPos].exp == b.termArray[bPos].exp) {
            double t = termArray[aPos].coef + b.termArray[bPos].coef;
            if (t) c.NewTerm(t,termArray[aPos].exp);
            aPos++;bPos++;
        }
        else if(termArray[aPos].exp < b.termArray[bPos].exp){
            c.NewTerm(b.termArray[bPos].coef,b.termArray[bPos].exp);
            bPos++;
        }
        else
        {
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
            aPos++;
        }
        //*this의 나머지 항들을 추가한다
        for (; aPos < terms; aPos++) {
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
        }
        return c;
    }
}
