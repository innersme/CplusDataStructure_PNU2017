//
//  Ne.cpp
//  CplusDataStructure
//
//  Created by MJMac on 2017. 10. 10..
//  Copyright © 2017년 innersme. All rights reserved.
//

#include <fstream>
#include <string>
#include <iostream>
using namespace std;


static string* StringSplit(string strOrigin, string strTok)
{
    int     cutAt;                            //자르는위치
    int     index     = 0;                    //문자열인덱스
    string* strResult = new string[3];  //결과return 할변수
    
    //strTok을찾을때까지반복
    while ((cutAt = strOrigin.find_first_of(strTok)) != strOrigin.npos)
    {
        if (cutAt > 0)  //자르는위치가0보다크면(성공시)
        {
            strResult[index++] = strOrigin.substr(0, cutAt);  //결과배열에추가
        }
        strOrigin = strOrigin.substr(cutAt+1);  //원본은자른부분제외한나머지
    }
    
    if(strOrigin.length() > 0)  //원본이아직남았으면
    {
        strResult[index++] = strOrigin.substr(0, cutAt);  //나머지를결과배열에추가
    }
    
    return strResult;  //결과return
}



int main()
{
    // file 입력
    ifstream in("/Users/innersme/C_study/CplusDataStructure/CplusDataStructure/2.inp");
    // getline
    string str[1000];
    
    int i=0;
    
    while (!in.eof()) {
        getline(in, *(str+i));
        i++;
    }
    
    int N = stoi(str[1]);
    int M = stoi(str[2]);
    
    int **InitArr = NULL;
    InitArr = new int*[N];
    for (int i = 0; i < N ; i++) {
        InitArr[i] = new int [N];
    }
    // cout << N << M <<endl;
    
    for (int i =0; i < N; i++) {
        for (int j = 0; j < N ; j++) {
            InitArr[i][j] = 0;
        }
    }
    
    for (int i =0; i < N; i++) {
        for (int j = 0; j < N ; j++) {
            cout << InitArr[i][j] << " ";
        }
        cout << endl;
    }
    
    
    int *NofMatrix = new int[M];
    int *Midx = new int[M];
    
    
    NofMatrix[0] = stoi(str[4]);
    Midx[0] = 5;
    for (i = 1; i < M; i++) {
        NofMatrix[i] = stoi(str[NofMatrix[i-1] + 6]);
        Midx[i] = Midx[i-1] + NofMatrix[i-1]+2;
    }
    
    /*
     for (i = 0; i < M ; i++) {
     cout << NofMatrix[i] << Midx[i] <<endl;
     }*/
    
    for (i = 0; i < M; i++) {
        for (int j = 0; j < NofMatrix[i]; j++) {
            
            string cha = str[Midx[i]+j];
            string *ans = StringSplit(cha, ",");
            int Nrow = stoi(ans[0])-1;
            int Ncol = stoi(ans[1])-1;
            int Nvalue = stoi(ans[2]);
            
            cout << Nrow <<" " << Ncol <<" " << Nvalue << endl;
            
            for (int i =0; i < N; i++) {
                for (int j = 0; j < N ; j++) {
                    if (i == Nrow && j == Ncol) {
                        InitArr[i][j] = Nvalue;
                    }
                }
                cout << endl;
            }
            
            for (int i =0; i < N; i++) {
                for (int j = 0; j < N ; j++) {
                    cout << InitArr[i][j] << " ";
                }
                cout << endl;
            }
            
            
            
            
        }
    }
    
    
    
    delete [] Midx;
    delete [] NofMatrix;
    for (int i =0 ; i < N; i++) {
        delete[] InitArr[i];
    }
    delete [] InitArr;
    return 0;
}


