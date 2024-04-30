#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TC while (t--)

const int MOD = 1e9 + 7;

ll puiss(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res *= a;
            res = res % MOD;
        }
        a = a * a;
        a = a % MOD;
        b = b / 2;
    }

    return res;
}

int main()
{
    int t;
    cin >> t;
    TC
    {
        ll a, b, l;
        cin >> a >> b >> l;
        vector<int> div_a;
        vector<int> div_b;
        div_a.push_back(0);
        div_b.push_back(0);
        ll counter_a = 0;
        ll counter_b = 0;
        while (counter_a <= log(l) / log(a))
        {
            counter_a++;
            ll curr = puiss(a, counter_a);
            if (l % curr == 0)
            {
                div_a.push_back(counter_a);
            }
        }
        while (counter_b <= log(l) / log(b))
        {
            counter_b++;
            ll curr = puiss(b, counter_b);
            if (l % curr == 0)
            {
                div_b.push_back(counter_b);
            }
        }
        set<int> set_k;
        ll curr;
        if (a > b)
        {
            for (auto elm_a : div_a)
            {
                for (auto elm_b : div_b)
                {
                    curr = puiss(a, elm_a) * puiss(b, elm_b);
                    if (curr > l)
                    {
                        break;
                    }
                    if (l % curr == 0)
                    {
                        set_k.insert(l / curr);
                    }
                }
            }
        }
        else
        {
            for (auto elm_b : div_b)
            {
                for (auto elm_a : div_a)
                {
                    curr = puiss(a, elm_a) * puiss(b, elm_b);
                    if (curr > l)
                    {
                        break;
                    }
                    if (l % curr == 0)
                    {
                        set_k.insert(l / curr);
                    }
                }
            }
        }
        cout << set_k.size() << "\n";
    }

    return 0;
}
