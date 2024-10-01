/**
 *    author:  compounding
 *    created: 2024-10-01 22:25:28
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
    vi coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    // in cases where we have to find minimum of something, dp state is better initialized with INT_MAX
    vi dp(x + 1, INT_MAX);
    dp[0] = 0; // empty set
    // pull dp -> past values which are computed are used to compute the current value
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0) // check
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    cout << (dp[x] == INT_MAX ? -1 : dp[x]) << endl;
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