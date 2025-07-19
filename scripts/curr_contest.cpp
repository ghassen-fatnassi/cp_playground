#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define TC while (t--)
const ll MOD = 998244353;

void solve()
{
    int n, k;
    cin >> n >> k;
    deque<pair<int, int>> dq;
    int curr;
    for (int i = 0; i < n; i++)
    {
        cin >> curr;
        dq.push_back({curr, 0});
    }
    for (int i = 0; i < k; i++)
    {
        auto x = dq[0];
        auto y = dq[1];
        if (x.first > y.first)
        {
            dq.pop_front();
            dq.pop_front();
            dq.push_back(y);
            dq.push_front({x.first, x.second + 1});
        }
        else
        {
            dq.pop_front();
            dq.push_back(x);
            dq[0] = {y.first, y.second + 1};
        }
    }
    pair<int, int> maxx = {0, 0};
    for (int i = 0; i < n; i++)
    {
        if (dq[i].second > maxx.second)
        {
            maxx.first = dq[i].first;
            maxx.second = dq[i].second;
        }
    }
    cout << maxx.first << "\n";
}

int main()
{
    FASTIO
    ll t;
    t = 1;
    // cin >> t;
    TC
    {
        solve();
    }
    return 0;
}
