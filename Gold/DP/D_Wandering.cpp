/**
 *    author:  compounding
 *    created: 2024-12-06 19:35:28
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
    int n;
    cin >> n;
    vi a(n);
    int prefix_sum = 0;
    int max_prefix_sum = 0;
    int cur = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        prefix_sum += a[i];
        max_prefix_sum = max(max_prefix_sum, prefix_sum);
        ans = max(ans, cur + max_prefix_sum);
        cur += prefix_sum;
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