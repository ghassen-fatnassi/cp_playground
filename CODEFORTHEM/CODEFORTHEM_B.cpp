#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    std::ios_base::sync_with_stdio(false);
#define TC while (t--)
#define ld long double

const int MOD = 1e9 + 7;

int main()
{
    FASTIO
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    for (int i = 1; i <= sqrt(s1); i++)
    {
        if (s1 % i == 0)
        {
            int a = i;
            int b = s1 / i;
            if (s2 % a == 0 && s3 % b == 0 && s2 / a == s3 / b)
            {
                int c = s2 / a;
                cout << 4 * a + 4 * b + 4 * c << endl;
                return 0;
            }
            else if (s2 % b == 0 && s3 % a == 0 && s2 / b == s3 / a)
            {
                int c = s2 / b;
                cout << 4 * a + 4 * b + 4 * c << endl;
                return 0;
            }
        }
    }

    return 0;
}
