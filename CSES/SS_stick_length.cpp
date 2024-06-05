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
        int inc = 1, dec = n;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                a[i] = inc;
                inc++;
            }
            else
            {
                a[i] = dec;
                dec--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}