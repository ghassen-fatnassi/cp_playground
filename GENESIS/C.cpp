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
    ll n;
    cin >> n;
    set<pair<ll, ll>> points;
    map<pair<ll, ll>, ll> indexes;

    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        points.insert(pair(x, y));
        indexes[pair(x, y)] = i;
    }
    ll i = 0;
    auto last = "\n";
    for (auto elm : points)

    {
        if (last == "\n")
        {
            last = " ";
        }
        else
        {
            last = "\n";
        }
        cout << indexes[elm] + 1 << last;
    }
}