/**
 *    author:  compounding
 *    created: 2024-09-21 17:28:21
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
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // m  - numbering of operations
    // k - number of queries, we have to apply all operations from (xi, yi)
    // then create the diff array and then update the array
    vector<pair<pair<int, int>, int>> ops(m + 2);
    // as we have to do r+1 so we took m+2
    for (int i = 1; i <= m; i++)
    {
        cin >> ops[i].f.f >> ops[i].f.s >> ops[i].s;
    }
    vi opscnt(m + 2, 0);
    while (k--)
    {
        int l, r;
        cin >> l >> r;
        r++;
        opscnt[l]++;
        opscnt[r]--;
    }
    for (int i = 1; i <= m; i++)
    {
        opscnt[i] += opscnt[i - 1];
    }
    vi diff(n + 2, 0);
    for (int i = 1; i <= m; i++)
    {
        diff[ops[i].f.f] += opscnt[i] * ops[i].s;
        diff[ops[i].f.s + 1] -= opscnt[i] * ops[i].s;
    }
    for (int i = 1; i <= n; i++)
    {
        diff[i] += diff[i - 1];
        a[i] += diff[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
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