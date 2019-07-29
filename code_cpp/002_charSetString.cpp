#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    string str;
    while(cin >> str) {
        vector<char> vecChar;

        for(int i = 0; i < str.length() && i < 100; i++) {
            int index;
            index = str.find(str[i]);
            if(index == i) {
                vecChar.push_back(str[i]);
            }
        }
        for(int j = 0; j < vecChar.size(); j++) {
            cout << vecChar[j];
        }
        cout << endl;
    }
    return 0;
}