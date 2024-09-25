/**
 *    author:  compounding
 *    created: 2024-09-25 18:59:19
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
bool check(vi &a, vi &b, int n, int m, int mid)
{
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (abs(a[i] - b[j]) <= mid)
        {
            i++;
        }
        else
        {
            j++;
        }
        if (i == n)
        {
            return true;
        }
    }
    return false;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vi a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int low = 0;
    int high = 2e9 + 1;
    int ans = high;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (check(a, b, n, m, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
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