#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);
#define TC while (t--)
const int MOD = 1e9 + 7;

void make_set(vector<int> &parent, int v)
{
    parent[v] = v;
}

int find_set(vector<int> &parent, int u)
{
    if (parent[u] == u)
    {
        return u;
    }
    return parent[u] = find_set(parent, parent[u]);
}

void union_sets(vector<int> &parent, int u, int v)
{
    int p_v = find_set(parent, v);
    int p_u = find_set(parent, u);
    if (p_u != p_v)
    {
        parent[p_u] = p_v;
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> parent(n, 0);
    for (int i = 0; i < n; i++)
    {
        make_set(parent, i);
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        union_sets(parent, a - 1, b - 1);
    }
    set<int> unique;
    for (int i = 0; i < n; i++)
    {
        unique.insert(find_set(parent, i));
    }
    cout << unique.size() - 1 << "\n";
    int first = -1;
    for (auto elm : unique)
    {
        if (first == -1)
        {
            first = elm;
        }
        else
        {
            cout << first + 1 << " " << elm + 1 << "\n";
        }
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    TC { solve(); }

    return 0;
}