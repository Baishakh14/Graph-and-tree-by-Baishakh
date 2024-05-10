#include<bits/stdc++.h>
using namespace std;

#define n 100001

vector<int> graph[n];

void dfs() {
    for (int i = 0; i < n; i++) {
        if (!graph[i].empty()) {
            cout << i << " -> ";
            for (int j = 0; j < graph[i].size(); j++) {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int node, edge;
    cin >> node >> edge;

    for (int i = 0; i < edge; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    dfs();

    return 0;
}
