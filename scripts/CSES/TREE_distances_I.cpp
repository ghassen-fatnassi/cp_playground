#include <bits/stdc++.h>
using namespace std;

#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define ll long long
const int MOD = 998244353;

void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &dist)
{
    for (int child : adj[node])
    {
        if (child == parent)
        {
            continue;
        }
        dist[child] = dist[node] + 1;
        dfs(child, node, adj, dist);
    }
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
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> distA(n), distB(n);
    distA[0] = 0;
    dfs(0, -1, adj, distA); // to find first endpoint of diameter

    int A = max_element(distA.begin(), distA.end()) - distA.begin();
    distA[A] = 0;
    dfs(A, -1, adj, distA); // to find the second endpoint of diameter

    int B = max_element(distA.begin(), distA.end()) - distA.begin();
    distB[B] = 0;
    dfs(B, -1, adj, distB);
    for (int i = 0; i < n; i++)
    {
        cout << max(distB[i], distA[i]) << " ";
    }
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
