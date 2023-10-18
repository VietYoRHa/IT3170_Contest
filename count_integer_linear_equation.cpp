#include <bits/stdc++.h>
using namespace std;

vector<int> coefficients;
int solutions = 0;

void solutionCount(int n, int M, int index){
    if (M == 0 && index == n){ // M = 0 and checked final coefficient
        solutions++;
        return;
    }
    if (M < 0 || index == n) return; // M < 0 during/finish checking or checked final coefficient
    for (int x = 1; x <= M / coefficients[index]; x++){
        solutionCount(n, M - x*coefficients[index], index + 1); // else call solve a2x2 + a3x3 + ... + anxn = M - a1x1
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
    solutionCount(n, M, 0); // call solve a1x1 + a2x2 + ... + anxn = M
    cout << solutions << endl;
    return 0;
}