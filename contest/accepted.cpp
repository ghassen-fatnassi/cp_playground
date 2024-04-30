#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO  \
    cin.tie(0); \
    std::ios_base::sync_with_stdio(false);
#define TC while (t--)

const int MOD = 1e9 + 7;

int main()
{
    FASTIO
    int t;
    cin >> t;
    TC
    {
        int n, c, d;
        cin >> n >> c >> d;
        int a[n * n];
        for (int i = 0; i < n * n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n * n);
        int diff[n * n - 1];
        for (int i = 0; i < n * n - 1; i++)
        {
            diff[i] = a[i + 1] - a[i];
        }
        int a11 = a[0];
        int ghorbel[n * n - 1];
        int x = min(c, d);
        ghorbel[0] = x;
        ghorbel[n * n - 2] = x;
        for (int i = 0; i < n * n - 2; i++)
        {
            ghorbel[i] = abs(c - d);
        }
        bool same = true;
        for (int i = 0; i < n * n - 1; i++)
        {
            if (ghorbel[i] != diff[i])
            {
                same = false;
                break;
            }
        }
        if (same)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}

// ll puiss(ll a, ll b)
// {
//     ll res = 1;
//     while (b > 0)
//     {
//         if (b & 1)
//         {
//             res *= a;
//             res = res % MOD;
//         }
//         a = a * a;
//         a = a % MOD;
//         b = b / 2;
//     }

//     return res;
// }

// int main()
// {
//     FASTIO
//     /*int t;
//     cin >> t;
//     TC
//     {
//         int n, k;
//         cin >> n >> k;
//         bool win = true;
//         int alive = n;
//         for (int i = 1; i <= n; i++)
//         {
//             if (k > (alive * i))
//             {
//                 k++;
//                 alive--;
//             }
//             else
//             {
//                 win = false;
//                 break;
//             }
//         }
//         if (win)
//         {
//             cout << "YES\n";
//         }
//         else
//         {
//             cout << "NO\n";
//         }
//     }
//     */

//     int t;
//     cin >> t;
//     TC
//     {
//         int n, k;
//         cin >> n >> k;
//         cout << (2 * k * (n - 1) + k * (k - 1)) << " " << ((n - 1 + k) * (n + k - 2)) << endl;
//     }
//     return 0;
// }

/*int n;
       cin >> n;
       string ss;
       cin >> ss;
       int counter = 0;
       for(int )
       for (int i = 0; i < n / 2; i++)
       {
           if (ss[i] != ss[n - i - 1])
           {
               counter++;
           }
       }
       cout << counter << endl;
   }*/

// BITMASK#############################################################################################

// void PrintAllSubsets(int N, int max_mask_req)
// {
//     cout << "0";

//     for (int mask = 0; mask <= max_mask_req; mask++)
//     {
//         for (int k = 0; k < N; k++)
//         {
//             if ((mask & (1 << k)) != 0)
//             {
//                 cout << k + 1 << " ";
//             }
//         }
//         cout << "\n";
//     }
// }

// int main()
// {

//     int N = 8;

//     int max_mask_req = (1 << N) - 1;

//     PrintAllSubsets(N, max_mask_req);
//     return 0;
// }

// BINARY EXPONENTIATION###########################################################################

// int main()
// {
//     ll n;
//     cin >> n;
//     TC
//     {
//         ll a, b;
//         cin >> a >> b;
//         ll res = 1;
//         while (b > 0)
//         {
//             if (b & 1)
//             {
//                 res *= a;
//                 res = res % MOD;
//             }
//             a = a * a;
//             a = a % MOD;
//             b = b / 2;
//         }

//         print(res)
//     }

//     return 0;
// }

// GRAPH ########################################################################################"
//  void dfs(int pos)
//  {
//      vis[pos] = true;
//      for (int i = 0; i < graph[pos].size(); i++)
//      {
//          int x = graph[pos][i];
//          if (!vis[x])
//          {
//              dfs(x);
//          }
//      }
//      return;
//  }

// const int N = 1e5;
// bool vis[N];
// vector<int> graph[N];

// void bfs(int pos)
// {
//     vis[pos] = true;
//     queue<int> q;
//     q.push(pos);
//     while (!q.empty())
//     {
//         int x = q.front();
//         q.pop();
//         for (int i = 0; i < graph[x].size(); i++)
//         {
//             int next = graph[x][i];
//             if (!vis[next])
//             {
//                 vis[next] = true;
//                 q.push(next);
//             }
//         }
//     }
// }

//  ABOUT SETS #############################################################################################
// std::set<int> unionSet;
//     std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(unionSet, unionSet.begin()));

// std::set<int> intersectionSet;
//     std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(intersectionSet, intersectionSet.begin()));

// DECIMAL TO BINARY ##############################################################################################################################""

// int main() {
//     int decimalNumber;
//     std::cout << "Enter a decimal number: ";
//     std::cin >> decimalNumber;

//     std::bitset<32> binaryNumber(decimalNumber); // Assuming 32-bit integer

//     std::cout << "Binary representation: " << binaryNumber << std::endl;

//     return 0;
// }
// ::::::::::::::::::::::::::::::::::::::