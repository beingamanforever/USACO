/**
 *    author:  compounding
 *    created: 2024-09-21 01:48:35
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
    // in usaco use, fin and fout
    ifstream fin("hps.in");
    ofstream fout("hps.out");
    int n;
    fin >> n;
    vi h(n, 0);
    vi p(n, 0);
    vi s(n, 0);
    for (int i = 0; i < n; i++)
    {
        char x;
        fin >> x;
        if (i == 0)
        {
            if (x == 'H')
            {
                p[i] = 1;
            }
            if (x == 'P')
            {
                s[i] = 1;
            }
            if (x == 'S')
            {
                h[i] = 1;
            }
        }
        else
        {
            if (x == 'H')
            {
                h[i] = h[i - 1];
                p[i] = p[i - 1] + 1;
                s[i] = s[i - 1];
            }
            if (x == 'P')
            {
                h[i] = h[i - 1];
                p[i] = p[i - 1];
                s[i] = s[i - 1] + 1;
            }
            if (x == 'S')
            {
                h[i] = h[i - 1] + 1;
                p[i] = p[i - 1];
                s[i] = s[i - 1];
            }
        }
    }
    int maxe = 0;
    for (int i = 0; i < n; i++)
    {
        maxe = max(maxe, h[i] + p[n - 1] - p[i]);
        maxe = max(maxe, h[i] + s[n - 1] - s[i]);
        maxe = max(maxe, p[i] + h[n - 1] - h[i]);
        maxe = max(maxe, p[i] + s[n - 1] - s[i]);
        maxe = max(maxe, s[i] + h[n - 1] - h[i]);
        maxe = max(maxe, s[i] + p[n - 1] - p[i]);
    }
    fout << maxe << endl;
    fin.close();
    fout.close();
    return 0;
}