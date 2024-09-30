/**
 *    author:  compounding
 *    created: 2024-09-30 17:13:40
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
#define endl "\n"

void solve()
{
    int k, a, b;
    cin >> k >> a >> b;
    string s;
    cin >> s;
    int n = s.size();
    if (n < k * a || n > k * b)
    {
        cout << "No solution" << endl;
        return;
    }
    int remaining = n;
    int used_lines = 0;
    for (int i = 0; i < n;)
    {
        int remaining_lines = k - used_lines;
        int line_length = min(b, remaining - (remaining_lines - 1) * a);
        cout << s.substr(i, line_length) << endl;
        i += line_length;
        remaining -= line_length;
        used_lines++;
    }
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
