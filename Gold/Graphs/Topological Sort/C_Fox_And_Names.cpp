/**
 *    author:  compounding
 *    created: 2024-10-05 17:18:09
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
vi indegree;
void solve()
{
    int n;
    cin >> n;
    adj.resize(26);
    indegree.resize(26, 0);
    string s;
    cin >> s;
    string prev = s;
    string cur;
    for (int i = 1; i < n; i++)
    {
        cin >> cur;
        // maximum length to compare
        int len = min(prev.size(), cur.size());
        int same = 0; // how much part is same
        while (same < len)
        {
            // means we found a dissimilarity
            if (prev[same] != cur[same])
            {
                // and prev's that letter should come before cur's letter
                // so there should be an edge from prev -> cur
                int ncur = cur[same] - 'a';
                int nprev = prev[same] - 'a';
                adj[nprev].push_back(ncur);
                indegree[ncur]++;
                break;
            }
            same++;
        }
        // if cur is a prefix of prev, and lenth of prev is more then its impossible
        if ((same == len) && prev.size() > cur.size())
        {
            cout << "Impossible" << endl;
            return;
        }
        prev = cur;
    }
    // topological sort
    queue<int> q;
    vi topo;
    for (int i = 0; i < 26; i++)
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
            if ((--indegree[x]) == 0)
            {
                q.push(x);
            }
        }
    }
    if (topo.size() < 26)
    {
        cout << "Impossible" << endl;
        return;
    }
    for (auto &x : topo)
    {
        cout << (char)(x + 'a');
    }
    cout << endl;
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