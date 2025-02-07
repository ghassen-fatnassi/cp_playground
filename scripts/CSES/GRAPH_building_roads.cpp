#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);
#define TC while (t--)
const int MOD = 1e9 + 7;

void make_set(vector<int> &parent, int v) { parent[v] = v; }
int find_set(vector<int> &parent, int u)
{
    if (parent[u] = u)
    {
        return u;
    }
    return parent[u] = find_set(parent, u);
}

void union_set(vector<int> &parent, int u, int v) {}

void solve()
{
    int n, m;
    cin >> n >> m;
}

int main()
{
    int t;
    // cin >> t;
    TC { solve(); }

    return 0;
}