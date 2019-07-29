#include <iostream>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        cout<<n/2<<endl;
    }
    return 0;
}

// ==============================================solution2

#include<iostream>
#include<vector>

using namespace std;
int changeNum(int input) {
    int res, other;
    int count;
    if(input <= 1) {
        return 0;
    }
    if(input == 2) {
        return 1;
    } else {
        res = input / 3;
        other = input % 3;
        count = res + changeNum(res + other);
    }
    return count;
}
int main() {
    int count = 0;
    while(count < 10) {
        int inputNum = 0;
        cin >> inputNum;
        if(inputNum == 0) {
            break;
        }
        cout << changeNum(inputNum) << endl;
    }
    return 0;
}