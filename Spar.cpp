#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#define MaxNum 100000
using namespace std;


class Matrix{
    friend class SparseMatrix;
public:
    void GetValue(int r, int c, int v)
    {
        this->col = c;
        this->row = r;
        this->value = v;
    }
    
    void Print()
    {
        cout << this->col << this->row << this->value << endl;
    }
    
private:
    int row, col,value;
};

class SparseMatrix{
private:
    int rows, cols, values, idx;
    Matrix smArray[MaxNum];
    
public:
    // 초기화
    SparseMatrix(int _row, int _col,int _value)
    {
        rows = _row;
        cols = _col;
        values = _value;
        idx= 0;
    }
    
    SparseMatrix(){}
    
    // 값 저장
    void Store(int Nrow, int Ncol, int Nvalue)
    {
        smArray[idx].row = Nrow;
        smArray[idx].col = Ncol;
        smArray[idx].value = Nvalue;
        idx++;
    }
    
    SparseMatrix Plus(SparseMatrix b)
    {
        
        SparseMatrix Ans;
        Ans.cols = cols;
        Ans.rows = rows;
        Ans.values = values;
        
        idx++;
        
        return Ans;
    }
    
    
    void display(int N)
    {
        
        cout << "<" << N << "rows" << " / " << N << "cols>" << endl;
        for(int i = 0 ; i < (N*N) ; i++ )
        {
            cout << "  " << smArray[i].value ; // 입력 받은 행렬의 값을 smArray 배열에 저장
            if((i+1) % N == 0)
            {
                cout << endl; // 입력 받은 배열을 행렬로 표현하기 위해 최대 열 값으로 나눈다.
            }
        }
        cout << endl;
    }
    
    SparseMatrix Trans(){
        int *Rowsize = new int[cols];
        int *RowStart = new int[cols];
        
        SparseMatrix b;
        b.rows = cols; b.cols = rows; b.values = values;
        if (values > 0) {
            for (int i = 0 ; i<cols; i++) {
                Rowsize[i] = 0;
            }
            
            for (int i = 0; i < cols; i++) {
                RowStart[i] = RowStart[i-1]+Rowsize[i-i];
            }
            
            for (int i = 0 ; i< values ; i++) {
                int j = RowStart[smArray[i].col];
                b.smArray[j].row = smArray[i].col;
                b.smArray[j].col = smArray[i].row;
                b.smArray[j].value = smArray[i].value;
                RowStart[smArray[i].col]++;
            }
        }
        
        delete[] RowStart;
        delete [] Rowsize;
        
        return b;
    }
    
    
};

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
    ifstream in("/Users/innersme/C_study/CplusDataStructure/CplusDataStructure/1.inp");
    // getline
    string str[10000];
    
    int i=0;
    
    while (!in.eof()) {
        getline(in, *(str+i));
        i++;
    }
    
    int N = atoi(str[1].c_str());
    int M = atoi(str[2].c_str());
    
    // cout << N << M <<endl;
    
    int *NofMatrix = new int[M];
    int *Midx = new int[M];
    
    
    NofMatrix[0] = atoi(str[4].c_str());
    int NumM=NofMatrix[0];
    Midx[0] = 5;
    for (i = 1; i < M; i++) {
        NofMatrix[i] = atoi(str[NofMatrix[i-1] + 6].c_str());
        Midx[i] = Midx[i-1] + NofMatrix[i-1]+2;
        NumM += NofMatrix[i];
    }
    
    
    
    
    for (i = 0; i < M; i++) {
        for (int j = 0; j < NofMatrix[i]; j++) {
            string cha = str[Midx[i]+j];
            string *ans = StringSplit(cha, ",");
            
            int Nrow = atoi(ans[0].c_str());
            int Ncol = atoi(ans[1].c_str());
            int Nvalue = atoi(ans[2].c_str());
            
            
            MatArr[i]->Store(Nrow,Ncol,Nvalue);
            
        }
    }
    
    
    delete [] Midx;
    delete [] NofMatrix;
    
    for (i = 0; i < M; i++) {
        delete MatArr[i];
    }
    
    
    return 0;
    
}
