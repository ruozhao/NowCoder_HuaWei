#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
bool cmp(const string&a, const string&b) {
    return a[0] < b[0];
}
bool JudgeRepeatStr(string str,int m) {//判断字符串中是否有长度超过m的重复子串
    int len = str.size();
    string* suffix = new string[len - m];
    for (int i = 0; i < len - m; i++) {
        suffix[i] = str.substr(i, len - i);
    }
    sort(suffix, suffix + len - m, cmp);//重载为按第一个字符进行排序
    for (int i = 0; i < len - m - 1; i++) {//与相邻后缀数组进行比较，判断前m+1个字符是否一样
        if (suffix[i].substr(0, m + 1) == suffix[i + 1].substr(0, m + 1))
            return true;
    }
    return false;
}
int main() {
    string str;
    while (cin >> str) {
        int len = str.size();
        if (len <= 8) {
            cout << "NG" << endl;
            continue;
        }
        int mark[4] = { 0 };
        for (int i = 0; i < len; i++) {
            if (str[i] >= 'A'&&str[i] <= 'Z') mark[0]++;
            else if (str[i] >= 'a'&&str[i] <= 'z') mark[1]++;
            else if (str[i] >= '0'&&str[i] <= '9') mark[2]++;
            else mark[3]++;
        }
        int typeNum = (mark[0] > 0) + (mark[1] > 0) + (mark[2] > 0) + (mark[3] > 0);
        if (typeNum >= 3 && JudgeRepeatStr(str, 2) == 0)
            cout << "OK" << endl;
        else
            cout << "NG" << endl;
    }
    return 0;
}