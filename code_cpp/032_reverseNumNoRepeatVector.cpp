#include<iostream>
#include<vector>

using namespace std;

int main() {
    int num;
    while(cin >> num) {
        vector<int> noRepeat;
        int value;
        while(num % 10) {
            value = num % 10;
            num = num/10;
            bool flag = false;
            for(int k = 0; k < noRepeat.size(); k++) {
                if(noRepeat[k] == value) {
                    flag = true;
                }
            }
            if(!flag) {
                noRepeat.push_back(value);
            }
        }
        for(int i = 0; i < noRepeat.size(); i++) {
            cout << noRepeat[i];
        }
    }
    return 0;
}