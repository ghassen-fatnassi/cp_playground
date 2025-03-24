#include <bits/stdc++.h>
using namespace std;

#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);

struct Move
{
    int di, dj;
    char dir;
};

vector<Move> moves = {{-1, 0, 'U'}, {1, 0, 'D'}, {0, -1, 'L'}, {0, 1, 'R'}};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> G(n, vector<char>(m));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> direction(n, vector<char>(m, ' '));

    int ai = -1, aj = -1, bi = -1, bj = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> G[i][j];
            if (G[i][j] == 'A')
            {
                ai = i;
                aj = j;
            }
            if (G[i][j] == 'B')
            {
                bi = i;
                bj = j;
            }
        }
    }

    if (ai == -1 || aj == -1 || bi == -1 || bj == -1)
    {
        cout << "NO\n";
        return;
    }

    queue<pair<int, int>> q;
    q.push({ai, aj});
    visited[ai][aj] = 1;

    while (!q.empty())
    {
        auto [ci, cj] = q.front();
        q.pop();

        for (auto [di, dj, dir] : moves)
        {
            int ni = ci + di, nj = cj + dj;
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && G[ni][nj] != '#')
            {
                visited[ni][nj] = 1;
                parent[ni][nj] = {ci, cj};
                direction[ni][nj] = dir;
                q.push({ni, nj});
                if (G[ni][nj] == 'B')
                {
                    string path;
                    while (ni != ai || nj != aj)
                    {
                        path += direction[ni][nj];
                        tie(ni, nj) = parent[ni][nj];
                    }
                    reverse(path.begin(), path.end());
                    cout << "YES\n"
                         << path.size() << "\n"
                         << path << "\n";
                    return;
                }
            }
        }
    }

    cout << "NO\n";
}

int main()
{
    FASTIO
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
