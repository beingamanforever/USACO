/**
 *    author:  compounding
 *    created: 2024-12-06 17:42:51
 **/
#include <bits/stdc++.h>
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define NeedForSpeed                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<pair<int, int>> vpi;
#define f first
#define s second
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define endl "\n"
const int mod = 1000000007;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
const int maxn = (int)(1e5 + 5);
// sieve of eratosthenes
vb isprime;
void primecheck(int n)
{
    isprime.clear();
    isprime.assign(n + 1, true);
    isprime[0] = false;
    isprime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (isprime[i]) // if prime
        {
            for (int j = i * i; j <= n; j += i)
            {
                isprime[j] = false;
            }
        }
    }
}
vi prefix;
void precompute()
{
    primecheck(maxn);
    prefix.resize(maxn);
    // n = odd, n-> prime and (n+1)/2 -> prime
    for (int i = 1; i < maxn; i++)
    {
        prefix[i] = prefix[i - 1];
        if (isprime[i] && isprime[(i + 1) / 2])
        {
            prefix[i]++;
        }
    }
    return;
}
void solve()
{
    int l, r;
    cin >> l >> r;
    cout << prefix[r] - prefix[l - 1] << endl;
    return;
}

signed main()
{
    NeedForSpeed;
    int q = 1;
    cin >> q;
    precompute();
    while (q--)
    {
        solve();
    }
    return 0;
}