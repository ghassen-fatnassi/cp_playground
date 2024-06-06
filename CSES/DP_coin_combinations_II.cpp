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
    a[0] = 1;
    ll c[n];
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    sort(c, c + n);
    for (int j = 0; j < n; j++)
    {
        for (int curr = c[0]; curr <= x; curr++)
        {
            if (curr - c[j] >= 0)
            {
                a[curr] += a[curr - c[j]] % MOD;
                a[curr] = a[curr] % MOD;
            }
        }
    }
    cout << a[x] % MOD << "\n";
}
