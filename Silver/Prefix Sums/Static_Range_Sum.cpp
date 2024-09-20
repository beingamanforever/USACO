/**
 *    author:  compounding
 *    created: 2024-09-21 00:20:54
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
    int n, q;
    cin >> n >> q;
    vi a(n);
    vi p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
        {

            p[i] = a[i];
        }
        else
        {
            p[i] = p[i - 1] + a[i];
        }
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (l == 0)
        {
            cout << p[r - 1] << endl;
        }
        else
        {
            cout << p[r - 1] - p[l - 1] << endl;
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