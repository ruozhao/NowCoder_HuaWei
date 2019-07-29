#include <iostream>
#include <vector>
using namespace std;
bool fill_sudoku(vector<vector<int> > &matrix,vector<pair<int,int> > &blank,int n){
    if(n==blank.size())
        return true;
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
            bool res=fill_sudoku(matrix,blank,n+1);
            if(!res)
                matrix[x][y]=0;
            else
                break;
        }
    }
    if(matrix[x][y]!=0)
        return true;
    else
        return false;
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
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            cout<<matrix[i][j];
            if(j!=8)
              cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}