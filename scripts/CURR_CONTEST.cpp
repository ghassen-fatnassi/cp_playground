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
    ll n, m, s;
    cin >> n >> m >> s;
    ll out = 0;
    ll one = 1;
    if (s < m && s < n)
    {
        ll coeff = 0;
        if (m % s == 0 && n % s == 0)
        {
            coeff = s * s;
        }
        else if (m % s == 0)
        {
            coeff = s * (n % s);
        }
        else if (n % s == 0)
        {
            coeff = s * (m % s);
        }
        else
        {
            coeff = (n % s) * (m % s);
        }
        ll val = (((((n - s) + (s - 1)) / s) + 1) * ((((m - s) + (s - 1)) / s) + 1));
        out = val * coeff;
    }
    else if (s < m)
    {
        out = (n % s) * (((m - s) + (s - 1)) / s + 1);
    }
    else if (s < n)
    {
        out = (m % s) * (((n - s) + (s - 1)) / s + 1);
    }
    else
    {
        out = n * m;
    }
    cout << out << "\n";
}

int main()
{
    FASTIO
    ll t;
    // cin >> t;
    t = 1;
    TC
    {
        solve();
    }
    return 0;
}