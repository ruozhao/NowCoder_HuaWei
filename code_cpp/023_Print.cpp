#include<iostream>
#include<vector>

using namespace std;

void printOrder(vector<int> &input, int len, vector<int> &output) {
    vector<int>::iterator it = input.begin();
    for(it; it != input.end(); it++) {
        int upperNum = 0;
        vector<int>::iterator in = input.begin();
        for(in; in != input.end(); in++) {
            if(*in > *it) {
                upperNum++;
            }
            cout << *it << ", " << *in << endl;
        }
        output.push_back(upperNum);
    }
}

int main() {
    int inputNumber;
    while(cin >> inputNumber) {
        vector<int> input;
        input.push_back(inputNumber);
        while (cin >> inputNumber) {
            input.push_back(inputNumber);
        }
        vector<int> output;
        printOrder(input, input.size(), output);

        vector<int>::iterator it = output.begin();
        int count = output.size();
        for(it; it != output.end(); it++) {
            cout << *it;
            count--;
            if (count != 0)
                cout << ", ";
            else
                cout << endl;
        }
    }
    return 0;
}