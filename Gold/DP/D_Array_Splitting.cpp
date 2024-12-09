/**
 *    author:  compounding
 *    created: 2024-12-06 00:59:51
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
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // after transformation = S(p1)+S(p2)+...+S(pk)
    vi suffix;
    int suff = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        suff += a[i];
        if (i > 0)
        {
            suffix.push_back(suff);
        }
    }
    sort(all(suffix));
    reverse(all(suffix));
    int ans = suff;
    for (int i = 0; i < k - 1; i++)
    {
        ans += suffix[i];
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