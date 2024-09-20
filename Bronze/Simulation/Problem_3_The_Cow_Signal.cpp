/**
 *    author:  compounding
 *    created: 2024-09-20 15:53:13
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
    ifstream fin("cowsignal.in");
    ofstream fout("cowsignal.out");
    int r, c, k;
    fin >> r >> c >> k;
    vector<string> a(r);
    for (int i = 0; i < r; i++)
    {
        fin >> a[i];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < k; j++)
        {
            for (int l = 0; l < c; l++)
            {
                for (int m = 0; m < k; m++)
                {
                    fout << a[i][l];
                }
            }
            fout << endl;
        }
    }
    fin.close();
    fout.close();

    return 0;
}