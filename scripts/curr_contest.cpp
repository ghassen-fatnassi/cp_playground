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
    ll n, k, l;
    cin >> n >> k >> l;
    ll sum = (2 * l) * (2 * l) * n - (n - 1) * (2 * l - k) * (2 * l - k);
    cout << sum << "\n";
}

int main()
{
    FASTIO
    int t;
    t = 1;
    TC
    {
        solve();
    }
    return 0;
}
