#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TC while (t--)

const int MOD = 1e9 + 7;

int main()
{
    int t;
    cin >> t;
    TC
    {
        int n;
        cin >> n;
        int a[n];
        ll prefix[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i == 0)
            {
                prefix[i] = a[i];
            }
            else
            {
                prefix[i] = a[i] + prefix[i - 1];
            }
        }
        ll f[n];
        for (int k = 0; k <= n / 2 - 1; k++)
        {
            if (n % k != 0)
            {
                f[k] = -1;
            }
            else
            {
                for (int i = 0; iw)
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (f[i] > maxi)
            {
                maxi = f[i];
            }
            if (a[i] < mini)
            {
                mini = f[i];
            }
        }
        cout << maxi - mini << endl;
    }
    return 0;
}