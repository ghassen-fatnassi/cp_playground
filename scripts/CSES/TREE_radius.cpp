#include <bits/stdc++.h>
using namespace std;
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define ll long long

const int MOD = 998244353;

pair<int, int> dfs(int node, int parent, vector<vector<int>> &adj)
{
    int max = -1;
    int index = node;
    for (auto child : adj[node])
    {
        if (child == parent)
        {
            continue;
        }
        auto out = dfs(child, node, adj);
        if (out.second > max)
        {
            index = out.first;
            max = out.second;
        }
    }
    return {index, max + 1};
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    auto Apair = dfs(0, -1, adj);
    auto Bpair = dfs(Apair.first, -1, adj);
    cout << Bpair.second << endl;
}

int main()
{
    FASTIO
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
