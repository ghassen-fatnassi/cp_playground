#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TC while (t--)

const int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    set<string> files;
    string ss;
    string temp;
    getline(cin, ss);
    for (int i = 0; i < n; i++)
    {
        cin >> ss;
        getline(cin, temp);
        if (ss[0] == 't')
        {
            files.insert(temp);
        }
        else if (ss[0] == 'r')
        {
            files.erase(temp);
        }
        else
        {
            cout << files.size() << "\n";
        }
    }

    return 0;
}
