#include <bits/stdc++.h>
using namespace std;

#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define ll long long
const int MOD = 998244353;

void find_subtree(int node, int parent, vector<vector<int>> &adj, vector<int> &subtree_size)
{
    int curr_size = 1;
    for (int child : adj[node])
    {
        if (child == parent)
        {
            continue;
        }
        find_subtree(child, node, adj, subtree_size);
        curr_size += subtree_size[child];
    }
    subtree_size[node] = curr_size;
}

void calc_dist(int node, int parent, vector<vector<int>> &adj, vector<ll> &total_dist, vector<int> &subtree_size)
{
    if (total_dist[node] == 0)
    {
        total_dist[node] = total_dist[parent] + (total_dist.size() - 2 * subtree_size[node]);
    }
    for (int child : adj[node])
    {
        if (child == parent)
        {
            continue;
        }
        calc_dist(child, node, adj, total_dist, subtree_size);
    }
}

void dfs(int node, int parent, vector<vector<int>> &adj, vector<ll> &root_dist)
{
    for (int child : adj[node])
    {
        if (child == parent)
        {
            continue;
        }
        root_dist[child] = root_dist[node] + 1;
        dfs(child, node, adj, root_dist);
    }
}

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 0 << endl;
    }
    else
    {

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
        vector<int> subtree_size(n, 0);
        vector<ll> total_dist(n, 0);

        find_subtree(0, -1, adj, subtree_size);
        vector<ll> root_dist(n, 0);
        dfs(0, -1, adj, root_dist);
        ll sum_root_dist = accumulate(root_dist.begin(), root_dist.end(), 0LL); // learned soemthing new today in c++ , 0LL :D
        total_dist[0] = sum_root_dist;
        calc_dist(0, -1, adj, total_dist, subtree_size);
        for (int i = 0; i < n; i++)
        {
            cout << total_dist[i] << " ";
        }
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
