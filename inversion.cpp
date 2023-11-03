#include <bits/stdc++.h>
using namespace std;

int n;
long long swapCount = 0;
vector<int> numList;

void input(){
    cin >> n;
    int num;
    for (int i = 0; i < n; i++){
        cin >> num;
        numList.push_back(num);
    }
}

void merge(vector<int>& arr, int leftIdx, int middleIdx, int rightIdx){
    int i, j;
    int n1 = middleIdx - leftIdx + 1;
    int n2 = rightIdx - middleIdx;
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);
    //Copy data to sub array
    for (i = 0; i < n1; i++){
        leftArr[i] = arr[leftIdx + i];
    }
    for (j = 0; j < n2; j++){
        rightArr[j] = arr[middleIdx + 1 + j];
    }
    //merge sub array
    i = 0; j = 0;
    int k = leftIdx;
    while(i < n1 && j < n2){
        if (leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
            swapCount += n1 - i;
        }
        k++;
    }
    while (i < n1){
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2){
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int leftIdx, int rightIdx){
    if (leftIdx < rightIdx){
        int middleIdx = leftIdx + (rightIdx - leftIdx) / 2;
        mergeSort(arr, leftIdx, middleIdx);
        mergeSort(arr, middleIdx + 1, rightIdx);
        merge(arr, leftIdx, middleIdx, rightIdx);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    mergeSort(numList, 0, n - 1);
    cout << swapCount;
    return 0;
}