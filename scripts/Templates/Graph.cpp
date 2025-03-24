#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);
#define TC while (t--)
const int MOD = 1e9 + 7;

class Graph
{
public:
    int n;
    vector<vector<int>> g;
    vector<int> vis;
    vector<int> parent;
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
        g[v].push_back(u); // to be removed if the graph is oriented
    }
    void initialize()
    {
        for (int i = 0; i < n; i++)
        {
            vis[i] = 0;
            parent[i] = -1;
        }
    }
    void dfs(int src, int x)
    {
        for (auto node : g[src])
        {
            if (!vis[node])
            {
                if (1) /* condition here */
                {
                    // logic here
                }
                parent[node] = src;
                vis[node] = 1;
                dfs(node, x);
            }
        }
    }
};

class WeightedGraph
{
public:
    int n;
    vector<vector<pair<int, int>>> g;
    vector<int> vis;
    vector<int> parent;
    WeightedGraph(int num_nodes)
    {
        n = num_nodes;
        g.resize(n, vector<pair<int, int>>());
        vis.resize(n, 0);
        parent.resize(n, -1);
    }
    void insert(int u, int v, int weight)
    {
        g[u].push_back({v, weight});
        g[v].push_back({u, weight}); // to be removed if the graph is oriented
    }
    void initialize()
    {
        for (int i = 0; i < n; i++)
        {
            vis[i] = 0;
            parent[i] = -1;
        }
    }
    void dfs(int src, int x)
    {
        for (auto node : g[src])
        {
            if (!vis[node.first])
            {
                if (1 /* condition here */)
                {
                    // logic here
                }
                parent[node.first] = src;
                vis[node.first] = 1;
                dfs(node.first, x);
            }
        }
    }
};