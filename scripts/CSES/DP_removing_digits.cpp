#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define TC while (t--)
const ll MOD = 998244353;

vector<ll> find_digits(ll x)
{
    vector<ll> digits;
    while (x != 0)
    {
        digits.push_back(x % 10);
        x = x / 10;
    }
    return digits;
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        vector<ll> digits = find_digits(i);
        for (auto &elm : digits)
        {
            dp[i] = min(dp[i], dp[i - elm] + 1);
        }
    }
    cout << dp[n] << "\n";
}

int main()
{
    FASTIO
    ll t;
    t = 1;
    TC
    {
        solve();
    }
    return 0;
}
