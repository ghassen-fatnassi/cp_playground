// CPP program to count almost prime numbers
// from 1 to n
#include <bits/stdc++.h>
using namespace std;
#define N 100005

// Create a boolean array "prime[0..n]" and initialize
// all entries it as true. A value in prime[i] will
// finally be false if i is Not a prime, else true.
bool prime[N];

void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));
    prime[1] = false;

    for (int p = 2; p * p < N; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p
            for (int i = p * 2; i < N; i += p)
                prime[i] = false;
        }
    }
}

// Function to count almost prime numbers
// from 1 to n
int almostPrimes(int n)
{
    // to store required answer
    int ans = 0;

    // 6 is first almost prime number
    for (int i = 6; i <= n; i++)
    {
        // to count prime factors
        int c = 0;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                // if it is perfect square
                if (j * j == i)
                {
                    if (prime[j])
                        c++;
                }
                else
                {
                    if (prime[j])
                        c++;
                    if (prime[i / j])
                        c++;
                }
            }
        }

        // if I is almost prime number
        if (c == 2)
            ans++;
    }
    return ans;
}

// Driver code
int main()
{
    SieveOfEratosthenes();
    int n;
    cin >> n;

    cout << almostPrimes(n);

    return 0;
}
