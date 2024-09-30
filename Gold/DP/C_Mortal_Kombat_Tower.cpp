/**
 *    author:  compounding
 *    created: 2024-09-30 13:41:32
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
    vi boss(n);
    for (int i = 0; i < n; i++)
    {
        cin >> boss[i];
    }
    vvi dp(2, vi(n + 1, 1e9));
    dp[1][0] = 0;
    // dp[0][0] = 0; wont make sense as 1st turn is his
    for (int j = 0; j < n; j++)
    {
        dp[0][j + 1] = min(dp[0][j + 1], dp[1][j] + boss[j]);
        dp[1][j + 1] = min(dp[1][j + 1], dp[0][j]);
        if ((j + 1) < n)
        {
            dp[1][j + 2] = min(dp[1][j + 2], dp[0][j]);
            dp[0][j + 2] = min(dp[0][j + 2], dp[1][j] + boss[j] + boss[j + 1]);
        }
    }
    cout << min(dp[0][n], dp[1][n]) << endl;
    return;
}

signed main()
{
    NeedForSpeed;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}