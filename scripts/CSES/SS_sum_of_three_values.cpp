#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        int goal = x - a[i].first;
        int left = i + 1, right = n - 1;
        while (left < right)
        {
            int sum = a[left].first + a[right].first;
            if (sum == goal)
            {
                cout << a[i].second << " " << a[left].second << " " << a[right].second << endl;
                return;
            }
            else if (sum < goal)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}