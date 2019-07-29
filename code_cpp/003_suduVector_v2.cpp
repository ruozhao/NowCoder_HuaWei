//Version2，输出所有解
//没有输出到标准输出，需要在程序所在目录新建text.txt，用于存储所有解，以便观察
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
void print_sudoku(vector<vector<int> > &matrix){
    ofstream fout("text.txt",ofstream::app);
    for(int i=0;i<9;++i){
        for(int j= 0;j<9;++j){
            fout<<matrix[i][j];
            if(j!=8)
                fout<<" ";
        }
        fout<<endl;
    }
    fout<<"***************************"<<endl;
}
void fill_sudoku(vector<vector<int> > &matrix,vector<pair<int,int> > &blank,int n){
    if(n==blank.size()){
        print_sudoku(matrix);//print all the possibilities
        return;
    }
    vector<bool> flags(9,false);
    int x=blank[n].first,y=blank[n].second;
    for(int i=0;i<9;++i){//row and column renouncement
        if(matrix[x][i]!=0)
            flags[matrix[x][i]-1]=true;
        if(matrix[i][y]!=0)
            flags[matrix[i][y]-1]=true;
    }
    int a[9][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1},{0,0}};
    int m=x/3,k=y/3;
    m=m*3+1;k=k*3+1;
    for(int i=0;i<9;++i){//square renouncement
        int temp=matrix[m+a[i][0]][k+a[i][1]];
        if(temp!=0)
            flags[temp-1]=true;
    }
    for(int i=1;i<=9;++i){
        if(!flags[i-1]){
            matrix[x][y]=i;//test each of the candidates
            fill_sudoku(matrix,blank,n+1);//iteration
            matrix[x][y]=0;
        }
    }
}
int main(){
    vector<vector<int> > matrix(9,vector<int>(9));
    vector<pair<int,int> > blank;
    for(int i=0;i<9;++i)
        for(int j=0;j<9;++j){
            cin>>matrix[i][j];
            if(matrix[i][j]==0)
                blank.push_back(make_pair(i,j));
        }
    fill_sudoku(matrix,blank,0);
    return 0;
}