/**
 *    author:  compounding
 *    created: 2024-12-07 18:29:35
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
const int maxn = 3005;
int n;
vi arr;
int dp[maxn][maxn];
// dp state -> as the optimal score for Jiro (X−Y) using the range [i,j]
int calc(int left, int right)
{
    if (left > right)
    {
        return 0;
    }
    if (dp[left][right] != -1)
    {
        return dp[left][right];
    }
    // try to take the leftmost element, or the rightmost element
    int ans = max(arr[left] - calc(left + 1, right), arr[right] - calc(left, right - 1));
    return dp[left][right] = ans;
}
void solve()
{
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    // dp[i][i] = arr[i]
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = arr[i];
    }
    int ans = calc(0, n - 1);
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