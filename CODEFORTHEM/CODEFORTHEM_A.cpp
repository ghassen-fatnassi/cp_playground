#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> seg;
void build(vector<int> &arr, int l, int r, int node)
{
    if (l == r)
    {
        seg[node] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    int L = 2 * node + 1;
    int R = 2 * node + 2;
    build(arr, l, mid, L);
    build(arr, mid + 1, r, R);
    seg[node] = seg[L] + seg[R];
}
void update(int l, int r, int node, int index, int val)
{
    if (l == r)
    {
        seg[node] = val;
        return;
    }
    int mid = (l + r) / 2;
    int L = 2 * node + 1;
    int R = 2 * node + 2;
    if (index <= mid)
    {
        update(l, mid, L, index, val);
    }
    else
    {
        update(mid + 1, r, R, index, val);
    }
    seg[node] = seg[L] + seg[R];
}
ll query(int l, int r, int node, int lq, int rq)
{
    if (lq > r || rq < l)
    {
        return 0;
    }
    else if (l >= lq && r <= rq)
    {
        return seg[node];
    }
    else
    {
        int mid = (l + r) / 2;
        int L = 2 * node + 1;
        int R = 2 * node + 2;
        return query(l, mid, L, lq, rq) + query(mid + 1, r, R, lq, rq);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    for (int i = 0; i < n; i++)

        cin >> v1[i];
    for (int i = 0; i < n; i++)
        cin >> v2[i];
    seg.resize(4 * n);
    build(v1, 0, n - 1, 0);
    ll so = query(0, n - 1, 0, 0, n - 1);
    set<pair<int, int>> s;
    s.insert({0, n - 1});
    multiset<ll> ss;
    ss.insert(so);
    for (int i = 0; i < n; i++)
    {
        int x = v2[i] - 1;
        auto it = s.upper_bound({x, n - 1});
        it--;
        int a = (*it).first;
        int b = (*it).second;
        ll s1 = query(0, n - 1, 0, a, b);
        ll s2 = query(0, n - 1, 0, a, x - 1);
        ll s3 = query(0, n - 1, 0, x + 1, b);
        s.erase(it);
        s.insert({a, x - 1});
        s.insert({x + 1, b});
        auto it1 = ss.find(s1);
        ss.erase(it1);
        ss.insert(s2);
        ss.insert(s3);
        auto it3 = ss.end();
        it3--;
        cout << (*it3) << endl;
    }
    return 0;
}
