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
    int occ = 0;
    int a[2 * n - 1];
    for (int i = 0; i < 2 * n - 1; i += 2)
    {
        a[i] = (i + 1) / 2;
        a[i + 1] = (i + 1) / 2;
    }
    for (int i = 0; i < 2 * n - 1; i++)
    {
        if (k <= 0)
        {
            break;
        }
        else
        {
            k = k - (n - i);
            occ++;
        }
    }
    cout << occ << "\n";
}

int main()
{
    FASTIO
    ll t;
    cin >> t;
    TC
    {
        solve();
    }
    return 0;
}
