/**
 *    author:  compounding
 *    created: 2024-09-20 19:34:33
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
    ifstream fin("traffic.in");
    ofstream fout("traffic.out");
    int n;
    fin >> n;
    // in usaco use, fin and fout
    vector<pair<string, pair<int, int>>> a(n);
    for (int i = 0; i < n; i++)
    {
        fin >> a[i].f >> a[i].s.f >> a[i].s.s;
    }
    // move from start to end
    int x = 0;
    int y = INT_MAX;
    bool yes = false;
    // move from end to front
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i].f == "off")
        {
            x += a[i].s.f;
            y += a[i].s.s;
        }
        else if (a[i].f == "on")
        {
            x -= a[i].s.s;
            y -= a[i].s.f;
        }
        else
        {
            x = max(x, a[i].s.f);
            if (yes)
            {
                y = min(y, a[i].s.s);
            }
            else
            {
                y = a[i].s.s;
            }
            yes = true;
        }
        x = max(x, 0LL);
    }
    fout << x << " " << y << endl;
    x = 0, y = INT_MAX;
    yes = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i].f == "on")
        {
            x += a[i].s.f;
            y += a[i].s.s;
        }
        else if (a[i].f == "off")
        {
            x -= a[i].s.s;
            y -= a[i].s.f;
        }
        else
        {
            x = max(x, a[i].s.f);
            if (yes)
            {
                y = min(y, a[i].s.s);
            }
            else
            {
                y = a[i].s.s;
            }
            yes = true;
        }
        x = max(x, 0LL);
    }
    fout << x << " " << y << endl;
    fin.close();
    fout.close();
    return 0;
}