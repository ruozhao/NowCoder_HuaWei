#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    string inputStr;
    while(cin >> inputStr) {
        vector<string> pro;
        while(inputStr.size() != 0) {
            string temp;
            int indexSplit = inputStr.find_first_of(";", 0);
            temp = inputStr.substr(0, indexSplit);
            pro.push_back(temp);
            inputStr = inputStr.substr(indexSplit + 1);
        }
        int xPos = 0, yPos = 0;
        for(int i = 0; i < pro.size(); i++) {
            string temp = pro[i];
            char handler = temp[0];
            int num = 0;
            bool flag = false;
            for(int j = 1; j < temp.size(); j++) {
                if(temp[j] > '9' || temp[j] < '0') {
                    flag = true;
                    break;
                }
                num = temp[j] - '0' + num * 10;
            }
            if(!flag) {
                if(handler == 'A') {
                    xPos = xPos - num;
                }
                if(handler == 'D') {
                    xPos = xPos + num;
                }
                if(handler == 'S') {
                    yPos = yPos - num;
                }
                if(handler == 'W') {
                    yPos = yPos + num;
                }
            }
        }
        cout << xPos << "," << yPos << endl;
    }
    return 0;
}