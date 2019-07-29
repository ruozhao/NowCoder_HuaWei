#include <iostream>
#include <vector>
using namespace std;
bool is_sudoku(vector<vector<int> > &matrix){
    vector<bool> flags1(9,false),flags2(9,false),flags3(9,false);
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            flags1[matrix[i][j]-1]=true;//check the column
            flags2[matrix[j][i]-1]=true;//check the line
        }
        for(int j=0;j<9;++j){
            if(!(flags1[j]&&flags2[j]))
                return false;
        }
    }
    int a[9][2]={{0,0},{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
    for(int i=1;i<9;i+=3){
        for(int j=1;j<9;j+=3){
            //check every grid
            vector<bool> flags(9,false);
            for(int k=0;k<9;++k){
                int x=i+a[k][0];
                int y=j+a[k][1];
                flags[matrix[x][y]-1]=true;
            }
            for(int k=0;k<9;++k){
                if(!flags[k])
                    return false;
            }
        }
    }
    return true;
}
int main(){
    vector<vector<int> > matrix(9,vector<int>(9));
    while(1){
        for(int i=0;i<9;++i)
            for(int j=0;j<9;++j)
                cin>>matrix[i][j];
        bool res=is_sudoku(matrix);
        if(res)
            cout<<"This sudoku is normal"<<endl;
        else
            cout<<"This sudoku is abnormal"<<endl;
    }
    return 0;
}