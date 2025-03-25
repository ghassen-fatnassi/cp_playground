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
    cin >> n;
    multiset<int> digits = {0, 0, 0, 1, 2, 2, 3, 5};
    int stop = -1;
    int curr;
    for (int i = 0; i < n; i++)
    {
        cin >> curr;
        digits.erase(curr);
        if (digits.size() == 0)
        {
            stop = i;
        }
    }
}

int main()
{
    FASTIO
    int t = 1;
    cin >> t;
    TC { solve(); }
    return 0;
}