/**
 *    author:  compounding
 *    created: 2024-09-20 16:00:52
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
    ifstream fin("speeding.in");
    ofstream fout("speeding.out");
    int n, m;
    fin >> n >> m;
    vi a(101, 0);
    int maxe = 0, prev = 0;
    while (n--)
    {
        int x, y;
        fin >> x >> y;
        for (int i = prev; i < (prev + x); i++)
        {
            a[i] = y;
        }
        prev += x;
    }
    prev = 0;
    while (m--)
    {
        int x, y;
        fin >> x >> y;
        for (int i = prev; i < (prev + x); i++)
        {
            if (a[i] < y)
            {
                maxe = max(maxe, y - a[i]);
            }
        }
        prev += x;
    }
    fout << maxe << endl;
    fin.close();
    fout.close();

    return 0;
}