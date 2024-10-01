/**
 *    author:  compounding
 *    created: 2024-10-01 22:11:52
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
#define endl "\n"
const int mod = 1000000007;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
void solve()
{
    int n;
    cin >> n;
    vi dp(n + 1, 0);
    // dp[i] = number of ways to reach i
    // transiiton: dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6]
    dp[0] = 1;
    // pull dp -> past values which are computed are used to compute the current value
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i - j >= 0)
            {
                dp[i] = (dp[i] + dp[i - j]) % mod;
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
    //  cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}