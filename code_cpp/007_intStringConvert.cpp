#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;
int main()
{
    // int 转 string
    stringstream ss;
    int n = 123;
    string str;
    ss<<n;
    ss>>str;
    cout << str << endl;
    // string 转 int
    str = "456";
    n = atoi(str.c_str());
    cout << n << endl;

    return 0;
}