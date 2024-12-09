/**
 *    author:  compounding
 *    created: 2024-12-09 16:01:27
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
const int N = 2005;
int fact[N];
int invfact[N];
// binary exponentiation
int binpow(int a, int b, int m = (int)1e9 + 7)
{
    a %= m;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}
void precompute()
{
    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    invfact[N - 1] = binpow(fact[N - 1], mod - 2); // calculated from back, as invfact[N-1] is the least
    for (int i = N - 2; i >= 0; i--)
    {
        invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
    }
}
int nCr(int n, int r)
{
    if (r < 0 || r > n)
    {
        return 0;
    }
    return (((fact[n] * invfact[r]) % mod) * (invfact[n - r] % mod)) % mod;
}
void solve()
{
    // similar to JEE question, first distribute 2 items each to k groups
    // left with n-2k, now each group be given atleast 1 item, done in (n-2k-1 C k-1) ways
    int n;
    cin >> n;
    precompute();
    if (n < 3)
    {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    int parts = 1;
    // parts means number of terms in sequence
    while ((n - 3 * parts) >= 0)
    {
        // give 3 to each part
        int left = n - 3 * parts;
        // now distribute left to parts
        ans += nCr(left + parts - 1, parts - 1);
        ans %= mod;
        parts++;
    }
    cout << ans << endl;
    return;
}

signed main()
{
    NeedForSpeed;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}