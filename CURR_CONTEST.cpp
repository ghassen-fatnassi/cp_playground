#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);
#define TC while (t--)
const int MOD = 1e9 + 7;

long long puiss(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res *= a;
            res = res;
        }
        a = a * a;
        b = b / 2;
    }
    return res;
}
int main()
{
    FASTIO
    ll t;
    cin >> t;
    TC
    {
        ll x, y;
        cin >> x >> y;
        ll ix;
        ll iy;
        ll curr = 0;
        ll i = 0;
        while (curr == 0)
        {
            ix = x % 2;
            iy = y % 2;
            curr = abs(ix - iy);
            i++;
            x = x / 2;
            y = y / 2;
        }
        cout << puiss(2, i - 1) << "\n";
    }
}