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
    int cubes[n];
    for (int i = 0; i < n; i++)
    {
        cin >> cubes[i];
    }
    multiset<int> towers;
    towers.insert(cubes[0]);
    for (int i = 1; i < n; i++)
    {
        auto it = towers.upper_bound(cubes[i]);
        if (it == towers.end())
        {
            towers.insert(cubes[i]);
        }
        else
        {
            towers.erase(it);
            towers.insert(cubes[i]);
        }
    }
    cout << towers.size() << endl;
    return 0;
}