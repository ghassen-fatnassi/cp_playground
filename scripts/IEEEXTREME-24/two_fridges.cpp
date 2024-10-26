#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);
#define TC while (t--)
const int MOD = 1e9 + 7;

int solve()
{
    int n;
    cin >> n;
    set<pair<int, int>> subs;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        subs.insert(pair(x, y));
    }
    set<pair<int, int>> possibles;
    for (int i = -100; i <= 100; i++)
    {
        for (int j = -100; j <= 100; j++)
        {
            int good = 1;
            for (auto elm : subs)
            {
                if ((elm.first > i || elm.second < i) && (elm.first > j || elm.second < j))
                {
                    good = 0;
                    break;
                }
            }
            if (good)
            {
                possibles.insert(pair(i, j));
            }
        }
    }
    if (possibles.size() == 0)
    {
        cout << -1;
    }
    else
    {
        cout << possibles.begin()->first << " " << possibles.begin()->second;
    }
    return 0;
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