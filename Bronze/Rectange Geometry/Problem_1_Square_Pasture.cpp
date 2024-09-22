/**
 *    author:  compounding
 *    created: 2024-09-22 15:27:09
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
signed main()
{
    NeedForSpeed;
    freopen("square.in", "r", stdin);
    freopen("square.out", "w", stdout);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    // make sure its a square
    int p = min(x1, a);
    int q = min(y1, b);
    int r = max(x2, c);
    int s = max(y2, d);
    int check1 = abs(p - r);
    int check2 = abs(q - s);
    if (check2 > check1)
    {
        swap(check1, check2);
    }
    s = q + check1;
    cout << check1 * check1 << endl;

    return 0;
}