/**
 *    author:  compounding
 *    created: 2024-09-20 15:36:07
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
void pour(int &a, int &ca, int &b, int &cb)
{
    int temp = min(a, cb - b);
    a -= temp;
    b += temp;
}
signed main()
{
    NeedForSpeed;
    ifstream fin("mixmilk.in");
    ofstream fout("mixmilk.out");
    // a, capacity of bucket-a and so on
    int a, ca, b, cb, c, cc;
    fin >> ca >> a >> cb >> b >> cc >> c;
    for (int i = 0; i < 100; i++)
    {
        if ((i % 3) == 0)
        { // a -> b
            pour(a, ca, b, cb);
        }
        else if ((i % 3) == 1)
        { // b -> c
            pour(b, cb, c, cc);
        }
        else if ((i % 3) == 2)
        { // c -> a

            pour(c, cc, a, ca);
        }
    }
    // pour(a, ca, b, cb);
    fout << a << endl
         << b << endl
         << c << endl;
    fin.close();
    fout.close();

    return 0;
}