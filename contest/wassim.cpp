#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    std::ios_base::sync_with_stdio(false);
#define TC while (t--)

const int MOD = 1e9 + 7;

ll pgcd(ll a, ll b)
{
    ll aux;
    if (a == 0)
    {
        return b;
    }
    if (b == 0)
    {
        return a;
    }
    while (1)
    {
        aux = b;
        b = a % b;
        a = aux;
        if (b == 0)
        {
            break;
        }
    }
    return a;
}
int main()
{
    FASTIO
    int t;
    cin >> t;
    TC
    {
        ll n, k;
        cin >> n >> k;
        if (n == 1 && k == 1)
        {
            cout << 1 << " " << 1 << endl;
        }
        else
        {
            ll a = 2 * k * (n - 1) + k * (k - 1);
            ll b = ((n - 1 + k) * (n + k - 2));
            ll d = pgcd(a, b);
            cout << a / d << " " << b / d << endl;
        }
    }
    return 0;
}
