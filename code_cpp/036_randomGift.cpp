#include<iostream>
#include<map>
#include<cmath>
using namespace std;

int main() {

    map<int, int> child;

    for (int i = 1; i <= 10;)
    {
        int value = ceil(random() * 10);
        cout << "value is = " << value << endl;
        bool flag = false;

        for (map<int, int>::iterator it = child.begin(); it != child.end(); it++)
        {
            if(it -> second == value) {
                flag = true;
                break;
            }
        }
        if(flag || i == value) {
            value = ceil(random() * 10);
        } else {
            child[i] = value;
            i++;
        }

    }

    for (map<int, int>::iterator kk = child.begin(); kk != child.end(); kk++)
    {
        cout << kk -> first << " => " << kk -> second << endl;
    }

    return 0;
}