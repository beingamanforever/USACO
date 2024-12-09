/**
 *    author:  compounding
 *    created: 2024-12-05 16:44:36
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
vi ans(87);
void precompute()
{
    int p1 = 2;
    int p2 = 1;
    ans[0] = p1; // L0 = 2
    ans[1] = p2; // L1 = 1
    for (int i = 2; i <= 86; i++)
    {
        ans[i] = p1 + p2;
        int temp = p1;
        p1 = p2;
        p2 = ans[i];
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << ans[n] << endl;
    return;
}

signed main()
{
    NeedForSpeed;
    int t = 1;
    precompute();
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}