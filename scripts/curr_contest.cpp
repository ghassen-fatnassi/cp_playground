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
    ll n, k;
    cin >> n >> k;
    ll p, q;
    p = 2 * k * (n - 1) + k * (k - 1);
    q = (n + k - 1) * (n + k - 2);
    if (n == 1 && k == 1)
    {
        cout << "1 1\n";
    }
    else
    {
        ll x = gcd(p, q);
        cout << p / x << " " << q / x;
        cout << "\n";
    }
}

int main()
{
    int t;
    cin >> t;
    TC { solve(); }

    return 0;
}