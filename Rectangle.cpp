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

Rectangle::Rectangle(int x, int y, int h, int w)
{
    xLow = x; yLow = y;
    height = h; width = w;
}
