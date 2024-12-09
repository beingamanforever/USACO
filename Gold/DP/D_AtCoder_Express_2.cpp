/**
 *    author:  compounding
 *    created: 2024-12-06 18:33:24
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
typedef vector<vi> vvi;
typedef vector<pair<int, int>> vpi;
#define f first
#define s second
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const int mod = 1000000007;
void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vvi prefix(n + 1, vi(n + 1, 0));
    for (int i = 0; i < m; i++)
    {
        // 2D prefix sum -> number of trains that start at l, end at r
        int l, r;
        cin >> l >> r;
        prefix[l][r]++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            prefix[i][j] += prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
        }
    }
    while (q--)
    {
        int p, q;
        cin >> p >> q;
        cout << prefix[q][q] - prefix[p - 1][q] - prefix[q][p - 1] + prefix[p - 1][p - 1] << endl;
    }
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
