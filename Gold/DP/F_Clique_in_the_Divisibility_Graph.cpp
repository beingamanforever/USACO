/**
 *    author:  compounding
 *    created: 2024-12-08 16:34:44
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
const int N = 1e6 + 5;
int dp[N + 1];
vi a;
void solve()
{
    int n;
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        dp[a[i]]++;
    }
    int ans = 1;
    // dont do from 1 to N, as overcounting might happen
    for (int i = N; i >= 1; i--)
    {
        if (dp[i] > 0) // if present in the array
        {
            for (int j = 2 * i; j <= N; j += i)
            {
                dp[i] = max(dp[j] + 1, dp[i]);
                ans = max(ans, dp[i]);
            }
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