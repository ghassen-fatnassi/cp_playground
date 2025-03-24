#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);
#define TC while (t--)
const int MOD = 1e9 + 7;

bool bfs(vector<vector<int>> &G, vector<int> &vis, vector<int> &parent, int start)
{
    queue<int> q;
    q.push(start);
    vis[start] = 1;

    while (!q.empty())
    {
        int curr_node = q.front();
        q.pop();

        for (int child : G[curr_node])
        {
            if (!vis[child])
            {
                vis[child] = 1;
                parent[child] = curr_node;
                q.push(child);

                if (child == G.size() - 1)
                    return true;
            }
        }
    }
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    vector<int> parent(n, -1);
    vector<int> vis(n, 0);
    vector<int> path;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a - 1].push_back(b - 1);
        G[b - 1].push_back(a - 1);
    }

    bool found = bfs(G, vis, parent, 0);

    if (!found)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    int curr = n - 1;
    while (curr != -1)
    {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int node : path)
    {
        cout << node + 1 << " ";
    }
    cout << "\n";
}

int main()
{
    FASTIO;
    int t = 1;
    // cin >> t;
    TC { solve(); }

    return 0;
}
