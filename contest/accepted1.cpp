#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TC while (t--)

const int MOD = 1e9 + 7;

ll modulo(ll a)
{
    return a % MOD;
}

int main()
{
    int t;
    cin >> t;
    TC
    {
        ll n, c;
        cin >> n >> c;
        ll a[n];
        double result = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        if (c >= n * 100)
        {
            cout << 100 << endl;
        }
        else
        {
            int count = n;
            while (c > 100)
            {
                result += a[count - 1] * 100;
                count--;
                c -= 100;
            }
            result += a[count - 1] * c;
            ll coeff = 0;
            for (int i = 0; i < n; i++)
            {
                coeff += a[i] * 100;
            }
            double ress = (result / coeff) * 100;
            cout << fixed << setprecision(15) << ress << endl;
        }
    }
    // int n, t;
    // cin >> n >> t;
    // ll prefix[n];
    // for (int i = 0; i < n; i++)
    // {
    //     prefix[i] = 0;
    // }
    // TC
    // {
    //     int type;
    //     cin >> type;
    //     if (type == 1)
    //     {
    //         ll l, r;
    //         cin >> l >> r;
    //         if (l == 1)
    //         {
    //             cout << prefix[r - 1];
    //         }
    //         else
    //         {
    //             cout << prefix[r - 1] - prefix[l - 1] << endl;
    //         }
    //     }
    //     else
    //     {
    //         ll l,r,p,k,v;
    //         cin>>l>>r>>p>>k>>v;
    //         int start=l+k-(l%p);
    //         for(int i=l-1;i<r-1;i+=p){prefix[]}
    //     }
    // }
    return 0;
}