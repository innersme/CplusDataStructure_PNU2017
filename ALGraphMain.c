//
//  ALGraphMain.c
//  CplusDataStructure_PNU2017
//
//  Created by MJMacBook on 2017. 12. 5..
//  Copyright © 2017년 MJMacBook. All rights reserved.
//

#include <stdio.h>
#include "ALGraph.h"

int main()
{
    ALGraph graph;          // 그래프의 생성
    GraphInit(&graph, 5);   // 그래프의 초기화
    
    AddEdge(&graph, A, B);
    AddEdge(&graph, A, D);
    AddEdge(&graph, B, C);
    AddEdge(&graph, C, D);
    AddEdge(&graph, D, E);
    AddEdge(&graph, E, A);
    
    ShowGraphEdgeInfo(&graph);
    GraphDestroy(&graph);
    return 0;
}
