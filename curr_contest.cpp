#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);
#define TC while (t--)
const int MOD = 1e9 + 7;

const int MAXN = 10002;

int parent[MAXN];

int send_message(int a, int b)
{
    cout << "? " << a << " " << b << endl;
    int x;
    cin >> x;
    return x;
}

void find(int a, int b)
{
    int x = send_message(a, b);
    if (x == a)
    {
        parent[b] = a;
    }
    else
    {
        if (parent[x] == x)
        {
            find(a, x);
        }
        if (parent[b] == b)
        {
            find(x, b);
        }
    }
}

void solve()
{
}

int main()
{
    FASTIO;
    ll t;
    cin >> t;
    TC
    {
        solve();
        cout << "\n";
    }
}
