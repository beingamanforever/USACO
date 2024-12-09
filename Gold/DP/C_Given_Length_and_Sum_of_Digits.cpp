/**
 *    author:  compounding
 *    created: 2024-12-05 18:59:58
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
void solve()
{
    int m, s;
    cin >> m >> s;
    if (s == 0)
    {
        if (m == 1)
        {
            cout << "0 0" << endl;
        }
        else
        {
            cout << "-1 -1" << endl;
        }
        return;
    }
    // smallest number
    string min_num = "";
    int remaining_sum = s;
    for (int i = 0; i < m; i++)
    {
        // we can't have 0 at the start
        for (int digit = (i == 0 ? 1 : 0); digit <= 9; digit++)
        {
            if ((remaining_sum - digit) >= 0 && (remaining_sum - digit) <= 9 * (m - i - 1))
            {
                min_num += char('0' + digit);
                remaining_sum -= digit;
                break;
            }
        }
    }
    if (remaining_sum > 0)
    {
        cout << "-1 -1" << endl;
        return;
    }
    // largest number
    string max_num = "";
    remaining_sum = s;
    for (int i = 0; i < m; i++)
    {
        for (int digit = 9; digit >= 0; digit--)
        {
            if (remaining_sum - digit >= 0 && remaining_sum - digit <= 9 * (m - i - 1))
            {
                max_num += char('0' + digit);
                remaining_sum -= digit;
                break;
            }
        }
    }
    cout << min_num << " " << max_num << endl;
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
