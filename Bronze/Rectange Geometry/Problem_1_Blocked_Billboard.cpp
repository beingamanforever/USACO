/**
 *    author:  compounding
 *    created: 2024-09-22 02:43:43
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
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<pair<int, int>> vpi;
#define f first
#define s second
#define endl "\n"
const int mod = 1000000007;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
struct rect
{
    int x1, y1, x2, y2;
    int area()
    { // length * breadth
        return (x2 - x1) * (y2 - y1);
    }
};
int interection(rect a, rect b)
{
    // x overlap
    int xoverlap = max(0LL, min(a.x2, b.x2) - max(a.x1, b.x1));
    // y overlap
    int yoverlap = max(0LL, min(a.y2, b.y2) - max(a.y1, b.y1));
    return xoverlap * yoverlap;
}
signed main()
{
    NeedForSpeed;
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    rect a, b, t;
    cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
    cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
    cin >> t.x1 >> t.y1 >> t.x2 >> t.y2;
    int ans = a.area() + b.area();
    int intersection = interection(a, t) + interection(b, t);
    cout << ans - intersection << endl;

    return 0;
}