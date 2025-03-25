#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);
#define TC while (t--)
const int MOD = 998244353;

void dfs(int root, vector<int> &subtreesize, vector<vector<int>> &children, vector<int> &parent)
{
    int subs = children[root].size();
    for (auto child : children[root])
    {

        dfs(child, subtreesize, children, parent);
        subs += subtreesize[child];
    }
    subtreesize[root] = subs;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> subtreesize(n + 1);
    vector<vector<int>> children(n + 1);
    vector<int> parent(n + 1);
    parent[1] = 1;
    int curr;
    for (int i = 2; i <= n; i++)
    {
        cin >> curr;
        children[curr].push_back(i);
        parent[i] = curr;
    }
    dfs(1, subtreesize, children, parent);
    for (int i = 1; i < n + 1; i++)
    {
        cout << subtreesize[i] << " ";
    }
}

int main()
{
    FASTIO
    int t = 1;
    // cin >> t;
    TC { solve(); }
    return 0;
}