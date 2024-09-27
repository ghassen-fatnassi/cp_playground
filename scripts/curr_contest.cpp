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
    ll n;
    cin >> n;
    string s = "eaoui";
    string sb = "iuoae";
    string out = "";
    for (int i = 0; i < (n / 5); i++)
    {
        if (i % 2 == 0)
        {
            out += s;
        }
        else
        {
            out += sb;
        }
    }
    if ((n / 5) & 1)
    {
        for (int i = 0; i < (n % 5); i++)
        {
            out += sb[i];
        }
    }
    else
    {
        for (int i = 0; i < (n % 5); i++)
        {
            out += s[i];
        }
    }
    cout << out << "\n";
}

int main()
{
    FASTIO;
    ll t;
    t = 1;
    cin >> t;
    TC
    {
        solve();
    }
}
