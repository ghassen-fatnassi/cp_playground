#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    ios_base::sync_with_stdio(false);

const ll MOD = 1e9 + 7;

vector<vector<ll>> matmul(const vector<vector<ll>> &A, const vector<vector<ll>> &B)
{
    ll Arows = A.size();
    ll Acols = A[0].size();
    ll Bcols = B[0].size();

    vector<vector<ll>> M(Arows, vector<ll>(Bcols, 0));
    for (ll i = 0; i < Arows; i++)
    {
        for (ll j = 0; j < Bcols; j++)
        {
            for (ll k = 0; k < Acols; k++)
            {
                M[i][j] = (M[i][j] % MOD + ((A[i][k] * B[k][j]) % MOD)) % MOD;
            }
        }
    }
    return M;
}

vector<vector<ll>> MatrixBinaryExp(vector<vector<ll>> M, ll n)
{
    ll rows = M.size();
    vector<vector<ll>> I(rows, vector<ll>(rows, 0));

    for (ll i = 0; i < rows; i++)
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
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> A(n, vector<ll>(n, 0));

    for (ll i = 0; i < m; i++)
    {
        ll p, q;
        cin >> p >> q;
        A[p - 1][q - 1] = 1;
    }

    A = MatrixBinaryExp(A, k);
    cout << A[0][n - 1] << "\n";
}

int main()
{
    FASTIO
    solve();
    return 0;
}
