/**
 *    author:  compounding
 *    created: 2024-09-29 14:27:28
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

struct fenwicktree
{
    vector<int> bit;
    int n;
    fenwicktree(int n)
    {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }
    void add(int idx, int delta)
    {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
    int sum(int idx)
    {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<tuple<int, int, int>> operations(m);
    for (int i = 0; i < m; i++)
    {
        int l, r, d;
        cin >> l >> r >> d;
        operations[i] = {l - 1, r - 1, d};
    }
    vector<pair<int, int>> queries(k);
    for (int i = 0; i < k; i++)
    {
        cin >> queries[i].f >> queries[i].s;
        queries[i].f--;
        queries[i].s--;
    }
    // counts how many times we are applying which operation, like difference arrays
    fenwicktree op_count(m);
    for (auto [l, r] : queries)
    { // add goes ahead till n, and sum goes from idx to 1
        op_count.add(l, 1);
        if (r + 1 < m)
        {
            op_count.add(r + 1, -1);
        }
    }
    fenwicktree result_tree(n);
    for (int i = 0; i < m; i++)
    {
        int op_times = op_count.sum(i);
        if (op_times > 0)
        {
            int l = get<0>(operations[i]);
            int r = get<1>(operations[i]);
            int d = get<2>(operations[i]);
            result_tree.add(l, d * op_times);
            result_tree.add(r + 1, -d * op_times);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] + result_tree.sum(i) << " ";
    }
    cout << endl;
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
