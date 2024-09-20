/**
 *    author:  compounding
 *    created: 2024-09-20 17:08:59
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
    ifstream fin("blist.in");
    ofstream fout("blist.out");
    int n;
    fin >> n;
    vector<pair<int, int>> a;
    // line sweep algorithm
    for (int i = 0; i < n; i++)
    {
        int x, y, b;
        fin >> x >> y >> b;
        a.push_back({x, b});
        a.push_back({y + 1, -b});
    }
    sort(a.begin(), a.end());
    int maxe = INT_MIN;
    int cur = 0;
    for (int i = 0; i < a.size(); i++)
    {
        cur += a[i].s;
        maxe = max(maxe, cur);
    }
    fout << maxe << endl;
    fin.close();
    fout.close();
    return 0;
}