/**
 *    author:  compounding
 *    created: 2024-09-25 16:27:51
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
#define endl "\n"
const int mod = 1000000007;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
bool check(vi &a, int mid, int t)
{
    priority_queue<int> pq;
    int n = a.size();
    int time = 0;
    int j = 0;
    int size = 0;
    for (int i = 0; i < mid; i++)
    {
        pq.push(-a[i]);
        size++;
        j++;
    }
    while ((int)(pq.size()))
    {
        time += max(-pq.top() - time, 0LL);
        pq.pop();
        if (j < n)
        {
            pq.push(-(a[j] + time));
            j++;
        }
    }
    if (time > t)
    {
        return false;
    }
    return true;
}
signed main()
{
    NeedForSpeed;
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);
    int n, t;
    cin >> n >> t;
    vi d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    int low = 1, high = (n);
    int mid;
    int ans = high;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (check(d, mid, t))
        {
            ans = min(ans, mid);
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}