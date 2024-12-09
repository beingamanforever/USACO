/**
 *    author:  compounding
 *    created: 2024-12-06 18:12:39
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
const int maxi = 90001;
int posx[maxi], posy[maxi];
int cost[maxi];
void solve()
{
    int h, w, d;
    cin >> h >> w >> d;
    // O(1) hashing
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            int x;
            cin >> x;
            posx[x] = i;
            posy[x] = j;
        }
    }
    // cost to get to (1<= x <=d) = 0 (as it can't be reached from elsewhere)
    for (int i = d + 1; i <= w * h + 1; i++)
    {
        cost[i] = cost[i - d] + abs(posx[i] - posx[i - d]) + abs(posy[i] - posy[i - d]);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << cost[r] - cost[l] << endl;
    }
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