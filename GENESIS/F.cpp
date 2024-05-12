#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);
#define TC while (t--)
const int MOD = 998244353;
ll paths = 0;
void rec(ll curr_sum, ll rest, ll half, ll x)
{
    if (rest == 0)
    {
        paths++;
    }
    else
    {
        if (curr_sum == 0)
        {
            rec(curr_sum + x, rest - 1, half, x);
        }
        else if (curr_sum == half)
        {
            paths++;
        }
        else
        {
            rec(curr_sum + x, rest - 1, half, x);
            rec(curr_sum - x, rest - 1, half, x);
        }
    }
}

int main()
{
    FASTIO
    ll n, x;
    cin >> n >> x;
    if (n % 2 == 0)
    {
        rec(0, n - 1, n * x / 2, x);
        cout << paths % MOD << "\n";
    }
    else
    {
        cout << 0;
    }
}