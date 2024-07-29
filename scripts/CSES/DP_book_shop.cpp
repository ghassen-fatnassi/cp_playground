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
    ll n, x;
    cin >> n >> x;
    ll h[n]; // prices
    ll s[n]; // pages
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    ll dp[x + 1] = {0}; // dp[i] is the max pages we can get for amount of money i
    for (int i = 0; i < x + 1; i++)
    {
        dp[i] = 0;
    }
    for (int j = 0; j < n; j++) // going through all the prices in an ordered way, to make sure to not repeat the same book twice
    {
        for (int i = x; i > -1; i--) // checking the contributions of each book to the max number of pages we can get at a certain amount of money i
        {
            if (i >= h[j])
            {
                dp[i] = max(dp[i], dp[i - h[j]] + s[j]);
            }
        }
    }
    cout << dp[x] << "\n";
}
int main()
{
    FASTIO
    solve();
    return 0;
}
