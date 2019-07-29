#include<iostream>
#include<string>
#include<map>

using namespace std;

int main() {
    string strNum;
    string const strHex = "0abcdefghijklmnopqrstuvwxyz";

    while(cin >> strNum) {
        long int result = 0;
        string strSplit = strNum;
        for(int i = 0; i < strSplit.size(); i++) {
            if(strSplit[i] < 97 && strSplit[i] > 64) {
                strSplit[i] = strSplit[i] + 32;
            }
            char ch = strSplit[i];
            result = result * 26 + strHex.find(ch, 0);
        }
        cout << result << endl;
    }
    return 0;
}