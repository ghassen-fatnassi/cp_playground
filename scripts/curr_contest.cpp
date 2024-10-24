#include <bits/stdc++.h>
using namespace std;
#define TC while (t--)
#define ll long long
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
const int MOD = 1e9 + 7;

ll mod_exp(ll base, ll exp, ll mod)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void solve()
{
    int t;
    cin >> t;
    vector<ll> n(t);
    vector<ll> k(t);
    for (int i = 0; i < t; i++)
    {
        cin >> n[i];
    }
    for (int i = 0; i < t; i++)
    {
        cin >> k[i];
    }
    for (int i = 0; i < t; i++)
    {
        cout << mod_exp(2, k[i], MOD) << "\n";
    }
}

int main()
{
    FASTIO;
    int t = 1;
    TC
    {
        solve();
    }
    return 0;
}
