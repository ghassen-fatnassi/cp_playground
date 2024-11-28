#include <bits/stdc++.h>
using namespace std;
#define ll long long

class DSU
{
public:
    int n;
    vector<int> parent;
    vector<int> rank;

    DSU(int num_nodes)
    {
        n = num_nodes;
        parent.resize(n, -1);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    void union_set(int u, int v)
    {
        u = find_set(u);
        v = find_set(v);
        if (u != v)
        {
            if (rank[u] > rank[v])
            {
                swap(u, v);
            }
            parent[u] = v;
            if (rank[u] == rank[v])
            {
                rank[u]++;
            }
        }
    }
    int find_set(int u)
    {
        if (u == parent[u])
        {
            return u;
        }
        return parent[u] = find_set(parent[u]);
    }
};