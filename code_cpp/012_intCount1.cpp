#include<iostream>

using namespace std;
int main() {
    int inputInt;
    while(cin >> inputInt) {
        int count = 0;
        while(inputInt) {
            if(inputInt % 2)
                count++;
            inputInt = inputInt >> 1;
        }
        cout << count << endl;
    }
    return 0;
}