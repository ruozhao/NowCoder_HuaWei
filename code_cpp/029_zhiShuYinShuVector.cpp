#include<iostream>
#include<vector>

using namespace std;
int main() {
    long int ulDataInput;
    while(cin >> ulDataInput) {

        vector<int> yinShu;
        int num = 2;
        while(ulDataInput != 1){
            if(ulDataInput % num == 0) {
                yinShu.push_back(num);
                ulDataInput = ulDataInput / num;
            } else {
                num++;
            }
        }
        for(int i = 0; i < yinShu.size(); i++) {
            cout << yinShu[i] << " ";
        }

    }
    return 0;
}

// https://www.cnblogs.com/aminxu/p/4686332.html
// http://blog.chinaunix.net/uid-26000296-id-3785623.html
//
//