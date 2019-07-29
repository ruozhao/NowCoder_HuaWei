#include<iostream>
#include<cmath>

using namespace std;

int main() {
    float inputNum;
    while(cin >> inputNum) {
        float middle = (floor(inputNum) + ceil(inputNum))/2;
        if (inputNum < middle) {
            cout << floor(inputNum) << endl;
        } else {
            cout << ceil(inputNum) << endl;
        }
    }
    return 0;
}

//  https://blog.csdn.net/FX677588/article/details/52962798