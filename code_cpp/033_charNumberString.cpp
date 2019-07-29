#include<iostream>
#include<string>

using namespace std;

int main() {
    string inputStr;
    while(cin >> inputStr) {
        int num = 1;
        for(int i = 1; i < inputStr.size(); i++) {
            char ch = inputStr[i];
            int index = inputStr.find(ch, 0);
            if(index == i) {
                num++;
            }
        }
        cout << num << endl;
    }
    return 0;
}