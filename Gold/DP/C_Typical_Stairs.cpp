/**
 *    author:  compounding
 *    created: 2024-12-08 19:44:56
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
void solve()
{
    int n, m;
    cin >> n >> m;
    vi a(m); // invalid steps to land on
    int cur = -1, prev = -1;
    set<int> s;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        s.insert(a[i]);
        cur = a[i];
        if (prev + 1 == cur)
        {
            cout << 0 << endl; // two consecutive invalid steps
            return;
        }
    }
    vi dp(n + 1, 0);
    // dp[i] = number of ways to reach ith step
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (s.find(i) == s.end())
        {
            if (i == 1)
            {
                dp[i] = 1;
            }
            else
            {
                dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
            }
        }
    }
    cout << dp[n] << endl;
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