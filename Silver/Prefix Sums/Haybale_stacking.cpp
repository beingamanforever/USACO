/**
 *    author:  compounding
 *    created: 2024-09-21 12:34:58
 **/
#include <bits/stdc++.h>
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define NeedForSpeed                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
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
    int n, k;
    cin >> n >> k;
    // difference arrays
    vi diff(n + 1, 0);
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        diff[a]++;
        diff[b + 1]--;
    }
    vi ans(n, 0);
    int sum = 0;
    // prefix sum array build
    for (int i = 0; i < n; i++)
    {
        sum += diff[i];
        ans[i] = sum;
    }
    sort(ans.begin(), ans.end());
    cout << ans[n / 2] << endl;
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