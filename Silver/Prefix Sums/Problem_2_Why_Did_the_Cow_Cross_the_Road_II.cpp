/**
 *    author:  compounding
 *    created: 2024-09-21 02:27:53
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
    ifstream fin("maxcross.in");
    ofstream fout("maxcross.out");
    int n, k, b;
    fin >> n >> k >> b;
    vi a(n, 0);
    for (int i = 0; i < b; i++)
    {
        int x;
        fin >> x;
        x--;
        a[x] = 1;
    }
    int l = 0, r = (k - 1);
    int mini = n;
    int cur = 0;
    for (int i = 0; i < k; i++)
    {
        if (a[i] == 1)
        {
            cur++;
        }
    }
    while (r < n)
    {
        mini = min(mini, cur);
        if (a[l] == 1)
        {
            cur--;
        }
        l++;
        r++;
        if (r < n && a[r] == 1)
        {
            cur++;
        }
    }
    fout << mini << endl;
    fin.close();
    fout.close();
    return 0;
}