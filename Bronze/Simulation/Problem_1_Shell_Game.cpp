/**
 *    author:  compounding
 *    created: 2024-09-20 15:03:25
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
#define endl "\n"
const int mod = 1000000007;

signed main()
{
    ifstream fin("shell.in");
    ofstream fout("shell.out");
    NeedForSpeed;
    int t;
    fin >> t;
    vector<tuple<int, int, int>> moves(t);
    for (int i = 0; i < t; i++)
    {
        int a, b, g;
        fin >> a >> b >> g;
        moves[i] = {a - 1, b - 1, g - 1};
    }
    int max_score = 0;
    for (int initial = 0; initial < 3; initial++)
    {
        vi pebble(3, 0);
        pebble[initial] = 1;
        int cur_score = 0;

        for (const auto &[a, b, g] : moves)
        {
            swap(pebble[a], pebble[b]);
            if (pebble[g] == 1)
            {
                cur_score++;
            }
        }
        max_score = max(max_score, cur_score);
    }
    fout << max_score << endl;
    fin.close();
    fout.close();
    return 0;
}
