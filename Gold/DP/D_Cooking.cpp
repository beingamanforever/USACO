/**
 *    author:  compounding
 *    created: 2024-12-09 14:01:31
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
int n, totalsum;
vi a;
vvi cache;
int dp(int idx, int cursum)
{
    if (idx == n)
    {
        return max(cursum, totalsum - cursum);
    }
    int &ans = cache[idx][cursum];
    if (ans != -1)
    {
        return ans;
    }
    int include = dp(idx + 1, cursum + a[idx]);
    int exclude = dp(idx + 1, cursum);
    ans = min(include, exclude);
    return ans;
}

void solve()
{
    // TODO: Cooking, Atcoder, 0-1 Knapsack Variation
    cin >> n;
    a.resize(n);
    totalsum = 0;
    // kind of like divide the array into two subsets with diff being min
    // dp[i][j] = min time to cook first i dishes with sum j in first subset
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        totalsum += a[i];
    }
    cache.assign(n, vi(totalsum + 1, -1));
    cout << dp(0, 0) << endl;
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
