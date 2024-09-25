/**
 *    author:  compounding
 *    created: 2024-09-25 17:33:47
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
bool check(vi &x, int mid, int k)
{
    int n = x.size();
    int cnt = 1;
    int last = x[0];
    for (int i = 1; i < n; i++)
    {
        if ((last + 2 * mid) < x[i])
        {
            cnt++;
            last = x[i];
        }
        if (cnt > k)
        {
            return false;
        }
    }
    return true;
}
signed main()
{
    NeedForSpeed;
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vi x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    sort(all(x));
    int low = 1, high = x[n - 1] - x[0];
    int mid, ans = high;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (check(x, mid, k))
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