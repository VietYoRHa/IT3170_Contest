#include<bits/stdc++.h>
using namespace std;

vector<string> dateVector;

int timeCalculate(string tTime){
    stringstream sTTime(tTime);
    char sp = ':';
    int tHour, tMin, tSec;
    sTTime >> tHour >> sp >> tMin >> sp >> tSec;
    return tHour*3600 + tMin*60 + tSec;
}

string timeReverseCal(int tTime){
    int tHour = tTime / 3600;
    int tMin = (tTime % 3600) / 60;
    int tSec = (tTime % 3600) % 60;
    string s1 = to_string(tHour);
    string s2 = to_string(tMin);
    string s3 = to_string(tSec);
    if (s1.length() < 2) s1 = string(1, '0') + s1;
    if (s2.length() < 2) s2 = string(1, '0') + s2;
    if (s3.length() < 2) s3 = string(1, '0') + s3;
    string result = s1 + ":" + s2 + ":" + s3;
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string input;
    int i;
    do{
        getline(cin, input);
        if (input == "*") break;
        dateVector.push_back(input);
    }while (input != "*");
    do{
        getline(cin, input);
        if (input == "***") break;
        string taskDate, sTaskTime, sTaskDuration;
        istringstream iss(input);
        iss >> taskDate >> sTaskTime >> sTaskDuration;
        int taskTime = timeCalculate(sTaskTime);
        int taskDuration = stoi(sTaskDuration);
        int total = taskTime + taskDuration;
        for (i = 0; i < dateVector.size(); i++){
            if (dateVector[i] == taskDate) break;
        }
        int finishDate = i + (total / 86400);
        int finishTime = total % 86400;
        string sFinishTime = timeReverseCal(finishTime);
        cout << dateVector[finishDate] << ' ' << sFinishTime << endl;
    }while (input != "***");
    return 0;
}