#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TC while(t--)

const int MOD =1e9+7;

void dfs(vector<vector<int>>& graph, vector<vector<int>>& visited, int i, int j, int n, int m) {
    if (graph[i][j] != 0 && visited[i][j] == 0) {
        visited[i][j] = 1;
        if (j + 1 < m) { dfs(graph, visited, i, j + 1, n, m); }
        if (j - 1 >= 0) { dfs(graph, visited, i, j - 1, n, m); }
        if (i - 1 >= 0) { dfs(graph, visited, i - 1, j, n, m); }
        if (i + 1 < n) { dfs(graph, visited, i + 1, j, n, m); }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int>(m));
    vector<vector<int>> visited(n, vector<int>(m,0));
    char in;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> in;
            if (in == '.') { map[i][j] = 1; }
            else { map[i][j] = 0; }
        }
    }

    int rooms = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (visited[i][j] == 0 && map[i][j] == 1) {
                rooms++;
                dfs(map, visited, i, j, n, m);
            }
        }
    }

    cout<< rooms << endl;

    return 0;
}