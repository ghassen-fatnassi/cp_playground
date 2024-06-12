#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    std::ios_base::sync_with_stdio(false);
#define TC while (t--)

const int MOD = 1e9 + 7;

int main()
{
    FASTIO
    int n;
    cin >> n;
    int a[n];
    map<int, int> elm_by_index;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        elm_by_index[a[i]] = i;
    }
    set<pair<int, int>> inversions; // stores the consecutive integers whose indices are inverted
    for (int i = 1; i < n; i++)
    {
        if (elm_by_index[i + 1] < elm_by_index[i])
        {
            inversions.insert(pair(elm_by_index[i], elm_by_index[i + 1]));
        }
    }
    cout << 1 + inversions.size();
    return 0;
}