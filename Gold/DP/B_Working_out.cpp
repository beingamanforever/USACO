/**
 *    author:  compounding
 *    created: 2024-12-08 15:45:59
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
int n, m;
int grid[1001][1001];
int dp1[1001][1001];
int dp2[1001][1001];
int dp3[1001][1001];
int dp4[1001][1001];
void solve()
{
    // dp[i][j] = maximal cost to reach / go from desirecd states
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
        }
    }
    // dp1[i][j] = maximal cost to go from (1,1) to (i,j), using only right and down moves
    // dp2[i][j] = maximal cost to go from (n,1) to (i,j), using only right and up moves
    // dp3[i][j] = maximal cost to go from (i,j) to (1,m), using only right and up moves
    // dp4[i][j] = maximal cost to go from (i,j) to (n,m), using only right and down moves
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp1[i][j] = grid[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
        }
    }
    for (int i = n; i >= 1; i--) // ulta loop
    {
        for (int j = 1; j <= m; j++)
        {
            dp2[i][j] = grid[i][j] + max(dp2[i + 1][j], dp2[i][j - 1]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--) // ulta loop
        {
            dp3[i][j] = grid[i][j] + max(dp3[i - 1][j], dp3[i][j + 1]);
        }
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = m; j >= 1; j--)
        {
            dp4[i][j] = grid[i][j] + max(dp4[i + 1][j], dp4[i][j + 1]);
        }
    }
    int ans = 0;
    // meeting places can be (2,2) to (n-1,m-1), as we need one down/one right and one up move/ one right
    for (int i = 2; i < n; i++)
    {
        for (int j = 2; j < m; j++)
        {
            // two posoibilities, A takes 1,2 B takes 2,1 or A takes 2,1 B takes 1,2
            // ! they will exchange directions at the meeting point
            ans = max({ans, dp1[i][j - 1] + dp2[i + 1][j] + dp3[i - 1][j] + dp4[i][j + 1],
                       dp1[i - 1][j] + dp2[i][j - 1] + dp3[i][j + 1] + dp4[i + 1][j]});
        }
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