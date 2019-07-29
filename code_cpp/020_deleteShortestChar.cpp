#include <iostream>
#include <string>
#include <map>

using namespace std;
int main() {
    string inputStr;
    while(cin >> inputStr) {

        map<char, int> charCount;
        for(int i = 0; i < inputStr.size(); i++) {
            char tmp = inputStr[i];
            if(charCount.find(tmp) != charCount.end()) {
                charCount[tmp] = charCount[tmp] + 1;
            } else {
                charCount[tmp] = 1;
            }
        }
        map<char, int>::iterator it = charCount.begin();
        map<char, int>::iterator min = it;
        it++;
        for(; it != charCount.end(); it++) {
            if(it -> second < min -> second) {
                min = it;
            }
        }

        int num = min -> second;
        for(it = charCount.begin(); it != charCount.end(); it++) {
            if(it -> second == num) {
                char delChar = it -> first;
                int ind = inputStr.find(delChar);
                while(inputStr.size() != 0 && ( ind >= 0 && ind < inputStr.length())) {
                        inputStr.erase(ind, 1);
                        ind = inputStr.find(delChar);
                }
            }
        }

        cout << inputStr << endl;
    }
    return 0;
}