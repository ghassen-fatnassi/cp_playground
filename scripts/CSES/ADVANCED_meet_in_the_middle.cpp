#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);
#define TC while (t--)
const int MOD = 1e9 + 7;

void SubsetsSums(const vector<ll> &arr, vector<ll> &sums)
{
    int n = arr.size();
    for (int mask = 0; mask < (1 << n); mask++)
    {
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (mask & (1 << i))
            {
                sum += arr[i];
            }
        }
        sums.push_back(sum);
    }
}

void solve()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> t(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }

    vector<ll> t1(t.begin(), t.begin() + n / 2);
    vector<ll> t2(t.begin() + n / 2, t.end());

    vector<ll> x, y;
    SubsetsSums(t1, x);
    SubsetsSums(t2, y);

    sort(y.begin(), y.end());

    ll counter = 0;
    for (ll sum_x : x)
    {
        ll target = k - sum_x;

        counter += upper_bound(y.begin(), y.end(), target) - lower_bound(y.begin(), y.end(), target);
    }

    cout << counter << "\n";
}

int main()
{
    FASTIO;
    ll t;
    t = 1;
    TC
    {
        solve();
    }
}
