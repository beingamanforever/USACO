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

// GCD function
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
struct Node
{
    Node *links[10];
    int cntPrefix = 0;

    bool containsKey(int num)
    {
        return links[num] != NULL;
    }

    Node *get(int num)
    {
        return links[num];
    }

    void put(int num, Node *node)
    {
        links[num] = node;
    }

    void increasePrefix()
    {
        cntPrefix++;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string number)
    {
        Node *node = root;
        for (char ch : number)
        {
            int digit = ch - '0';
            if (!node->containsKey(digit))
            {
                node->put(digit, new Node());
            }
            node = node->get(digit);
            node->increasePrefix();
        }
    }

    int search(const string &number)
    {
        Node *node = root;
        for (char ch : number)
        {
            int digit = ch - '0';
            if (node->containsKey(digit))
            {
                node = node->get(digit);
            }
            else
            {
                return 0;
            }
        }
        return node->cntPrefix;
    }
};

string wordToNumeric(const string &word, const vector<string> &runeMap)
{
    string number = "";
    for (char ch : word)
    {
        for (int i = 2; i <= 9; i++)
        {
            if (runeMap[i].find(ch) != string::npos)
            {
                number += (i + '0');
                break;
            }
        }
    }
    return number;
}

signed main()
{
    NeedForSpeed;
    int n, m;
    cin >> n >> m;
    vector<string> runeMap = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    Trie trie;
    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        string numericSequence = wordToNumeric(name, runeMap);
        trie.insert(numericSequence);
    }
    for (int i = 0; i < m; i++)
    {
        string sequence;
        cin >> sequence;
        cout << trie.search(sequence) << endl;
    }

    return 0;
}
