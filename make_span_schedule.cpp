#include <bits/stdc++.h>
using namespace std;

typedef struct AdjList{
    int size; // số lượng đỉnh kề
    int *list; // danh sách các đỉnh kề
} ADJ;

int *loadNodeWeighted(int n){
    int *weighted = (int*) malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
        cin >> weighted[i];
}

ADJ *loadAdjList(int n, int m){
    ADJ *lstAdj = (ADJ *) malloc(n * sizeof(ADJ));
    for (int i = 0; i< n; i++){
        lstAdj[i].size = 0;
        lstAdj[i].list = (int *) malloc(n * sizeof(int));
    }
    int preID = 0;
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        lstAdj[a - 1].list[lstAdj[a - 1].size] = b;
        lstAdj[a - 1].size++;
    }
    return lstAdj;
}

void loadData(int *n, int *m, int **weighted, ADJ **lstAdj){
    int n1, m1;
    cin >> n1 >> m1;
    *weighted = loadNodeWeighted(n1);
    *lstAdj = loadAdjList(n1, m1);
    *n = n1;
    *m = m1;
}
void process(int n, int m, int *weighted, ADJ *lstAdj){
    priority_queue<pair<int, int>> nextNodes;
    queue<pair<int, int>> timeline;

    // tính bậc các đỉnh
    int edgeDegree[n] = {0};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < lstAdj[i].size; j++){
            edgeDegree[lstAdj[i].list[j]]++;
        }
    }

    // đưa vào trong Heap
    for (int i = 0; i < n; i++){
        nextNodes.push({i, edgeDegree[i]});
    }
}

void print(int n, int m, int *weighted, ADJ *lstAdj){
    cout << n << " " << m << endl;
    for (int i = 0; i < n; i++) printf("%d ", weighted[i]);
    printf("\n");
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    int *weighted;
    ADJ *lstAdj;

    loadData(&n, &m, &weighted, &lstAdj);
    // print(n, m, weighted, lstAdj);

    return 0;
}