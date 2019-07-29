#include <iostream>
#include <string>

using namespace std;
void handle(string &s);
int main() {
    string str1, str2;
    while(cin >> str1 >> str2) {
        handle(str1);
        handle(str2);
    }
    return 0;
}

void handle(string &s) {
    if(s.size() <= 8) {
        s.append(8 - s.size(), '0');
        cout << s << endl;
    } else {
        cout << s.substr(0, 8) << endl;
        string str = s.substr(8);
        handle(str);
    }
}