#include <bits/stdc++.h>
using namespace std;

void PrintAllSubsets(int N, int max_mask_req)
{
    cout << "0";

    for (int mask = 0; mask <= max_mask_req; mask++)
    {
        for (int k = 0; k < N; k++)
        {
            if ((mask & (1 << k)) != 0)
            {
                cout << k + 1 << " ";
            }
        }
        cout << "\n";
    }
}

int main()
{

    int N = 8;

    int max_mask_req = (1 << N) - 1;

    PrintAllSubsets(N, max_mask_req);
    return 0;
}