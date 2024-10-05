/**
 *    author:  compounding
 *    created: 2024-10-05 15:48:03
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
vvi adj;
vb visited, path_visited;
vi cycle;
bool dfs(int node)
{
    visited[node] = true;
    path_visited[node] = true;
    // path visited means the ones we are currently processing
    for (auto child : adj[node])
    {
        if (path_visited[child]) // start cycle
        {
            // means child is a grey node, hence it can be a part of cycle
            cycle.push_back(node);
            path_visited[node] = false;
            path_visited[child] = false;
            return true;
        }
        else if (!visited[child]) // white node so visit it
        {
            if (dfs(child)) // if cycle found, continue cycle
            {
                if (path_visited[node])
                {
                    cycle.push_back(node);
                    path_visited[node] = false;
                    return true;
                }
                else
                { // found you again
                    cycle.push_back(node);
                    return false;
                }
            }
            if (!cycle.empty())
            { // cycle found, finished
                return false;
            }
        }
    }
    path_visited[node] = false;
    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    // for cycle it should be visited + its neighbours should be in path visited
    adj.resize(n);
    visited.resize(n, false);
    path_visited.resize(n, false);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }
    for (int i = 0; i < n && cycle.empty(); i++)
    {
        dfs(i);
    }
    if (cycle.empty())
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    reverse(cycle.begin(), cycle.end());
    cout << cycle.size() + 1 << endl;
    for (auto x : cycle)
    {
        cout << x + 1 << " ";
    }
    cout << cycle[0] + 1 << endl;
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