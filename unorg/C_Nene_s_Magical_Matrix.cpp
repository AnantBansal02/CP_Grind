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
    ll n;cin>>n;
    ll sum = 0;
    ll mul = 1;
    for(ll i=1;i<=n;i++){
        sum += i * mul;
        mul += 2;
    }
    cout<<sum<<" "<<2*n<<"\n";
    for(ll i=n;i>=1;i--){
        cout<<1<<" "<<i<<" ";
        for(ll j=1;j<=n;j++){
            cout<<j<<" ";
        }
        cout<<"\n";
        cout<<2<<" "<<i<<" ";
        for(ll j=1;j<=n;j++){
            cout<<j<<" ";   
        }
        cout<<"\n";
    }    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // seive(1e5);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}