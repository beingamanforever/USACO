/**
 *    author:  compounding
 *    created: 2024-12-08 22:57:31
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
    // kind of similar to minimum coins needed to reach a sum
    int h, n;
    cin >> h >> n;
    vi value(n), cost(n);
    for (int i = 0; i < n; i++)
    {
        cin >> value[i] >> cost[i];
    }
    vi dp(h + 1, LLONG_MAX);
    dp[0] = 0;
    // dp[i] = minimum cost to reach i health
    for (int i = 1; i <= h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - value[j] >= 0)
            {
                dp[i] = min(dp[i], dp[i - value[j]] + cost[j]);
            }
            else
            {
                dp[i] = min(dp[i], cost[j]);
            }
        }
    }
    cout << dp[h] << endl;
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