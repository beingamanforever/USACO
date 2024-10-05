/**
 *    author:  compounding
 *    created: 2024-10-06 00:44:18
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
    int n, m;
    cin >> n >> m;
    // if valid topo sort -> no cycle, then add edge from u to v, if u comes before v in ordering
    // if unvalid then cycle exists already
    vvi adj(n);
    vi indegree(n, 0);
    vpi toadd;
    for (int i = 0; i < m; i++)
    {
        int t1;
        cin >> t1;
        if (t1 == 0)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            toadd.push_back({u, v});
        }
        else
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            indegree[v]++;
        }
    }
    // check if a valid topo sort exists
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
    if (topo.size() != n)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    map<int, int> mp;
    // map the nodes to their ordering
    for (int i = 0; i < n; i++)
    {
        mp[topo[i]] = i;
    }
    for (auto &x : toadd)
    {
        if (mp[x.f] > mp[x.s])
        {
            cout << x.s + 1 << " " << x.f + 1 << endl;
        }
        else
        {
            cout << x.f + 1 << " " << x.s + 1 << endl;
        }
    }
    // print the directed edges
    for (auto &x : topo)
    {
        for (auto &y : adj[x])
        {
            cout << x + 1 << " " << y + 1 << endl;
        }
    }
    return;
}

signed main()
{
    NeedForSpeed;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}