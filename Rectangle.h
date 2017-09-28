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
#endif /* Rectangle_hpp */
