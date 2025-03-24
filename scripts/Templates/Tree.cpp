#include <bits/stdc++.h>
using namespace std;
#define ll long long

// this class is supposed to contain the following methods
// int n;cin>>n; to get the number of nodes in the tree
// Tree T(n); to construct the tree
// T.add(u,v) *k(pseudocode) ; insert k edges in the form of u,v where u is the parent of v
// T.initialize(x) ; where x is the node to be considered the root throughout the code
// T.lca(u,v) ; this returns the least common ancestor between u and v
// T.dist(u,v) ; this returns the distance between u and v in terms of edges (throughout the shortest path)
class Tree
{
public:
    vector<vector<int>> adj;
    vector<int> parent;
    vector<vector<int>> dp;
    int size;
    int log_size;
    Tree(int n)
    {
        size = n;
        adj.resize(size);
        parent.resize(size);
        log_size = (int)ceil(log(size));
        dp.resize(n, vector<int>(log_size));
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
        for (int i = 0; i < log_size; i++)
        {
            dp[0][i] = 0;
        }
        dp_dfs(0);
    }
    void dp_dfs(int x)
    {
        parent[x] = x;
        dp[x][0] = parent[x];
        for (int j = log_size; j > 0; j--)
        {
            dp[x][j] = dp[dp[x][j - 1]][j - 1]; // the "node up 2^j from x" is the "node up 2^(j-1) from the node up 2^(j-1) from x"
        }
        for (auto &y : adj[x])
        {
            if (parent[x] != y)
            {
                // logic here
                dp_dfs(y);
            }
        }
    }
    void lca(int u, int v)
    {
        // fix the problem of u and v not being same height
        // check case of u and v are same node after fixing height(v in the subtree of u or vice versa)
        // now suppose u and v same height and keep going
    }
    void dist(int u, int v)
    {
        // finds the distance (length of path ,in edges) between 2 nodes in the tree
    }
};