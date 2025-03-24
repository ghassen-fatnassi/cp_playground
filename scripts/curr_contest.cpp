#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);
#define TC while (t--)
const int MOD = 998244353;

void solve()
{
    ll n;
    string s;
    cin >> n;
    cin >> s;
    ll u = 0, d = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '_')
        {
            d++;
        }
        else
        {
            u++;
        }
    }
    ll l, r;
    l = u / 2;
    r = u - (u / 2);
    ll total = l * r * d;
    cout << total << endl;
}

int main()
{
    FASTIO
    int t = 1;
    cin >> t;
    TC { solve(); }
    return 0;
}