#include <bits/stdc++.h>
using namespace std;

vector<int> coefficients;
int solutions = 0;

void solutionCount(int n, int M, int index){
    if (M == 0 && index == n){
        solutions++;
        return;
    }
    if (M < 0 || index == n) return;
    for (int x = 1; x <= M / coefficients[index]; x++){
        solutionCount(n, M - x*coefficients[index], index + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, M;
    int input;
    cin >> n >> M;
    for (int i = 0; i < n; i++){
        cin >> input;
        coefficients.push_back(input);
    }
    solutionCount(n, M, 0);
    cout << solutions << endl;
    return 0;
}