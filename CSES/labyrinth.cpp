#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TC while (t--)

const int MOD = 1e9 + 7;

string path_out = "NO";

void bfs(vector<vector<char>> &graph, vector<vector<int>> &visited, int i, int j, int n, int m, string path_in, queue<pair<int, int>> *Q)
{
    while (!(*Q).empty())
    {
        pair<int, int> curr = (*Q).front();
        (*Q).pop();
        if (graph[curr.first][curr.second] == 'B')
        {
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> map(n, vector<char>(m));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> Q;
    char in;
    int ia, ja;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> in;
            map[i][j] = in;
            if (in == 'A')
            {
                ia = i;
                ja = j;
            }
        }
    }
    Q.push((ia, ja));
    string initt = "";
    bfs(map, visited, ia, ja, n, m, initt, &Q);
    if (path_out == "NO")
    {
        cout << path_out;
    }
    else
    {
        cout << "YES"
             << "\n"
             << path_out.size() << "\n"
             << path_out;
    }
    return 0;
}