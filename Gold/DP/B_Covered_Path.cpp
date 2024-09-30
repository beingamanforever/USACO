/**
 *    author:  compounding
 *    created: 2024-09-30 17:38:58
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
#define endl "\n"

void solve()
{
    int v1, v2, t, d;
    cin >> v1 >> v2 >> t >> d;
    // speed at time t
    vi speed(t);
    speed[0] = v1;
    speed[t - 1] = v2;
    // think like, v2 is a line and we have (t-i-1) intervals so the maximum we can get at t = i is v2 + (t-i-1)*d
    // and before this we have some speed[i-1], and maximum increase we can get to is speed[i-1] + d
    // so we take minimum of these two
    for (int i = 1; i < t - 1; i++)
    {
        speed[i] = min(speed[i - 1] + d, v2 + (t - 1 - i) * d);
    }
    int total = 0;
    for (int i = 0; i < t; i++)
    {
        total += speed[i];
    }
    cout << total << endl;
}

signed main()
{
    NeedForSpeed;
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
