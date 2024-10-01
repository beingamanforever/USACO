/**
 *    author:  compounding
 *    created: 2024-10-01 23:55:00
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
    int n;
    cin >> n;
    // as its asking for minimum initialize the dp array with 1e9
    vi dp(n + 1, 1e9);
    dp[0] = 0; // empty set
    // pull dp -> use the previous values to calculate the current value
    for (int i = 1; i <= n; i++)
    {
        int x = i;
        while (x > 0)
        { // pull dp
            dp[i] = min(dp[i], dp[i - (x % (10))] + 1);
            x /= 10;
        }
    }
    cout << dp[n] << endl;
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