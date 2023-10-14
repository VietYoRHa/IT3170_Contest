#include <bits/stdc++.h>
using namespace std;

int N;

string DecToBin(int n){
    string bin = "";
    while (n > 0){
        bin = char(n % 2 + '0') + bin;
        n = n/2;
    }
    while(bin.length() < N){
        bin = "0" + bin;
    }
    return bin;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    int i, N_2 = pow(2, N);
    for (i = 0; i < N_2; i++)
        cout << DecToBin(i) << endl;
    return 0;
}