#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);
#define TC while (t--)
const int MOD = 1e9 + 7;

int main()
{
    FASTIO
    int n;
    cin >> n;
    ll grid[n][n];
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            grid[i][j] = 0;
        }
    }
    grid[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char x;
            cin >> x;
            if (x == '*')
            {
                grid[i][j] = 0;
            }
            else
            {
                if (i > 0)
                {
                    grid[i][j] += grid[i - 1][j] % MOD;
                }
                if (j > 0)
                {
                    grid[i][j] += grid[i][j - 1] % MOD;
                }
            }
        }
    }
    cout << grid[n - 1][n - 1] % MOD;
}
