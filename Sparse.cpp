#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

class Arr{
    int row, col, value;
    
public:
    friend class Matrix;
};

class Matrix{
    // size of Matrix;
    int som;
    int arrNum;
    Arr *ArrList;
    int order;
public:
    Matrix(int iparrNum);
    ~Matrix();
    void Psom(int ipsom);
    void MInput(int r, int c, int v);
    void MPrint(int order);
};

Matrix::Matrix(int iparrNum)
{
    ArrList = new Arr[iparrNum];
    order = 0;
}
Matrix::~Matrix()
{
    delete []ArrList;
}
void Matrix::Psom(int ipsom)
{
    som = ipsom;
}
void Matrix::MInput(int r, int c, int v)
{
    ArrList[order].row = r;
    ArrList[order].col = c;
    ArrList[order++].value = v;
}
void Matrix::MPrint(int morder)
{
    cout << " << Matrix " << morder <<" >>"  << endl;
    cout << "row: " << ArrList[morder].row << endl;
    cout << "col: " << ArrList[morder].col << endl;
    cout << "val: " << ArrList[morder].value << endl;
}
int main()
{
    ifstream fin("/Users/innersme/C_study/CplusDataStructure_PNU2017/sampleData1/2.inp");
    int i = 0;
    
    // question
    string Que;
    fin >> Que;
    
    // size of matrix
    int N;
    fin >> N;
    // num of matrix
    int M;
    fin >> M;
    
    int *idxofArr = new int[M];
    int *NofArr = new int[M];
    
    Matrix **MatArr = NULL;
    
    int j = 0;
    while (j < M) {
        fin >> idxofArr[j] >> NofArr[j];
        for (int k = 0 ; k < NofArr[j]; k++) {
            int tprow, tpcol, tpval;
            fin >> tprow >> tpcol >> tpval;
            MatArr[j]->MInput(tprow, tpcol, tpval);
        }
        j++;
    }
    
    delete [] MatArr;
    delete [] NofArr;
    return 0;
}
