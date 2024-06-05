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
    int songs[n];
    for (int i = 0; i < n; i++)
    {
        cin >> songs[i];
    }
    map<int, int> index_per_elm;
    int l = 0;
    int r = 0;
    int maxi = 1;
    int length = 1;
    index_per_elm[songs[r]] = r;
    while (r < n - 1)
    {
        r++;
        if (index_per_elm.find(songs[r]) != index_per_elm.end())
        {
            if (index_per_elm[songs[r]] >= l)
            {
                l = index_per_elm[songs[r]] + 1;
            }
        }
        index_per_elm[songs[r]] = r;
        length = r - l + 1;
        if (length > maxi)
        {
            maxi = length;
        }
    }
    cout << maxi << endl;
    return 0;
}