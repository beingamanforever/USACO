/**
 *    author:  compounding
 *    created: 2024-12-05 17:42:36
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
    int h, w;
    cin >> h >> w;
    char grid[h][w];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> grid[i][j];
        }
    }
    int dp[h][w];
    memset(dp, 0, sizeof(dp));
    // base case
    dp[0][0] = 1;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (grid[i][j] == '.') // if valid
            {
                if (i > 0)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                }
                if (j > 0)
                {
                    dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
                }
            }
            else // can't be reached
            {
                dp[i][j] = 0;
            }
        }
    }
    cout << dp[h - 1][w - 1] << endl;
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