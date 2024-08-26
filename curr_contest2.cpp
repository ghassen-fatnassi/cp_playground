#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);
#define TC while (t--)
const int MOD = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;

    map<char, ll> occ_per_char;
    for (int i = 0; i < n; i++)
    {
        occ_per_char[s[i]]++;
    }

    vector<pair<ll, char>> freq_vec;
    for (auto it : occ_per_char)
    {
        freq_vec.push_back({it.second, it.first});
    }
    sort(freq_vec.rbegin(), freq_vec.rend());

    string out(n, ' ');
    int index = 0;

    for (auto &[freq, ch] : freq_vec)
    {
        for (int i = 0; i < freq; i++)
        {
            if (index >= n)
                index = 1;
            out[index] = ch;
            index += 2;
        }
    }

    cout << out << "\n";
}

int main()
{
    FASTIO;
    ll t;
    cin >> t;
    TC
    {
        solve();
    }
}
