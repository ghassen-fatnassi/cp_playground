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
    int cycle;

    Graph(int num_nodes)
    {
        n = num_nodes;
        g.resize(n, vector<int>());
        vis.resize(n, 0);
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
        }
        cycle = 0;
    }
    void bfs(int src)
    {
        deque<int> q;
        q.push_back(src);
        vis[src] = 1;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop_front();
            for (int child : g[curr])
            {
                if (vis[child] == 0)
                {
                    q.push_back(child);
                    vis[child] = 3 ^ vis[curr];
                }
                else if ((3 ^ vis[curr]) != vis[child])
                {
                    cycle = 1;
                    return;
                }
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
            city.bfs(i);
        }
        if (city.cycle == 1)
        {
            break;
        }
    }
    if (city.cycle == 1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        for (int i = 0; i < n; ++i)
        {
            cout << city.vis[i] << " ";
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
