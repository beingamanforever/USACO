/**
 *    author:  compounding
 *    created: 2024-12-08 23:15:35
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
const int mod = 998244353;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
const int N = 3005;
int cache[N][N];
int a[N];
int n, s;
int dp(int idx, int sum)
{
    if (sum == 0)
    {
        // since L is fixed, we have achived the sum, so possibilities for R is n-idx+2
        return n - idx + 2;
    }
    if (idx > n)
    {
        return 0;
    }
    if (sum < 0)
    {
        return 0;
    }
    int &ans = cache[idx][sum];
    if (ans != -1)
    {
        return ans;
    }
    // we have two choices, either we take the element or we don't
    ans = (dp(idx + 1, sum) + dp(idx + 1, sum - a[idx])) % mod;
    return ans;
}
void solve()
{
    // TODO: Knapsack for all segments
    memset(cache, -1, sizeof(cache));
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // dp(idx, s) -> dp state, number of subsequences starting at idx and sum of the subsequence is s
    // dp(idx, s) = dp(idx+1, s) + dp(idx+1, s-a[idx])
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += dp(i, s);
    }
    cout << ans % mod << endl;
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