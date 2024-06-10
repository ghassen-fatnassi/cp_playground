#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);
#define TC while (t--)
const int MOD = 1e9 + 7;

int main()
{
    FASTIO
    ll n;
    cin >> n;
    ll dp[n + 1];
    fill_n(dp, n + 1, 0);
    for (ll i = 1; i <= n; ++i)
    {
        ll mino = 1e10;
        string digits;
        digits = to_string(i);
        cout << digits << " ";
        for (char digit : digits)
        {
            ll num;
            string sta = "";
            sta += digit;
            num = stoll((sta));

            if (i - num >= 0)
            {
                cout << dp[i - num] << " ";
                mino = min(mino, dp[i - num]);
            }
        }
        dp[i] = mino + 1; // Corrected line
        cout << dp[i] << " \n";
    }
}
