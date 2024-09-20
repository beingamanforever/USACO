/**
 *    author:  compounding
 *    created: 2024-09-21 01:02:28
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
    ifstream fin("div7.in");
    ofstream fout("div7.out");
    int n;
    fin >> n;
    vi a(n);
    vi p(n);
    vi modulo(7, -1);
    int maxe = 0;
    for (int i = 0; i < n; i++)
    {
        fin >> a[i];
        if (i == 0)
        {
            p[i] = a[i];
            modulo[a[i] % 7] = i;
        }
        else
        {
            p[i] = p[i - 1] + a[i];
            if (modulo[p[i] % 7] == (-1))
            {
                modulo[p[i] % 7] = i;
            }
            else
            {
                maxe = max(maxe, i - modulo[p[i] % 7]);
            }
        }
    }
    fout << maxe << endl;
    fin.close();
    fout.close();
    return 0;
}