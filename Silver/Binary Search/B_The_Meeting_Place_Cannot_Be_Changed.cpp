/**
 *    author:  compounding
 *    created: 2024-09-08 22:33:57
 **/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define NeedForSpeed                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
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
    int n = 1;
    cin >> n;
    vi x(n), v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // the meeting place can be b/w the min and max of x[i]
    long double l = 0;
    long double r = (1e9);
    while ((r - l) > 1e-7) // precision
    {
        long double mid = l + (r - l) / 2;
        long double maxleft = -mod;
        long double minright = mod;
        // we have to compute the minimum time required to reach the meeting point
        // we see how far we can reach from each point towards the left and right
        // and basically the minright should be greater than maxleft, if it is then we check for even smaller time
        for (int i = 0; i < n; i++)
        {
            maxleft = max(maxleft, x[i] - v[i] * mid);
            minright = min(minright, x[i] + v[i] * mid);
        }
        if ((minright - maxleft) >= 0)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << fixed << setprecision(29) << r << endl;
    return 0;
}