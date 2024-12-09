/**
 *    author:  compounding
 *    created: 2024-12-05 22:51:17
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
    int n, m, q;
    cin >> n >> m >> q;
    string s, t;
    cin >> s >> t;
    vi diff(n, 0); // n different starting positions for t
    for (int i = 0; i <= n - m; i++)
    {
        if (s.substr(i, m) == t)
        {
            diff[i] = 1;
        }
    }
    vi prefix(n, 0);
    prefix[0] = diff[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + diff[i];
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if ((r - l + 1) < m)
        {
            cout << 0 << endl;
        }
        else
        {
            // use r-m+1 as further it we can't have t fit in
            cout << prefix[r - m + 1] - (l == 0 ? 0 : prefix[l - 1]) << endl;
        }
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