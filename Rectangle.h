//
//  Rectangle.hpp
//  CplusDataStructure
//
//  Created by MJMacBook on 2017. 9. 29..
//  Copyright © 2017년 MJMacBook. All rights reserved.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H
//Rectangle.h 헤더 파일 속에

class Rectangle{
public:
    Rectangle();
    ~Rectangle();
    int GetHeight();
    int GetWidth();
private:
    int xLow, yLow, height, width;
    //(xLow, yLow)는 사각형의 왼쪽 하단 모서리 좌표이다.
};


class NaturalNumber{
public:
    NaturalNumber Zero();
    // 0을 반환한다.
    
    bool IsZero();
    // *this 가 0이면 true를, 아니면 false를 반환한다.
    
    NaturalNumber Add(NaturalNumber y);
    // *this + y 와 AXINT에서 작은 값을 반환한다.
    
    bool Equal(NaturalNumber y);
    // *this == y 이면 true를, 아니면 false를 바환하다.
    
    NaturalNumber Successor();
    // *this가 MAXINT이면 MAXINT를 아니면 *this+1을 반환한다.
    
    NaturalNumber Substract(NaturalNumber y);
    // *this < y이면 0을, 아니면 *this-y를 반환한다.
};

class GeneralArray {
public:
    GeneralArray(int j, RangeList list, double initValue = defaultValue);
    
    double Retrieve(index i);
    
    void Store(index i, double x);
    // i가 배열의 index집합에 있으면 배열에서 i와 쌍이 되는 값을 x로 대체하고,
};

class Polynomial{
public:
    Polynomial();
    // 다항식 p(x) = 0 을 생성
    
    Polynomial Add(Polynomial poly);
    // 다항식 *this와 poly의 합을 반환
    
    Polynomial Mult(Polynomial poly);
    
    double Eval(double f);
    // 다항식 *this에 f를 대입한 값을 계산하여 그 결과를 반환
private:
    Term *termArray;    // 0이 아닌 항의 배열
    int capacity;       // termArrary의 크기
    int terms;          // 0이 아닌 항의 수
};

class Term{
    friend Polynomial;
private:
    double coef;    // 계수
    int exp;        // 지수
};

#endif /* Rectangle_hpp */
