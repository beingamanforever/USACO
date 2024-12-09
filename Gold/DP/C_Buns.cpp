/**
 *    author:  compounding
 *    created: 2024-12-08 18:22:31
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
    // TODO: Fractional Knapsack variation, Greedy
    int n, m, c0, d0;
    cin >> n >> m >> c0 >> d0;
    vi a(m + 1), b(m + 1), c(m + 1), d(m + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    // dp state -> using first m items, n grams dough -> maximum profit
    // dp[i][j]
    vvi dp(m + 1, vi(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        int maxtake = a[i] / b[i];   // maximum we can take of this type
        for (int j = 0; j <= n; j++) //  grams of dough used
        {
            for (int k = 0; k <= maxtake; k++) // number of items we take of this type
            {
                if (j + k * c[i] <= n)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j + k * c[i]] + k * d[i]);
                }
            }
        }
    }
    // now fill in the left ones with normal without stuffing
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        int more = (i / c0) * d0;
        dp[m][i] += more; // dp[m][i]-> maximum profit using all m items and i grams of dough
        ans = max(ans, dp[m][i]);
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