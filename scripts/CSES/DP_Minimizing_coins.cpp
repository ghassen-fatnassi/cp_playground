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
    a[0] = 0;
    fill_n(a, x + 1, -1);
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
    for (int curr = c[0] + 1; curr <= x; curr++)
    {
        if (a[curr] == -1)
        {
            ll least_prev = 1e10;
            for (int j = 0; j < n; j++)
            {
                if (curr - c[j] > 0 && a[curr - c[j]] + 1 != 0)
                {
                    if (a[curr - c[j]] < least_prev)
                    {
                        least_prev = a[curr - c[j]];
                    }
                }
            }
            if (least_prev == 1e10)
            {
                a[curr] = -1;
            }
            else
            {
                a[curr] = least_prev + 1;
            }
        }
    }
    cout << a[x] << "\n";
}