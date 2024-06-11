#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);
#define TC while (t--)
// #define MAXN 1e9
// vector<int> spf(MAXN + 1, 1);
const ll MOD = 998244353;

void solve()
{
    ll h, n;
    cin >> h >> n;
    ll a[n];
    ll c[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    ll l = 1;
    ll r = 4e10;
    ll mid = (l + r) / 2;
    while (l < r)
    {
        mid = (l + r) / 2;
        ll damage = 0;
        for (int i = 0; i < n; i++)
        {
            damage += a[i] * (mid / c[i] + (mid % c[i] != 0));
        }
        if (damage >= h)
        {
            r = mid; // Corrected line
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << r << "\n";
}

int main()
{
    FASTIO
    ll t;
    cin >> t;
    TC
    {
        solve();
    }
    return 0;
}
