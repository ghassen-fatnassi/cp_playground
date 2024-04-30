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
#define f first
#define s second
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
        int n;
        cin >> n;
        string s1;
        string s2;
        cin >> s1;
        s2 = s1;
        sort(s1.begin(), s1.end());
        int count = 0;
        bool same = true;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
            {
                same = false;
                break;
            }
        }
        if (same)
        {
            cout << 0 << endl;
        }
        else if (!same && s1[n - 1] == s2[n - 1])
        {
            cout << -1 << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (s1[i] != s2[i])
                {
                    count++;
                }
            }
            cout << count << endl;
        }
    }
    return 0;
}