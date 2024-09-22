/**
 *    author:  compounding
 *    created: 2024-09-22 22:08:48
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
void solve()
{
    int n, m;
    cin >> n >> m;
    vvi v(n, vi(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    // calculate sum for each column and then add them up
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        vi temp;
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            temp.push_back(v[j][i]);
            sum += v[j][i];
        }
        sort(all(temp));
        int cursum = 0;
        for (int j = 0; j < n; j++)
        {
            cursum += temp[j];
            // add the contribution of the jth element to the difference sum for that column
            ans += abs(sum - cursum) - (n - 1 - j) * temp[j];
        }
    }
    cout << ans << endl;
    return;
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