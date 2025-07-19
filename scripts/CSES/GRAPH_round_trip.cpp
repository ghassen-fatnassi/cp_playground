#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define TC while (t--)
const ll MOD = 998244353;

class Graph
{
public:
    int n;
    vector<vector<int>> g;
    vector<int> vis;
    vector<int> parent;
    int NOD = -1;

    Graph(int num_nodes)
    {
        n = num_nodes;
        g.resize(n, vector<int>());
        vis.resize(n, 0);
        parent.resize(n, -1);
    }
    void insert(int u, int v)
    {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void initialize()
    {
        for (int i = 0; i < n; i++)
        {
            vis[i] = 0;
            parent[i] = -1;
        }
    }
    void dfs(int src)
    {
        for (auto node : g[src])
        {
            if (NOD != -1)
            {
                return;
            }
            else if (vis[node] && node != parent[src])
            {
                parent[node] = src;
                NOD = node;
            }
            else if (!vis[node])
            {
                parent[node] = src;
                vis[node] = 1;
                dfs(node);
            }
        }
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    Graph city(n);
    city.initialize();
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        city.insert(a, b);
    }
    for (int i = 0; i < n; ++i)
    {
        if (city.vis[i] == 0)
        {
            city.vis[i] = 1;
            city.dfs(i);
            if (city.NOD != -1)
            {
                break;
            }
        }
    }
    if (city.NOD == -1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        vector<int> path;
        path.push_back(city.NOD);
        int curr = city.parent[city.NOD];
        while (curr != city.NOD)
        {
            path.push_back(curr);
            curr = city.parent[curr];
        }
        ll l = path.size();
        cout << l + 1 << "\n";
        for (ll i = 0; i <= l; ++i)
        {
            cout << path[i % l] + 1 << " ";
        }
    }
}

int main()
{
    FASTIO
    ll t;
    t = 1;
    // cin>>t;
    TC
    {
        solve();
    }
    return 0;
}
