#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
    string inputStr;
    while(cin >> inputStr) {
        vector<char> strConvert;
        for(int k = 0; k < inputStr.size(); k++) {
            strConvert.push_back(inputStr[k]);
        }
        while(strConvert.size()) {
            char ch = strConvert.at(strConvert.size()-1);
            cout << ch;
            strConvert.pop_back();
        }
    }
    return 0;
}


// ================================================solution2

#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
    string numStr;
    while(cin >> numStr) {
        vector<char> noRepeat;
        int k;
        for(k = 0; k < numStr.size(); k++) {
            noRepeat.push_back(numStr[k]);
        }
        for(k = k - 1; k >= 0; k--) {
            cout << noRepeat[k];
        }
    }
    return 0;
}