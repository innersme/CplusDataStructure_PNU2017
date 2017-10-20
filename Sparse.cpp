#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#define MaxNum 100000
using namespace std;

class Arr{
    friend class Matrix;
    
private:
    
public:
    
    int col, row, value;
    
    void Save(int r, int c, int v)
    {
        this->col = c;
        this->row = r;
        this->value =v;
    }
    
    void print()
    {
        cout <<"row: "<< this->row <<"col: "<< this->col <<"value: "<< this->value<< endl;
    }
    
    
    int getValue(int value)
    {
        return this->value;
    }
    
};

class Matrix{
public:
    // 배열 인덱스
    int idx;
    Arr SMatrix[MaxNum];
    // 배열 항 갯수
    int NumofValue;
    
    Matrix(){ };
    
    void setValue(int v)
    {
        NumofValue = v;
    }
    
    Matrix *Add(Matrix b, int count, int count_b, int N)
    {
        
        Matrix re = b;
        
        idx = 0;
        // idx 에 저장
        for (idx = 0 ; idx < count; idx++) {
            SMatrix[idx].Save(this->SMatrix[idx].col,this->SMatrix[idx].row,this->SMatrix[idx].value);
        }
        
    
        
        int jdx = 0;
        while (jdx < count_b) {
            int plusidx = 0;
            for(int ro = 0; ro < N ; ro++)
            {
                if (re.SMatrix[jdx].row == ro)
                {
                    for(int k = 0 ; k < count ; k++)
                    {
                        if (b.SMatrix[jdx].col == SMatrix[k].col) {
                            SMatrix[k].value += b.SMatrix[jdx].value;
                        }
                    }
                    SMatrix[idx+plusidx].Save(b.SMatrix[jdx].row, b.SMatrix[jdx].col, b.SMatrix[jdx].value);
                }
                else
                {
                    SMatrix[idx+plusidx].Save(b.SMatrix[jdx].row, b.SMatrix[jdx].col, b.SMatrix[jdx].value);
                }
            }
            
            
            jdx++;
        }
        
        return this;
    
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
    ifstream in("/Users/innersme/C_study/CplusDataStructure/CplusDataStructure/2.inp");
    // getline
    string str[MaxNum];
    
    int i=0;
    
    while (!in.eof()) {
        getline(in, *(str+i));
        i++;
    }
    
    int N = atoi(str[1].c_str());
    int M = atoi(str[2].c_str());
    
    // cout << N << M <<endl;
    
    // NofMatrix [i]번째
    int *NofMatrix = new int[M];
    // index of K[i], first
    int *Midx = new int[M];
    
    
    NofMatrix[0] = atoi(str[4].c_str());
    // NumM = sum of K[i]
    int NumM=NofMatrix[0];
    
    Midx[0] = 5;
    for (i = 1; i < M; i++) {
        NofMatrix[i] = atoi(str[NofMatrix[i-1] + 6].c_str());
        Midx[i] = Midx[i-1] + NofMatrix[i-1]+2;
        NumM += NofMatrix[i];
    }
    
    // 배열 입력
    Matrix * SparseMatrix = new Matrix[M];
    
    //save
    for (i = 0; i < M; i++) {
        for (int j = 0; j < NofMatrix[i]; j++) {
            string cha = str[Midx[i]+j];
            string *ans = StringSplit(cha, ",");
            
            int Nrow = atoi(ans[0].c_str()) -1 ;
            int Ncol = atoi(ans[1].c_str()) -1 ;
            int Nvalue = atoi(ans[2].c_str());
            
            SparseMatrix[i].SMatrix[j].Save(Nrow, Ncol, Nvalue);
        }
        // setCount
        SparseMatrix[i].setValue(NofMatrix[i]);
    }

    // res함수
    Matrix res = SparseMatrix[0];
    
    res.Add(SparseMatrix[1], SparseMatrix[0].NumofValue, SparseMatrix[1].NumofValue, N);
    
    for (int i = 0; i  < SparseMatrix[0].NumofValue + SparseMatrix[1].NumofValue; i++) {
        res.SMatrix[i].print();
    }
    
    
    
    delete [] Midx;
    delete [] NofMatrix;
    delete [] SparseMatrix;
    return 0;
    
}
