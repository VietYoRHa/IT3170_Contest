#include <bits/stdc++.h>
using namespace std;

vector<int> numberList;
int idx = 0;

bool checkExist(vector<int> list, int num){
    auto listStart = list.begin() + idx;
    return binary_search(listStart, list.end(), num);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int subx, n, M, Q = 0, x = 0;
    int i;
    cin >> n >> M;
    numberList.reserve(n);
    for (i = 0; i < n; i++){
        cin >> x;
        numberList.push_back(x);
    }
    sort(numberList.begin(), numberList.end());
    auto it = lower_bound(numberList.begin(), numberList.end(), M / 2);
    idx = distance(numberList.begin(), it);
    for (i = 0; i < idx; i++){
        subx = M - numberList[i];
        if (checkExist(numberList, subx)) Q++;
    }
    cout << Q;
    return 0;
}