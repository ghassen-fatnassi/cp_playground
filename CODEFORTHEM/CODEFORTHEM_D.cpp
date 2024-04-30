#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    std::ios_base::sync_with_stdio(false);
#define TC while (t--)
#define ld long double
// cout << setprecision(3) <<num;
const int MOD = 1e9 + 7;

int main()
{
    FASTIO
    ll n, k;
    cin >> n >> k;
    string ss;
    cin >> ss;
    map<char, int> mp;
    for (ll i = 0; i < n; i++)
    {
        mp[ss[i]]++;
    }
    for (auto &pair : mp)
    {
        if (k == 0)
        {
            break;
        }
        if (k >= mp[pair.first])
        {
            k -= mp[pair.first];
            mp[pair.first] = 0;
        }
        else
        {

            mp[pair.first] = pair.second - k;
            k = 0;
        }
    }
    string s1;
    for (int i = n - 1; i >= 0; i--)
    {
        char c = ss[i];
        if (mp[c] > 0)
        {
            s1 += c;
            mp[c]--;
        }
    }
    string s2;
    for (int i = s1.size() - 1; i >= 0; i--)
    {
        s2 += s1[i];
    }
    cout << s2 << endl;
    return 0;
}