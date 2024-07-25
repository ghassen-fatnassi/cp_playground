#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);
#define TC while (t--)
const int MOD = 1e9 + 7;
const int N = 1e5;

int n;
int a[N];
vector<pair<int, int>> v;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int i = 0;
    int nb = 0;
    while (i < n)
    {
        if (i == n - 1)
        {
            v.push_back({a[i], i});
            nb++;
            i++;
        }
        else
        {
            if (a[i] < a[i + 1])
            {
                nb++;
                v.push_back({a[i], i});
                i += 2;
            }
            else
            {
                if (a[i + 1] < a[i + 2])
                {
                    nb++;
                    v.push_back({a[i + 1], i + 1});
                    i += 3;
                }
                else
                {
                    nb++;
                    v.push_back({a[i + 1], i + 1});
                    i += 2;
                }
            }
        }
    }
    sort(v.begin(), v.end());
    cout << nb << endl;
    for (auto pair : v)
    {
        cout << pair.second + 1 << " ";
    }

    return 0;
}