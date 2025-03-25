#include <bits/stdc++.h>
using namespace std;
#define ll long long
// all of the commendts are mine btw :D
//  this class is supposed to contain the following methods
//  int n;cin>>n; to get the number of nodes in the tree
//  Tree T(n); to construct the tree
//  T.add(u,v) *k(pseudocode) ; insert k edges in the form of u,v where u is the parent of v
//  T.initialize(x) ; where x is the node to be considered the root throughout the code
//  T.lca(u,v) ; this returns the least common ancestor between u and v
//  T.dist(u,v) ; this returns the distance between u and v in terms of edges (throughout the shortest path)
class Tree
{
public:
    vector<vector<int>> adj; // the main DS for the tree
    vector<int> parent;      // will help in dfs
    vector<int> height;      // will be useful in making nodes same height
    vector<vector<int>> dp;  // the main DS for binary lifting
    int size;                // number of nodes in the tree
    int log_size;            // (int)ceil(log(numer of nodes))
    Tree(int n)
    {
        size = n;
        adj.resize(size);
        parent.resize(size, -1);
        height.resize(size, 0);
        log_size = (int)ceil(log(size));
        dp.resize(n, vector<int>(log_size, 0)); // init to 0 since it's gonna be the root node
    }
    void add(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // this function is supposed to fill in the dp 2D array
    void init()
    {
        parent[0] = 0;
        dp_dfs(0);
    }
    void dp_dfs(int x)
    {
        dp[x][0] = parent[x];
        for (int j = 1; j <= log_size; j--)
        {
            dp[x][j] = dp[dp[x][j - 1]][j - 1]; // the "node up 2^j from x" is the "node up 2^(j-1) from the node up 2^(j-1) from x"
        }
        for (auto &y : adj[x])
        {
            if (parent[x] != y)
            {
                parent[y] = x;
                height[y] = height[x] + 1;
                dp_dfs(y);
            }
        }
    }
    int lca(int u, int v)
    {
        //  fix the problem of u and v not being same height
        if (height[v] > height[u])
        {
            swap(u, v);
        }
        // from now on we'll suppose height[u]>==height[v]
        for (int i = log_size; i >= 0; i--)
        {
            if ((1 << i) <= height[u] - height[v])
            {
                u = dp[u][i];
            }
        }
        //  check case of u and v are same node after fixing height(v in the subtree of u or vice versa)
        if (u == v)
        {
            return u;
        }
        //  now suppose u and v same height and keep going
        for (int i = log_size; i >= 0; i--)
        {
            if (dp[u][i] != dp[v][i])
            {
                u = dp[u][i];
                v = dp[v][i];
            }
        }
        return parent[u];
    }
    int dist(int u, int v)
    {
        // finds the distance (length of path ,in edges) between 2 nodes in the tree
        return 2 * height[lca(u, v)] - height[u] - height[v];
    }
};