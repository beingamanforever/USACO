/**
 *    author:  compounding
 *    created: 2024-12-08
 **/
#include <bits/stdc++.h>
using namespace std;
#define NeedForSpeed                  \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define int long long
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
#define endl "\n"
void solve()
{
    // ! here subsegment = subarray, so we can find LIS in O(n) time
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vi li(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] < a[i])
        {
            li[i] = li[i - 1] + 1;
        }
    }
    vi ri(n, 1);
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            ri[i] = ri[i + 1] + 1;
        }
    }
    int ans = 1;
    for (int i = 0; i <= n - 1; i++)
    {
        // convert a[i] to (a[i-1] + 1)
        if (i && i < n - 1)
        {
            if (a[i - 1] + 1 < a[i + 1])
            {
                ans = max(ans, li[i - 1] + ri[i + 1] + 1);
            }
            else
            {
                ans = max({ans, li[i - 1] + 1, ri[i + 1] + 1});
            }
        }
        else if (i)
        {
            ans = max(ans, li[i - 1] + 1);
        }
        else if (i < n - 1)
        {
            ans = max(ans, ri[i + 1] + 1);
        }
    }
    cout << ans << endl;
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
