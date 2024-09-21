/**
 *    author:  compounding
 *    created: 2024-09-21 12:58:55
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
    // legit nice one, prefix and suffix arrays for fast computation
    int n;
    cin >> n;
    vi a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // prefix and suffix gcd array
    vi prefix(n + 1, 0), suffix(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        prefix[i] = gcd(prefix[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i--)
    {
        suffix[i] = gcd(suffix[i + 1], a[i]);
    }
    int maxe = 0;
    for (int i = 1; i <= n; i++)
    {
        maxe = max(maxe, gcd(prefix[i - 1], suffix[i + 1]));
    }
    cout << maxe << endl;
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