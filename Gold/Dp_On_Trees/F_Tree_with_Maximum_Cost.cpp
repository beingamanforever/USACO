/**
 *    author:  compounding
 *    created: 2024-10-16 17:19:58
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
vi adj[200005];
int a[200005];  // cost array
vi dp(200005);  // subanswer array
vi sum(200005); // cumulative sum array
int ans = 0;    // final answer

void precompute(int u, int par)
{
    sum[u] = a[u];
    for (auto v : adj[u])
    {
        if (v != par)
        {
            precompute(v, u);
            sum[u] += sum[v];
            dp[u] += dp[v] + sum[v];
        }
    }
}
// re rooting
void dfs(int u, int par)
{
    ans = max(dp[u], ans);
    for (auto v : adj[u])
    {
        if (v != par)
        {
            int newcost = dp[u] - dp[v] - sum[v];
            int newsum = sum[u] - sum[v];
            dp[v] += (newcost + newsum);
            sum[v] += newsum;
            dfs(v, u);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans = 0;
    precompute(1, 0);
    dfs(1, 0);
    cout << ans << endl;
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
