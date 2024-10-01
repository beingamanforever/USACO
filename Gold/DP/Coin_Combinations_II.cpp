/**
 *    author:  compounding
 *    created: 2024-10-01 23:40:58
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
    int n, x;
    cin >> n >> x;
    vi c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    // for ordering we consider the first i coins only
    // pull dp[i][j] = number of ways to make j using the first i coins
    // dp[i][j] = dp[i-1][j] + dp[i][j-c[i]]
    vvi dp(n + 1, vi(x + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - c[i - 1] >= 0)
            {
                dp[i][j] += dp[i][j - c[i - 1]];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n][x] << endl;
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