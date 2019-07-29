#include<iostream>
#include<string>
#include<map>
using namespace std;

int main() {
    string strNum;
    string const strHex = "0123456789abcdef";

    while(cin >> strNum) {
        long int result = 0;
        string strSplit = strNum.substr(2);
        for(int i = 0; i < strSplit.size(); i++) {
            if(strSplit[i] < 97 && strSplit[i] > 64) {
                strSplit[i] = strSplit[i] + 32;
            }
            char ch = strSplit[i];
            result = result * 16 + strHex.find(ch, 0);
        }
        cout << result << endl;
    }
    return 0;
}

#include<iostream>
#include<string>
using namespace std;
int main() {
    string inputStr;
    const string hexString = "0123456789abcdef";

    while(cin >> inputStr) {
        string num = inputStr.substr(2);
        long int res = 0;
        for(int i = 0; i < num.size(); i++) {
            char tempCh;
            if(num[i] > 64 && num[i] < 92) {
                tempCh = num[i] + 32;
            } else
                tempCh = num[i];
            res = res * 16 + hexString.find(tempCh, 0);
        }
        cout << res << endl;
    }
    return 0;
}

// https://www.cnblogs.com/aminxu/p/4686320.html