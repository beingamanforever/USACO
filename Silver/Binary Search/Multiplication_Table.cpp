// Aman Behera, BeheraJi OP // header files and namespaces
#include <bits/stdc++.h>
using namespace std;
// BeheraJi code shortners use karte hue
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define PB push_back
#define endl "\n"
#define int long long
#define F first
#define S second
#define MP make_pair
//#define for(i,a,b) for(int i=a, i<b, i++)
#define BeheraJiOp ios_base::sync_with_stdio(false);cin.tie(NULL);
int mod = 1000000007;
// BeheraJI code karte hain ajao
signed main()
{   // we want to find the median and f(x)= number of elements >= x, in the matrix
    // so what we do is we divide (x) by 1, then 2, then 3... and if its >=n, then we take n as in that row
    // all are smaller than it
    BeheraJiOp;
    int n; cin>>n;
    int low=1; int high= n*n; int mid; int leq;
    while(high>low){
        mid= low+(high-low)/2;
        leq=0;
        for (int i = 1 ;i <= n; i++)
        {	leq+= min(n, mid/i);
        }
        //for median purpose
        if (leq >= (n * n + 1) / 2) {

			high = mid;

		} else {

			low = mid + 1;

		}
    }
    cout<< high <<endl;
    return 0;
}