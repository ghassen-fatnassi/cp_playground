#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);

const int MOD = 1e9 + 7;

vector<vector<ll>> matmul(vector<vector<ll>> A, vector<vector<ll>> B)
{
    vector<vector<ll>> M(6, vector<ll>(6));
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            M[i][j] = 0;
            for (int k = 0; k < 6; k++)
            {
                M[i][j] = (M[i][j] + A[i][k] * B[k][j] % MOD) % MOD;
            }
        }
    }
    return M;
}

vector<vector<ll>> MatrixBinaryExp(vector<vector<ll>> M, ll n)
{
    vector<vector<ll>> I(6, vector<ll>(6));
    for (int i = 0; i < 6; i++)
    {
        I[i][i] = 1;
    }
    while (n > 0)
    {
        if (n & 1)
        {
            I = matmul(I, M);
        }
        M = matmul(M, M);
        n >>= 1;
    }
    return I;
}

void solve()
{
    ll n;
    cin >> n;
    if (n == 0)
    {
        cout << "1\n";
        return;
    }
    n--;
    vector<vector<ll>> A(6, vector<ll>(6, 0));
    for (int i = 0; i < 6; i++)
    {
        if (i == 0)
        {
            fill(A[i].begin(), A[i].end(), 1);
        }
        else
        {
            A[i][i - 1] = 1;
        }
    }
    A = MatrixBinaryExp(A, n);

    vector<ll> D(6);
    D[0] = 1;
    for (int i = 1; i < 6; i++)
    {
        D[i] = D[i - 1] * 2 % MOD;
    }
    ll res = 0;
    for (int j = 0; j < 6; j++)
    {
        res = (res + A[5][j] * D[5 - j] % MOD) % MOD;
    }
    cout << res << "\n";
}

int main()
{
    FASTIO
    solve();
    return 0;
}
