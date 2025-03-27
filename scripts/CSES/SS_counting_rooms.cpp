#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TC while (t--)

const int MOD = 1e9 + 7;
ll ans = 0;
void dfs(vector<vector<int>> &graph, vector<vector<int>> &visited, int i, int j, int n, ll last)
{
    if (visited[i][j] == 0)
    {
        visited[i][j] = 1;
        if (graph[i][j] == last)
        {
            ans++;
            graph[i][j] = abs(1 - graph[i][j]);
        }
        last = graph[i][j];
        if (j + 1 < n)
        {

            dfs(graph, visited, i, j + 1, n, last);
        }
        if (j - 1 >= 0)
        {
            dfs(graph, visited, i, j - 1, n, last);
        }
        if (i - 1 >= 0)
        {
            dfs(graph, visited, i - 1, j, n, last);
        }
        if (i + 1 < n)
        {
            dfs(graph, visited, i + 1, j, n, last);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    vector<vector<int>> visited(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> grid[i][j];
        }
    }
    dfs(grid, visited, 0, 0, n, abs(1 - grid[0][0]));
    cout << ans << "\n";

    return 0;
}