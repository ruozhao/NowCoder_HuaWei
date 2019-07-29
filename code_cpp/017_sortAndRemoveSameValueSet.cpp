#include<iostream>
#include<set>
using namespace std;

int main() {
    int count;
    while(cin >> count) {
        set<int> position;
        for(int i = 0; i < count; i++) {
            int temp;
            cin >> temp;
            position.insert(temp);
        }

        if(position.size() < 3) {
            cout << -1 << endl;
            break;
        }

        set<int>::iterator j = position.begin();
        int pos = 1;
        while(j != position.end()) {
            if(pos == 3) {
                cout << *j << endl;
                break;
            }
            j++;
            pos++;
        }
    }
    return 0;
}


// https://www.cnblogs.com/omelet/p/6627667.html