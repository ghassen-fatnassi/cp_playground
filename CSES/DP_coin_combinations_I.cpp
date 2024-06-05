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
    ll a[x + 1];
    fill_n(a, x + 1, 0);
    ll c[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        if (c[i] <= x)
        {
            a[c[i]] = 1;
        }
    }
    sort(c, c + n);
    for (int curr = c[0]; curr <= x; curr++)
    {
        ll ways = a[curr];
        for (int j = 0; j < n; j++)
        {
            if (curr - c[j] > 0)
            {
                ways += a[curr - c[j]];
            }
        }
        a[curr] = ways % MOD;
    }
    cout << a[x] % MOD << "\n";
}