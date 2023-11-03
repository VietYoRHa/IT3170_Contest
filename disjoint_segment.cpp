#include <bits/stdc++.h>
using namespace std;

typedef struct time_seg{
    int start_time;
    int finish_time;
} time_seg;

int n;
// int tryCount = 1;
int maxCount = 1;
vector<time_seg> timeList;

void input(){
    cin >> n;
    for (int i = 0; i < n; i++){
        time_seg time_tmp;
        cin >> time_tmp.start_time >> time_tmp.finish_time;
        timeList.push_back(time_tmp);
    }
}

bool compareStartTime (const time_seg& a, const time_seg& b){
    if (a.finish_time < b.finish_time) return true;
    else if (a.finish_time == b.finish_time) return a.start_time < b.start_time;
    return false;
}

// void Try(int k){
//     if (k == n - 1){
//         if (tryCount > maxCount) maxCount = tryCount;
//         tryCount = 1;
//         return;
//     }
//     for (int j = k + 1; j < n; j++){
//         if (timeList[k].finish_time <= timeList[j].start_time){
//             tryCount++;
//             Try(j);
//         }
//     }
//     Try(k + 1);
// }

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    input();
    sort(timeList.begin(), timeList.end(), compareStartTime);
    // Try(0);
    time_seg last = timeList[0];
    for (int i = 1; i < n; i++){
        if (last.finish_time < timeList[i].start_time){
            maxCount++;
            last = timeList[i];
        }
    }
    cout << maxCount;
    return 0;
}
