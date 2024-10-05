/**
 *    author:  compounding
 *    created: 2024-10-05 16:28:05
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
    // for maximum length we can use dp
    // dp[v] = max(edge from u to v) (dp[u] + 1), i.e. we have to cover them in topological order
    // so as to ensure dp[u] is already calculated
    int n, m;
    cin >> n >> m;
    // node 0 - is the starting node
    // node (n-1) - is the ending node
    vvi adj(n);
    vvi backedge(n);
    vi indegree(n, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        // u -> v is the edge
        adj[u].push_back(v);
        // v -> u is the backedge, from which nodes we have path to u
        backedge[v].push_back(u);
        indegree[v]++;
    }
    // topological sort
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
        for (auto &child : adj[node])
        {
            indegree[child]--;
            // means we have covered all the edges from node to child
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }
    // dp array
    vi dist(n, INT_MIN);
    vi parent(n, -1);
    dist[0] = 1;
    for (int i = 0; i < topo.size(); i++)
    {
        int b = topo[i];
        for (auto prev : backedge[b])
        {
            if (dist[b] < dist[prev] + 1)
            {
                dist[b] = dist[prev] + 1;
                parent[b] = prev;
            }
        }
    }
    // if dist[n-1] < 0, then no path
    if (dist[n - 1] < 0)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    else
    {
        cout << dist[n - 1] << endl;
        vi path;
        int node = n - 1;
        while (node != -1)
        {
            path.push_back(node);
            node = parent[node];
        }
        reverse(all(path));
        for (auto x : path)
        {
            cout << x + 1 << " ";
        }
        cout << endl;
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