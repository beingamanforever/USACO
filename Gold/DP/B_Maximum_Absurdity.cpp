/**
 *    author:  compounding
 *    created: 2024-12-08 17:34:33
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
const int N = 2e5 + 5;

int n, k, arr[N], ps[N], best[N];

void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ps[i] = ps[i - 1] + arr[i];
    }
    int max_suf = 0, suf_start = 0;
    for (int i = n - k + 1; i >= 1; i--)
    {
        int sum = ps[i + k - 1] - ps[i - 1];
        if (sum >= max_suf)
        {
            max_suf = sum;
            suf_start = i;
        }
        best[i] = suf_start;
    }

    int max_sum = 0, start1 = 0, start2 = 0;
    for (int i = 1; i <= n - 2 * k + 1; i++)
    {
        int sum1 = ps[i + k - 1] - ps[i - 1];
        int s2 = best[i + k];
        int sum2 = ps[s2 + k - 1] - ps[s2 - 1];
        if (sum1 + sum2 > max_sum || (sum1 + sum2 == max_sum && (i < start1 || (i == start1 && s2 < start2))))
        {
            max_sum = sum1 + sum2;
            start1 = i;
            start2 = s2;
        }
    }
    cout << start1 << " " << start2 << endl;
}

signed main()
{
    NeedForSpeed;
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
