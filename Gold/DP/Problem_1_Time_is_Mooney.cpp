/**
 *    author:  compounding
 *    created: 2024-10-01 13:43:05
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
signed main()
{
    NeedForSpeed;
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    int n, m, c;
    cin >> n >> m >> c;
    vvi adj(n);
    vi moonies(n);
    for (int i = 0; i < n; i++)
    {
        cin >> moonies[i];
    }
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }
    vvi dp(1001, vi(n, -1));
    // if we dont even start we would get 0 moonies
    // dp[d][i] = max moonies if we are at node i at day d
    dp[0][0] = 0;
    int ans = 0;
    for (int d = 0; d < 1000; d++)
    {
        for (int i = 0; i < n; i++)
        {
            if (dp[d][i] != -1)
            {
                // if pahunch chuke hain then hei age jao
                for (auto x : adj[i])
                {
                    dp[d + 1][x] = max(dp[d + 1][x], dp[d][i] + moonies[x]);
                }
            }
        }
        ans = max(ans, dp[d][0] - (c * (d) * (d)));
    }
    cout << ans << endl;
    return 0;
}