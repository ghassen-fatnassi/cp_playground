#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    std::ios_base::sync_with_stdio(false);
#define TC while (t--)

const int MOD = 1e9 + 7;

int main()
{
    FASTIO
    int t;
    cin >> t;
    TC
    {
        ll n, k;
        cin >> n >> k;
        ll a[n];
        ll x[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll prefix_per_health[n];
        for (int i = 0; i < n; i++)
        {
            prefix_per_health[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
            prefix_per_health[abs(x[i]) - 1] += a[i];
        }
        for (int i = 1; i < n; i++)
        {
            prefix_per_health[i] = prefix_per_health[i] + prefix_per_health[i - 1];
        }
        bool good = true;
        for (int i = 0; i < n; i++)
        {
            if (prefix_per_health[i] > (i + 1) * k)
            {
                good = false;
                break;
            }
        }
        if (good)
        {
            cout << "YES"
                 << "\n";
        }
        else
        {
            cout << "NO"
                 << "\n";
        }
    }
    return 0;
}
