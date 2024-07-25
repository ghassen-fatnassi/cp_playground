long long squareMultiply(long long base, long long exponent, long long mod)
{
    long long result = 1;
    base %= mod;
    while (exponent > 0)
    {
        if (exponent & 1)
        {
            result = (result * base) % mod;
        }
        exponent >>= 1;
        base = (base * base) % mod;
    }
    return result;
}

vector<long long> divisors(long long y)
{
    vector<long long> d = {};
    vector<long long> e = {};
    if (y % 2 == 0)
    {
        for (long long i = 2; i <= y / 2; i++)
        {
            e.push_back(i);
        }
        for (long long i = 2; i <= y / 2; i++)
        {
            if (find(e.begin(), e.end(), y / i) != e.end())
            {
                d.push_back(i);
            }
        }
        return d;
    }
    else
    {
        for (long long i = 2; i <= y / 2; i++)
        {
            e.push_back(i);
        }
        for (long long i = 2; i <= y / 2; i++)
        {
            if (find(e.begin(), e.end(), y / i) != e.end())
            {
                d.push_back(i);
            }
        }
        return d;
    }
}

long long binarySearch(long long arr[], long long low, long long high, long long x)
{
    if (high >= low)
    {
        long long mid = low + (high - low) / 2;

        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;

        // If element is smalong longer than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, low, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, high, x);
    }
}

void SieveOfEratosthenes(long long n)
{
    // Create a boolean array "prime[0..n]" and initialize
    // all entries it as true. A value in prime[i] will
    // finally be false if i is Not a prime, else true.
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (long long p = 2; p * p <= n; p++)
    {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples of p greater than or
            // equal to the square of it numbers which are
            // multiple of p and are less than p^2 are
            // already been marked.
            for (long long i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Prlong long all prime numbers
    for (long long p = 2; p <= n; p++)
        if (prime[p])
            cout << p << " ";
}

long long puiss(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res *= a;
            res = res % mod;
        }
        a = a * a;
        a = a % mod;
        b = b / 2;
    }
    return res;
}