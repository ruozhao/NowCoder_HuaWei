#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main() {
    int count;
    while(cin >> count) {
        vector<int> position;
        for(int i = 0; i < count; i++) {
            int temp;
            cin >> temp;
            position.push_back(temp);
        }

        int moveVal;
        int result = 0;
        for(int i = 1; i < position.size() - 1; i++) {
            moveVal = position[i];
            cout << "Moved value is " << moveVal << endl;


            int temRes = 0;
            for(int j = 1; j < position.size(); j++) {
                if(j == i) {
                   position[j] = position[j-1];
                }
                temRes += abs(position[j] - position[j-1]);
            }
            cout << "temp moved step is " << temRes << endl;
            position[i] = moveVal;
            if(i == 1) {
                result = temRes;
            } else if(temRes < result) {
                result = temRes;
            }
        }
        cout << "The most little step is " << result << endl;
    }
    return 0;
}