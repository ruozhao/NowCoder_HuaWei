#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int len = 0;

    while(cin >> len) {
        int intArray[1000] = {0};
        int numInt = 0;
        while(numInt < len) {
            cin >> intArray[numInt];
            numInt++;
        }
        for(int i = 0; i < len; i++) {
            for(int j = 0; j < len; j++) {
                if(intArray[j] > intArray[i]) {
                    swap(intArray[i], intArray[j]);
                }
            }
        }

        for(int k = 0; k < len;) {
            cout << intArray[k] << endl;
            int num = 0;
            for(int i = k + 1; i < len; i++) {
                if(intArray[k] == intArray[i])
                    num++;
            }
            k = k + num + 1;
        }
    }
    return 0;
}