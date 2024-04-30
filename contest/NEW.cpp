#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    std::ios_base::sync_with_stdio(false);
#define TC while (t--)
#define ld long double

const int MOD = 1e9 + 7;

int main()
{
    FASTIO
    int t;
    cin >> t;
    TC
    {
        int n;
        cin >> n;
        int a[n];
        map<int, int> index_per_elm;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            index_per_elm[a[i]] = i;
        }
        set<int> final_set;
        final_set.insert(1);
        for (auto elm : index_per_elm)
        {
            if ((index_per_elm[elm.first - 1] > elm.second && index_per_elm[0] < elm.second) or (index_per_elm[elm.first - 1] < elm.second && index_per_elm[0] > elm.second))
            {
                final_set.insert(elm.first);
            }
        }
        int i = 1;

        for (auto elm : final_set)
        {
            if (elm != i)
            {
                break;
            }
            else
            {
                i++;
            }
        }
        cout << i << endl;
    }

    return 0;
}
