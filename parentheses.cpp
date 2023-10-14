#include <bits/stdc++.h>
using namespace std;

bool checkBalance(string varStr){
    stack<char> st;
    for (char c : varStr){
        if (c == '('  || c == '[' || c == '{') st.push(c);
        else if (c == ')' || c == ']' || c == '}'){
            if (st.empty()) return false;
            char open = st.top();
            if (open == '(' && c != ')' || open == '[' && c != ']' || open == '{' && c != '}') return false;
            else st.pop();
        }
    }
    return st.empty();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string str;
    cin >> str;
    if (checkBalance(str)) cout << 1;
    else cout << 0;
    return 0;
}