#include <bits/stdc++.h>
using namespace std;

struct CallDetail {
    string from_number;
    string to_number;
    string date;
    string from_time;
    string end_time;
};

vector<CallDetail> calllogs;
int phonecount = 0;
int total_calls = 0;

int countTime(string ftime, string etime){
    stringstream time1(ftime);
    stringstream time2(etime);
    char sp = ':';
    int fhour, fmin, fsec;
    int ehour, emin, esec;
    time1 >> fhour >> sp >> fmin >> sp >> fsec;
    time2 >> ehour >> sp >> emin >> sp >> esec;
    int startTime = fhour * 3600 + fmin * 60 + fsec;
    int endTime = ehour * 3600 + emin * 60 + esec;
    return endTime - startTime;
}

bool check_phone_number(){
    for (int i = 0; i < calllogs.size(); i++){
        if(calllogs[i].from_number.length() != 10 || calllogs[i].to_number.length() != 10) return false;
        for (int j = 0; j < 10; j++){
            if (!isdigit(calllogs[i].from_number.at(j))) return false;
            if (!isdigit(calllogs[i].to_number.at(j))) return false;
        }
    }
    return true;
};

void number_calls_from(string phone){
    phonecount = 0;
    for (int i = 0; i < calllogs.size(); i++){
        if (calllogs[i].from_number == phone) phonecount++;
    }
};

void count_time_calls_from(string phone){
    int time_call, total_time_call = 0;
    for (int i = 0; i < calllogs.size(); i++){
        if (calllogs[i].from_number == phone){
            time_call = countTime(calllogs[i].from_time, calllogs[i].end_time);
            total_time_call = total_time_call + time_call;
        };
    }
    cout << total_time_call << endl;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string option;
    string phone;
    do{
        cin >> option;
        if (option == "#") break;
        else{
            CallDetail call;
            cin >> call.from_number >> call.to_number >> call.date >> call.from_time >> call.end_time;
            calllogs.push_back(call);
            total_calls++;
        }
    }while (1);
    do{
        cin >> option;
        if (option == "#") break;
        else{
            if(option == "?check_phone_number"){
                if(check_phone_number()){
                    cout << 1 << endl;
                    continue;
                }
                else{
                    cout << 0 << endl;
                    break;
                };
            }
            if(option == "?number_calls_from"){
                cin >> phone;
                number_calls_from(phone);
                cout << phonecount << endl;
                continue;
            }
            if(option == "?number_total_calls"){
                cout << total_calls << endl;
                continue;
            }
            if(option == "?count_time_calls_from"){
                cin >> phone;
                count_time_calls_from(phone);
                continue;
            }
        }
    }while (1);
    return 0;
}

