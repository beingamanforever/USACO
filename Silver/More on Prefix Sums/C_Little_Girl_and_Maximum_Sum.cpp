/**
 *    author:  compounding
 *    created: 2024-09-21 18:01:42
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
    // find the cnt of which element how many times in the query, assign maximum to
    // maximum query cnt and so on
    int n, q;
    cin >> n >> q;
    vi a(n + 1, 0);
    vi diff(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        r++;
        diff[l]++;
        diff[r]--;
    }
    for (int i = 1; i <= n + 1; i++)
    {
        diff[i] += diff[i - 1];
    }
    sort(a.begin(), a.end());
    sort(diff.begin(), diff.end());
    // for (int i = 1; i <= n + 1; i++)
    // {
    //     cout << diff[i] << " ";
    // }
    int sum = 0;
    for (int i = n; i >= 1; i--)
    {
        sum += a[i] * diff[i + 1];
    }
    cout << sum << endl;
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