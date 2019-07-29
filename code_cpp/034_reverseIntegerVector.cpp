#include<iostream>
#include<vector>

using namespace std;

int main() {
    int num;
    while(cin >> num) {
        vector<int> noRepeat;
        int value;
        while(num) {
            value = num % 10;
            num = num/10;
            noRepeat.push_back(value);
        }
        for(int i = 0; i < noRepeat.size(); i++) {
            cout << noRepeat[i];
        }
    }
    return 0;
}