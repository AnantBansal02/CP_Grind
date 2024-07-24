#pragma GCC optimize("-Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define dbg(x) cout << #x << " = " << x << "\n"
#define pb push_back
#define fi first
#define se second
#define INF 1e18
#define all(x) (x).begin(), (x).end()
#define set_bits(x) __builtin_popcountll(x)

void solve()
{
    ll h, w, xa, ya, xb, yb;
    cin>>h>>w>>xa>>ya>>xb>>yb;
    if(xb > xa){
        if((xb - xa)%2 == 1){
            if(min(w, yb + (xb - xa)/2) > min(w, ya + (xb - xa)/2 + 1) || max(1LL, yb - (xb - xa)/2) < max(1LL, ya - (xb - xa)/2 - 1)){
                cout<<"Draw"<<"\n";
            }
            else{
                cout<<"Alice"<<"\n";
            }
        }
        else{
            if(min(w, ya + (xb - xa)/2) > min(w, yb + (xb - xa)/2) || max(1LL, ya - (xb - xa)/2) < max(1LL, yb - (xb - xa)/2)){
                cout<<"Draw"<<"\n";
            }
            else{
                cout<<"Bob"<<"\n";
            }
        }
    }
    else{
        cout<<"Draw"<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}