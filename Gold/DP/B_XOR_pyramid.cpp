/**
 *    author:  compounding
 *    created: 2024-12-06 17:13:54
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
const int maxn = 5005;
int n;
int a[maxn];
int dp[maxn][maxn];
int ans[maxn][maxn];
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = a[i];
    }
    // the length of the segment = len -> 3 has to be calculated before 4, so it's in outer loop
    for (int len = 1; len <= n; len++)
    {
        for (int i = 1; (i + len) <= n; i++)
        {
            dp[i][i + len] = dp[i][i + len - 1] ^ dp[i + 1][i + len];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans[i][i] = dp[i][i];
    }
    // key idea -> to caclulate the ans for len 4, use the answers of len 3
    for (int len = 1; len <= n; len++)
    {
        for (int i = 1; (i + len) <= n; i++)
        {
            // max among the whole dp[i][i+len] or ans[i][i+len-1] or ans[i+1][i+len]
            // ans[i][i+len] represents the maximum xor value of the segment [i,i+len]
            int j = i + len;
            ans[i][j] = max({ans[i][j - 1], ans[i + 1][j], dp[i][j]});
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << ans[l][r] << endl;
    }
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