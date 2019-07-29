#include<iostream>
#include<vector>
using namespace std;
int main() {
    string words;
    vector<string> sentence;
    while(cin >> words) {
        sentence.push_back(words);
    }

    vector<string>::iterator it = sentence.end() - 1;
    for(it; it != sentence.begin(); it--) {
        cout << *it << " ";
    }
    cout << *it << endl;
    return 0;
}