/**
 *    author:  compounding
 *    created: 2024-09-21 00:28:40
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
    ifstream fin("bcount.in");
    ofstream fout("bcount.out");
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, q;
        fin >> n >> q;
        vi a(n);
        vi p1(n);
        vi p2(n);
        vi p3(n);
        for (int i = 0; i < n; i++)
        {
            fin >> a[i];
            if (i == 0)
            {
                if (a[i] == 1)
                {
                    p1[i] = 1;
                    p2[i] = 0;
                    p3[i] = 0;
                }
                else if (a[i] == 2)
                {
                    p1[i] = 0;
                    p2[i] = 1;
                    p3[i] = 0;
                }
                else
                {
                    p1[i] = 0;
                    p2[i] = 0;
                    p3[i] = 1;
                }
            }
            else
            {
                if (a[i] == 1)
                {
                    p1[i] = p1[i - 1] + 1;
                    p2[i] = p2[i - 1];
                    p3[i] = p3[i - 1];
                }
                else if (a[i] == 2)
                {
                    p1[i] = p1[i - 1];
                    p2[i] = p2[i - 1] + 1;
                    p3[i] = p3[i - 1];
                }
                else
                {
                    p1[i] = p1[i - 1];
                    p2[i] = p2[i - 1];
                    p3[i] = p3[i - 1] + 1;
                }
            }
        }
        while (q--)
        {
            int l, r;
            fin >> l >> r;
            r--;
            l--;
            if (l == 0)
            {
                fout << p1[r] << " " << p2[r] << " " << p3[r] << endl;
            }
            else
            {
                fout << p1[r] - p1[l - 1] << " " << p2[r] - p2[l - 1] << " " << p3[r] - p3[l - 1] << endl;
            }
        }
    }
    fin.close();
    fout.close();
    return 0;
}