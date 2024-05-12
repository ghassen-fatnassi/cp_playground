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
    ll n, x;
    cin >> n >> x;
    ll a[n];
    ll dp[x] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    dp[a[0]] = 1;
    ll ans = 0;
    for (int i = a[i]; i < x; i++)
    {
        for (int j = 0; i < n; j++)
        {
            if (a[j] < i)
            {
                dp[i] += dp[i - a[j]];
                ans += dp[i];
            }
        }
    }
    cout << ans << "\n";
    return 0;
}