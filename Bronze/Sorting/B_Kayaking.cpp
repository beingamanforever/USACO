/**
 *    author:  compounding
 *    created: 2024-09-22 22:41:31
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
    int n;
    cin >> n;
    vi v(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> v[i];
    }
    sort(all(v));
    // basically we need to pair up nearest elements, for minimum sum
    // N<= 50, so O(n^3) is fine, 2 - loops for choosing whom to leave and then calculate the sum for the rest
    int ans = LLONG_MAX;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = i + 1; j < 2 * n; j++)
        {
            vi temp;
            for (int k = 0; k < 2 * n; k++)
            {
                if (k != i && k != j)
                {
                    temp.push_back(v[k]);
                }
            }
            // minimum is b/w adj two elements
            int sum = 0;
            for (int k = 0; k < temp.size(); k += 2)
            {
                sum += abs(temp[k + 1] - temp[k]);
            }
            ans = min(ans, sum);
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