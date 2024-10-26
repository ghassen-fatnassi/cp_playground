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
    int l, n, m;
    cin >> l >> n >> m;
    vector<ll> a;
    vector<ll> b;
    ll areas = m + n + 1;
    ll count = 0;
    ll UR = 0,UL=0;
    ll L = 0, R = 0;
    for (int i = 0; i < n; i++)
    {
        char c;
        ll x;
        cin >> c >> x;
        if (c == 'U')
        {
            UR++;
            a.push_back(3 * l - x);
        }
        else
        {
            R++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        char c;
        ll x;
        cin >> c >> x;
        if (c == 'U')
        {
            UL++;
            b.push_back(3 * l - x);
        }
        else
        {
            L++;
        }
    }
    areas += UR*L+UL*R + R * L;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (auto elm : a)
    {
        int index = upper_bound(b.begin(), b.end(), elm) - b.begin();
        areas += b.size() - index;
    }
    cout << areas << "\n";
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