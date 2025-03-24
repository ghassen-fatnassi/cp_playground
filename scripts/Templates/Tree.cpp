#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Tree
{
public:
    vector<vector<int>> adj;
    Tree(int n)
    {
        adj.resize(n);
    }
    void add(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void init()
    {
    }
};