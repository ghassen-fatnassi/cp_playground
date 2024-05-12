#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);
#define TC while (t--)
const int MOD = 1e9 + 7;

ll merge(ll first, ll second)
{
    return min(first, second); // changes based on operation
}

void build(ll v, ll l, ll r, ll SEG[], ll a[])
{
    if (l == r)
    {
        SEG[v] = a[l];
    }
    else
    {
        ll m = (l + r) / 2;
        build(2 * v + 1, l, m, SEG, a);
        build(2 * v + 2, m + 1, r, SEG, a);
        SEG[v] = merge(SEG[2 * v + 1], SEG[2 * v + 2]);
    }
}

ll query(ll s, ll e, ll v, ll l, ll r, ll neutral_element, ll SEG[])
{
    if (r < s || l > e) // no overlap
    {
        return neutral_element;
    }
    if (s <= l && e >= r) // full overlap
    {
        return SEG[v];
    }
    ll m = (l + r) / 2; // partial overlap
    return merge(query(s, e, 2 * v + 1, l, m, neutral_element, SEG), query(s, e, 2 * v + 2, m + 1, r, neutral_element, SEG));
}

void update(ll v, ll l, ll r, ll pos, ll new_value, ll SEG[])
{
    if (l == r)
    {
        SEG[v] = new_value;
    }
    else
    {
        ll m = (l + r) / 2;
        if (pos > m)
        {
            update(2 * v + 2, m + 1, r, pos, new_value, SEG);
        }
        else
        {
            update(2 * v + 1, l, m, pos, new_value, SEG);
        }
        SEG[v] = merge(SEG[2 * v + 1], SEG[2 * v + 2]);
    }
}

int main()
{
    FASTIO

    ll n, q;
    cin >> n >> q;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll SEG[4 * n] = {0};
    ll neutral_element = 1e9; // changes based on operation

    build(0, 0, n - 1, SEG, a); // complexity O(n)
    for (int i = 0; i < q; i++)
    {
        ll checker;
        cin >> checker;
        if (checker == 1)
        {
            ll k;
            ll u;
            cin >> k >> u;
            update(0, 0, n - 1, k - 1, u, SEG); // complexity O(log(n))
        }
        else
        {
            ll s;
            ll e;
            cin >> s >> e;
            cout << query(s - 1, e - 1, 0, 0, n - 1, neutral_element, SEG) << "\n"; // complexity O(log(n))
        }
    }
    return 0;
}
