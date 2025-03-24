#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);
#define TC while (t--)
const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int parent[n];
    pair<int, int> Tree[4 * n];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        parent[i] = x - 1;
    }
}

int main()
{
    FASTIO;
    int t = 1;
    // cin >> t;
    TC { solve(); }

    return 0;
}
