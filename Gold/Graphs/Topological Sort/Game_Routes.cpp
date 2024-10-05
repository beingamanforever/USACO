/**
 *    author:  compounding
 *    created: 2024-10-05 16:47:39
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
void solve()
{
    // if there are edges from say many nodes to a single node, we have to sum them up
    // dp[v] = (sum of dp[u]), if from u -> v there is an edge
    // so we have to calculate dp[u] before dp[v] - topological sort
    int n, m;
    cin >> n >> m;
    vvi adj(n);
    vvi backedge(n);
    vi indegree(n, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        backedge[v].push_back(u);
        indegree[v]++;
    }
    queue<int> q;
    vi topo;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto &x : adj[node])
        {
            indegree[x]--;
            if (indegree[x] == 0)
            {
                q.push(x);
            }
        }
    }
    vi ways(n, 0);
    ways[0] = 1; // empty set
    for (auto &node : topo)
    {
        for (auto &x : backedge[node])
        {
            ways[node] = (ways[node] + ways[x]) % mod;
        }
    }
    cout << ways[n - 1] << endl;
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