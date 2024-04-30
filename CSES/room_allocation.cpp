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
    int n;
    cin >> n;
    pair<int, int> customers[n];
    for (int i = 0; i < n; i++)
    {
        cin >> customers[i].first;
        cin >> customers[i].second;
    }
    sort(customers, customers + n);
    map<int, pair<int, int>> return 0;
}