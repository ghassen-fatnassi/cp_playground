#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    std::ios_base::sync_with_stdio(false);
#define TC while (t--)

const int MOD = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    int a[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
    }
    int par[n + 1];
    par[1] = 1;
    for (int i = 0; i < n - 1; i++)
    {
        par[i + 2] = a[i];
    }
    int sub[n + 1];
    sub[1] = n - 1;
    
}

int main()
{
    int t;
    t = 1;
    cin >> t;
    TC
    {
        solve();
    }
}