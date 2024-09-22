/**
 *    author:  compounding
 *    created: 2024-09-22 18:27:00
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
    int W, H;
    cin >> W >> H;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int w, h;
    cin >> w >> h;
    int ans = LLONG_MAX;
    if ((w + x2 - x1) <= W)
    {
        ans = min(ans, max(0LL, w - x1));
        ans = min(ans, max(0LL, x2 - (W - w)));
    }
    if ((h + y2 - y1) <= H)
    {
        ans = min(ans, max(0LL, h - y1));
        ans = min(ans, max(0LL, y2 - (H - h)));
    }
    if (ans == LLONG_MAX)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        cout << fixed << setprecision(9) << (double)ans << endl;
        return;
    }
}

signed main()
{
    NeedForSpeed;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}