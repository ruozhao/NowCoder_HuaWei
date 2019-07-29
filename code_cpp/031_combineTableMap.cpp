#include<iostream>
#include<map>

using namespace std;

int main() {
    int num;
    while(cin >> num) {
        map<int, int> mapTable;
        for(int i = 0; i < num; i++) {
            int key, value;
            cin >> key >> value;
            map<int, int>::iterator storedIter = mapTable.find(key);
            if(mapTable.end() != storedIter) {
                key = storedIter->first;
                value = storedIter->second + value;
            }
            mapTable[key] = value;
        }
        map<int, int>::iterator j = mapTable.begin();
        for(; j != mapTable.end(); j++) {
            cout << j->first << " " << j->second << endl;
        }
    }
    return 0;
}


// https://www.cnblogs.com/omelet/p/6617362.html
// https://blog.csdn.net/sevenjoin/article/details/81943864