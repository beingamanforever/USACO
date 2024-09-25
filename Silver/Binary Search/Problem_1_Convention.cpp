/**
 *    author:  compounding
 *    created: 2024-09-25 17:08:45
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
bool check(int mid, vi &t, int n, int m, int c)
{
    int cnt = 1;
    int prev = t[0];
    int bus = 1;
    for (int i = 1; i < n; i++)
    {
        if (t[i] - prev <= mid && cnt < c)
        {
            cnt++;
        }
        else
        {
            prev = t[i];
            cnt = 1;
            bus++;
        }
        if (bus > m)
        {
            return false;
        }
    }
    return true;
}
signed main()
{
    NeedForSpeed;
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);
    int n, m, c;
    cin >> n >> m >> c;
    vi t(n);
    for (int i = 0; i < n; i++)
    {
        cin >> t[i];
    }
    sort(all(t));
    int low = 0;
    int high = t[n - 1] - t[0];
    int mid = high;
    int ans = high;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (check(mid, t, n, m, c))
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
    return 0;
}