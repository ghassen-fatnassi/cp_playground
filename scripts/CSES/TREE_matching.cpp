#include <bits/stdc++.h>
using namespace std;

#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define ll long long

void dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &matched, int &matchings)
{
    for (int child : adj[node])
    {
        if (child == parent)
        {
            continue;
        }

        dfs(child, node, adj, matched, matchings);

        if (!matched[node] && !matched[child])
        {
            matched[node] = matched[child] = true;
            matchings++;
        }
    }
}

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> matched(n + 1, false);
    int matchings = 0;

    dfs(1, -1, adj, matched, matchings);

    cout << matchings << endl;
}

int main()
{
    FASTIO
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
