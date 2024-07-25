#include <bits/stdc++.h>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
using namespace std;

#define ll long long

const int mod = 1e9 + 7;
const int N = 1e5 + 5;

int a[N];
string ss;
int n, k, cp;
int tree[4 * N];

int mrg(int x, int y, int k)
{
    return (x * y) % k;
}

void build(int id = 0, int ns = 0, int ne = n - 1)
{
    if (ne == ns)
    {
        tree[id] = a[ns] % k;
        return;
    }
    int l = 2 * id + 1;
    int r = l + 1;
    int mid = ns + (ne - ns) / 2;
    build(l, ns, mid);
    build(r, mid + 1, ne);
    tree[id] = mrg(tree[l], tree[r], k);
}

int query(int qs, int qe, int id = 0, int ns = 0, int ne = n - 1)
{
    if (ns > qe || qs > ne)
    {
        return 1;
    }
    else if (qs <= ns && qe >= ne)
    {
        return tree[id];
    }
    int l = 2 * id + 1;
    int r = l + 1;
    int mid = ns + (ne - ns) / 2;
    return mrg(query(qs, qe, l, ns, mid), query(qs, qe, r, mid + 1, ne), k);
}

void upd(int pos, int id = 0, int ns = 0, int ne = n - 1)
{
    if (ns > pos || pos > ne)
    {
        return;
    }
    if (ne == ns)
    {
        tree[id]++;
        return;
    }
    int l = 2 * id + 1;
    int r = l + 1;
    int mid = ns + (ne - ns) / 2;

    if (pos <= mid)
    {
        upd(pos, l, ns, mid);
    }
    else
    {
        upd(pos, r, mid + 1, ne);
    }
    tree[id] = mrg(tree[l], tree[r], k);
}

int main()
{
    FAST;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    build();
    int j = 0;
    while (tree[0] != 0 && cp <= k)
    {
        cp++;
        j++;
        upd(j - 1);
        if (j == n - 1)
        {
            j = 0;
        }
    }
    cout << cp << endl;

    return 0;
}