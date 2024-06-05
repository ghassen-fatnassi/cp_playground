#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);
#define TC while (t--)
const int MOD = 1e9 + 7;

int divisors_count(ll x)
{
}

int main()
{
    FASTIO
    ll t;
    cin >> t;
    TC
    {
        ll l, r;
        cin >> l >> r;
        if (r - l != 0)
        {
            ll cc;
            if (r % 2 == 0)
            {
                cc = r;
            }
            else
            {
                cc = r - 1;
            }
        }
    }
}