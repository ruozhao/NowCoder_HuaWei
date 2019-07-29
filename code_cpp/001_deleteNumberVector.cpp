#include<iostream>
#include<vector>
using namespace std;
int main() {
    int len;
    while(cin >> len) {
        if(len > 1000) {
            len = 1000;
        }
        vector<int> vecNumber;
        for(int i = 0; i < len; i++) {
            vecNumber.push_back(i);
        }
        vector<int>::iterator it = vecNumber.begin();
        int i = 0;
        int value;
        while(vecNumber.size()) {
            if(i == 2) {
                i = 0;
                vector<int>::iterator current = it;
                value = *current;
                it = vecNumber.erase(current);
                if(it == vecNumber.end()) {
                    it = vecNumber.begin();
                }
            } else {
                i++;
                if(it + 1 != vecNumber.end())
                    it++;
                else
                    it = vecNumber.begin();
            }
        }
        cout << value << endl;
    }
    return 0;
}