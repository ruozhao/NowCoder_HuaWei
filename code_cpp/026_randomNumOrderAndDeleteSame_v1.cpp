#include<iostream>
#include<vector>
using namespace std;
void insertAndSort(int input, vector<int> &inputArr) {
    if(inputArr.size() == 0) {
        inputArr.push_back(input);
        return;
    }

    int i = 0;
    while(i < inputArr.size()) {
        if(input == inputArr[i]) {
            return;
        }
        if(input > inputArr[i]) {
            i++;
        } else {
            inputArr.insert(inputArr.begin() + i, input);
            return;
        }
    }
    if(i == inputArr.size()) {
        inputArr.push_back(input);
    }
    return;
}
int main() {
    int count = 0;
    while(cin >> count) {
        vector<int> inputArr;
        int input;
        for(int i = 0; i < count; i++) {
            cin >> input;
            insertAndSort(input, inputArr);
        }
        for(int i = 0; i < inputArr.size(); i++) {
            cout << inputArr[i] << endl;
        }
    }
    return 0;
}