#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int value, number, length;
    cin >> number >> length;
    for (int i = 0; i < number; i++){
        cin >> value;
        ostringstream strNum;
        strNum << setw(length) << setfill('0') << value;
        string str = strNum.str();
        cout << str << endl;
    }
    return 0;
}