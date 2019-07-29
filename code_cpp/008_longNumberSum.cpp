#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

string StrAdd(string str1, string str2)
{
    int len1 = str1.size();
    int len2 = str2.size();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    string resultStr;
    int flag = 0;
    for (int i = 0; i < len1; i++)
    {
        int temp = str1[i] - '0' + str2[i] - '0' + flag;
        temp = temp < 10 ?(flag=0, temp) : (flag = 1, temp - 10);
        resultStr += (temp+'0');
    }

    for (int j = len1; j < len2; j++)
    {
        int temp = str2[j] - '0' + flag;
        temp = temp < 10 ? (flag = 0, temp) : (flag = 1, temp - 10);
        resultStr += (temp + '0');
    }
    if (flag == 1)
        resultStr += '1';

    reverse(resultStr.begin(), resultStr.end());
    return resultStr;
}
int main()
{
    int count;
    while (cin >> count)
    {
        vector<string> input;
        for(int i = 0; i < count; i++) {
            string inputStr;
            cin >> inputStr;
            input.push_back(inputStr);
        }

        string resultStr = input[0];
        for(int k = 1; k < input.size(); k++) {
            if(resultStr.size() < input[k].size())
                resultStr = StrAdd(resultStr, input[k]);
            else
                resultStr = StrAdd(input[k], resultStr);
        }

        cout << resultStr << endl;
    }
    return 0;
}