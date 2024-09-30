/**
 *    author:  compounding
 *    created: 2024-09-30 15:23:24
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
#define endl "\n"
const int mod = 1000000007;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
const int N = 5e5 + 8;
vi a(N);
vi freqc(N);
vi f(N);
int n, c;
int res = 0;
void solve()
{
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        freqc[i] = freqc[i - 1] + (int)(a[i] == c);
    }
    // now lets say the maximum c we can get by changing all the elements from [1,i] to c which are equal to ai = f[a[i]]
    // res  = max( res, f[a[i]] + freqc[n] - freqc[i])
    // f[a[i]] = max(f[a[i]], freqc[i])
    for (int i = 1; i <= n; i++)
    {
        f[a[i]] = max(f[a[i]] + 1, freqc[i - 1] + 1);
        res = max(res, f[a[i]] + freqc[n] - freqc[i]);
    }
    cout << res;
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