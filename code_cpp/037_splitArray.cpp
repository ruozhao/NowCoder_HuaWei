#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int partition(vector<int> &array, int leftIndex, int rightIndex) {
    int i = leftIndex + 1;
    int j = rightIndex;
    int middle = array[leftIndex];
    while(i <= j) {
        while(array[i] < middle) {
            i++;
        }
        while(array[j] > middle) {
            j--;
        }

        if (i < j) {
            swap(array[i], array[j]);
            i++;
            j--;
        }
        else
            i++;
    }
    swap(array[leftIndex], array[j]);
    return j;
}
void quickSort(vector<int> &array, int leftIndex, int rightIndex) {
    if(leftIndex > rightIndex)
        return;
    int index = partition(array, leftIndex, rightIndex);

    quickSort(array, leftIndex, index - 1);
    quickSort(array, index + 1, rightIndex);
}

void divideArray(vector<int> &array, int sum, vector<int> &left, vector<int> &right) {
    int leftSum = 0;
    int rightSum = 0;
    int k = 0;
    while(k < array.size()) {
        if(leftSum < sum/2) {
            left.push_back(array[k]);
            leftSum += array[k];
            k++;
        } else
            break;
    }
    left.pop_back();
    leftSum -= array[k-1];
    for(k = k - 1; k < array.size(); k++) {
        right.push_back(array[k]);
        rightSum = rightSum + array[k];
    }
    cout << "leftSum is: " << leftSum << endl;
    cout << "rightSum is: " << rightSum << endl;
}

int main() {
    int len;
    while(cin >> len) {

        vector<int> inputArray;
        vector<int> left;
        vector<int> right;
        int value = 0;
        int sum = 0;
        for(int i = 0; i < len; i++) {
            cin >> value;
            inputArray.push_back(value);
            sum += value;
        }

        // 1. quick sort
        quickSort(inputArray, 0, len-1);
        cout << "Sorted array is: " << endl;
        for(int k = 0; k < inputArray.size(); k++) {
            cout << inputArray[k] << ", ";
        }
        cout << endl;

        // 2. divide array
        cout << "Sum is: " << sum << endl;
        divideArray(inputArray, sum, left, right);

        cout << "left is: " << endl;
        int k = 0;
        for(k = 0; k < left.size(); k++) {
            cout << left[k] << ", ";
        }
        cout<<endl;
        cout << "right is: " << endl;
        for(k = 0; k < right.size(); k++) {
            cout << right[k] << ", ";
        }

    }
    return 0;
}

