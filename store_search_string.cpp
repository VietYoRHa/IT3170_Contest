#include <bits/stdc++.h>
using namespace std;

vector<string> strSearch;

bool checkExist (vector<string> strCheck, string wordCheck){
    return binary_search(strCheck.begin(), strCheck.end(), wordCheck);
}

void findOption(string wordData){
    bool check = checkExist(strSearch, wordData);
    if (check) cout << 1 << endl;
    else cout << 0 << endl;
}

void insertOption(string wordData){
    bool check = checkExist(strSearch, wordData);
    if (check) cout << 0 << endl;
    else {
        strSearch.push_back(wordData);
        sort(strSearch.begin(), strSearch.end());
        cout << 1 << endl;
    }
}

int main(){
    string input, option = "";
    do {
        cin >> input;
        if (input == "*") break;
        else strSearch.push_back(input);
    } while (true);
    sort(strSearch.begin(), strSearch.end());
    do {
        cin >> option;
        if (option == "***") break;
        cin >> input;
        if (option == "find") findOption(input);
        else insertOption(input);
    } while (true);
    return 0;
}