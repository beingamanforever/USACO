/**
 *    author:  compounding
 *    created: 2024-09-25 18:08:49
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
bool check(vpi &v, int mid, int m, int n)
{
    int cnt = 1;                     // number of cows placed
    int prev = v[0].f;               // previous cow placed
    int intervalcnt = 0;             // interval numbering
    while (mid + prev <= v[m - 1].s) // in range
    {
        while (intervalcnt < m && v[intervalcnt].s < prev + mid)
        {
            intervalcnt++;
        }
        prev = max(prev + mid, v[intervalcnt].f);
        cnt++;
        if (cnt == n)
        {
            return true;
        }
    }
    return false;
}

signed main()
{
    NeedForSpeed;
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vpi v;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    sort(all(v));
    int low = 0, high = v[m - 1].s - v[0].f + 1;
    int ans = low, mid = 0;
    ;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (check(v, mid, m, n))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}