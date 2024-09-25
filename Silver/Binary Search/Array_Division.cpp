/**
 *    author:  compounding
 *    created: 2024-09-25 19:07:44
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
bool check(vi &a, int mid, int k)
{
	int cnt = 0;
	int cursum = 0;
	int n = a.size();
	for (int i = 0; i < n; i++)
	{
		if (a[i] > mid)
		{ // then we can't even take this element
			return false;
		}
		else if ((a[i] + cursum) > mid)
		{
			cnt++;
			cursum = 0;
		}
		cursum += a[i];
	}
	// slight mistake
	if (cursum > 0)
	{
		cnt++;
	}
	return cnt <= k;
}
void solve()
{
	int n, k;
	cin >> n >> k;
	vi v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int low = 1, high = LLONG_MAX, mid;
	int ans = low;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (check(v, mid, k))
		{
			// take more
			ans = mid;
			high = mid - 1;
		}
		else
		{

			low = mid + 1;
		}
	}
	cout << ans << endl;
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