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

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vi pref_a(n + 1, 0), pref_b(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pref_a[i + 1] = pref_a[i] + (s[i] == 'a');
        pref_b[i + 1] = pref_b[i] + (s[i] == 'b');
    }
    int maxi = LLONG_MIN;
    for (int i = 0; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            // a's before i + b's between i and j + a's after j
            int ans = pref_a[i] + (pref_b[j] - pref_b[i]) + (pref_a[n] - pref_a[j]);
            maxi = max(maxi, ans);
        }
    }
    cout << maxi << endl;
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
