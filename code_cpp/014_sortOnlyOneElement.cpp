#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;
int main() {
    int count;
    while(cin >> count) {
        map<int, int> mapInput;
        vector<int> vecInput;
        for(int i = 0; i < count; i++) {
            int tempIn;
            cin >> tempIn;
            mapInput[tempIn] = i;
            vecInput.push_back(tempIn);
        }

        sort(vecInput.begin(), vecInput.end());

        int num = 0;
        int index = count;
        for(int i = 0; i < count - 1; i++) {
            if(mapInput[vecInput[i]] > mapInput[vecInput[i + 1]]) { // 已经排好序的数组(vector中保存)： 前一个数A 小于 后一个数B
                                                                    // 但是 输入的数组顺序(map中保存)： 前一个数A 后于 后一个数B
                                                                    // 因此 后一个数B要在原序列中被拉出来插入到数组最后
                                                                    // yinci     后一个数B的输入顺序 设置为  原序列长度+1
                num++;
                mapInput[vecInput[i+1]] = index;
                index++;
                // cout << "move " << vecInput[i+1] << endl;
            }
        }
        cout << num << endl;    // adjust count

        // show the sorted list value
        // map<int, int>::iterator it = mapInput.begin();
        // for(it; it != mapInput.end(); it++) {
        //     cout << it->first << ", " << it->second << endl;
        // }
        // cout << endl;
    }
    return 0;
}