/**
 *    author:  compounding
 *    created: 2024-09-20 16:18:05
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
    // closed formula wont work, so simulation is better
    ifstream fin("lostcow.in");
    ofstream fout("lostcow.out");
    int x, y;
    if (!fin)
    {
        cin >> x >> y;
    }
    else
    {
        fin >> x >> y;
    }
    int dis = 0;
    int cur = x;
    int step = 1;
    bool forw = true;
    while (true)
    {
        int tar = x + step;
        int move = abs(cur - tar);
        if ((forw && y <= tar && y >= cur) || (!forw && y >= tar && y <= cur))
        {
            dis += abs(cur - y);
            break;
        }
        else
        {
            dis += move;
        }
        cur = tar;
        step *= -2;
        forw = !forw;
    }
    if (!fin)
    {
        cout << dis << endl;
    }
    else
    {
        fout << dis << endl;
        fin.close();
        fout.close();
    }

    return 0;
}
