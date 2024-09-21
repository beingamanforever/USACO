/**
 *    author:  compounding
 *    created: 2024-09-21 15:32:48
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
    int n;
    cin >> n;
    vi a(n);
    vi prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        prefix[i + 1] = prefix[i] + a[i];
    }
    // subarray sum from [i, j) = prefix[j] - prefix[i]
    // so for a fixed point j if we minimize prefix[i] then we maximize prefix[j] - prefix[i]
    int maxi = prefix[1];
    int mini = 0;
    for (int i = 1; i <= n; i++)
    {
        maxi = max(maxi, prefix[i] - mini);
        mini = min(mini, prefix[i]);
    }
    cout << maxi << endl;
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