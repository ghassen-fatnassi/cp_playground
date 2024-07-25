#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define print(n) cout << n << "\n";
#define TC while (n--)

const int mod = 1e9 + 7;
int main()
{
    ll n;
    cin >> n;
    TC
    {
        ll a, b;
        cin >> a >> b;
        ll res = 1;
        while (b > 0)
        {
            if (b & 1)
            {
                res *= a;
                res = res % mod;
            }
            a = a * a;
            a = a % mod;
            b = b / 2;
        }

        print(res)
    }

    return 0;
}