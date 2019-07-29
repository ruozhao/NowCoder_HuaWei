#include<iostream>
#include<vector>
using namespace std;

int findIndex(vector<string> &sentence, string word) {
    int indexWord = 0;
    vector<string>::iterator it = sentence.begin();
    while(it != sentence.end()) {
        if(word > *it) {
            indexWord++;
            it++;
        } else {
            break;
        }
    }
    return indexWord;
}

int main() {
    int count;
    while(cin >> count) {
        string word;
        vector<string> sentence;
        for(int i = 0; i < count; i++) {
            cin >> word;
            if(sentence.size() == 0) {
                sentence.push_back(word);
            } else {
                int insertIndex = findIndex(sentence, word);
                sentence.insert(sentence.begin() + insertIndex, word);
            }
        }
        vector<string>::iterator it = sentence.begin();
        for(it; it != sentence.end(); it++) {
            cout << *it << endl;
        }
    }
    return 0;
}