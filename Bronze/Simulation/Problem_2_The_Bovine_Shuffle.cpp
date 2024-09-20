/**
 *    author:  compounding
 *    created: 2024-09-20 16:57:45
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
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");
    int x;
    vi a, p, ans;
    map<int, int> mp;
    fin >> x;
    a.resize(x + 1);
    p.resize(x + 1);
    ans.resize(x + 1);
    for (int i = 1; i <= x; i++)
    {
        fin >> a[i];
        mp[a[i]] = i;
    }
    for (int i = 1; i <= x; i++)
    {
        fin >> p[i];
        int m = i;
        for (int k = 0; k < 3; k++)
        {
            m = mp[m];
        }
        ans[m] = p[i];
    }
    for (int i = 1; i <= x; i++)
    {
        fout << ans[i] << endl;
    }
    fin.close();
    fout.close();
    return 0;
}