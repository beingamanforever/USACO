/**
 *    author:  compounding
 *    created: 2024-12-05 23:46:34
 **/
#include <bits/stdc++.h>
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
#define NeedForSpeed                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<pair<int, int>> vpi;
#define f first
#define s second
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define endl "\n"
const int mod = 1000000007;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
void solve()
{
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    for (int i = 0; i < h; ++i)
    {
        cin >> grid[i];
    }
    vvi hor(h + 1, vi(w + 1, 0)), ver(h + 1, vi(w + 1, 0));
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            // hor, ver prefix sums
            hor[i][j] = hor[i - 1][j] + hor[i][j - 1] - hor[i - 1][j - 1];
            ver[i][j] = ver[i - 1][j] + ver[i][j - 1] - ver[i - 1][j - 1];
            // current cell = (i, j) -> right = (i, j+1), down = (i+1, j)
            if ((j < w) && grid[i - 1][j - 1] == '.' && grid[i - 1][j] == '.')
            {
                hor[i][j]++;
            }
            if ((i < h) && grid[i - 1][j - 1] == '.' && grid[i][j - 1] == '.')
            {
                ver[i][j]++;
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int horiz = hor[r1 - 1][c1 - 1] - hor[r1 - 1][c2 - 1] - hor[r2][c1 - 1] + hor[r2][c2 - 1];
        int verti = ver[r1 - 1][c1 - 1] - ver[r1 - 1][c2] - ver[r2 - 1][c1 - 1] + ver[r2 - 1][c2];
        cout << horiz + verti << endl;
    }
    return;
}

signed main()
{
    NeedForSpeed;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}