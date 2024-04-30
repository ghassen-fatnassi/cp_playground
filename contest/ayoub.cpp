#include <bits/stdc++.h>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define Pair pair<ll, ll>
#define iPair pair<int, int>
#define newL cout << endl
#define ll_max 1e18
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) v.begin(), v.end()
#define sortt(v) sort(all(v))
#define forn(j, n) for (int i = j; i < n; i++)
using namespace std;
#define ll long long
#define TC while (t--)

int main()
{
    int t;
    cin >> t;
    TC
    {
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;
        bool ok = true;
        if (n >= m)
        {
            int k = 0;
            for (int i = 0; i < n; i++)
            {
                if (x[i] == s[i])
                {
                    ok = true;
                    k = i;
                }
                else
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                cout << 0 << endl;
            }
            else
            {

                x += x;
                bool okii = true;
                for (int i = 0; i < (2 * n) - m; i++)
                {
                    int j = 0;
                    int k = 0;

                    while (j < m)
                    {
                        if (x[i + j] = s[j])
                        {
                            okii = true;
                            k = j;
                        }
                        else
                        {
                            okii = false;
                            break;
                        }
                    }
                    if (okii && k == m - 1)
                    {
                        break;
                    }
                }

                if (okii)
                {
                    cout << 1 << endl;
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                size_t foundPos = s.find(x[i]);
                if (foundPos != string::npos)
                {
                    ok = true;
                }
                else
                {
                    ok = false;
                    cout << -1 << endl;
                    break;
                }
            }
            int nb = n;
            int counter = 0;
            while (nb <= m)
            {
                nb = nb + nb;
                x += x;
                counter++;
            }
            x += x;
            for (int i = 0; i < x.size() - m; i++)
            {
                int j = 0;
                int k = 0;
                while (j < m)
                {
                    if (x[i + j] = s[j])
                    {
                        ok = true;
                        k = j;
                    }
                    else
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok && k == m - 1)
                {
                    break;
                }
            }
            if (ok)
            {
                cout << counter * 2 << endl;
            }
        }
    }
    return 0;
}