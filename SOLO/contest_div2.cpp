#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    std::ios_base::sync_with_stdio(false);
#define TC while (t--)
#define ld long double

const int MOD = 1e9 + 7;

int main()
{
    FASTIO
    ll t;
    cin >> t;
    TC
    {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        set<pair(ll, ll)> diff_right; // nemchi al limin
        set<pair(ll, ll)> diff_left;
        diff_right.insert(0, 0) for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i != 0)
            {
                diff_right.insert(a[i] - a[i - 1], i);
            }
        }
        diff_left.insert(0, n - 1);
        for (int i = n - 1; i >= 0; i--)
        {
            diff_left.insert(a[i - 1] - a[i], i)
        }
        while (diff_left.rbegin()->first != 0 && diff_right.rbegin()->first != 0 && k != 0)
        {
            if (diff_left.rbegin()->first > diff_right.rbegin()->first)
            {
                i = diff_left.rbegin()->second;
                a[i]=a[i+1];
                k--;
                diff_left.rbegin()->first=0;
            }
            else
            {
                i = diff_right.rbegin()->second;
                a[i]=a[i-1];
                k--;
                diff_right.rbegin()->first=0;
            }

        }
    }

    return 0;
}
