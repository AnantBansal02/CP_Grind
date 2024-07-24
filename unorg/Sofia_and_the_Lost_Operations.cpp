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
    vector<ll> a(n), b(n);
    for(auto &it : a){
        cin>>it;
    }
    for(auto &it : b){
        cin>>it;
    }
    ll m; cin >> m;
    vector<ll> d(m);
    multiset<ll> mst;
    for(auto &it : d){
        cin>>it;
        mst.insert(it);
    }
    for(ll i=0;i<n;i++){
        if(a[i] != b[i]){
            if(mst.find(b[i]) == mst.end()){
                cout<<"NO"<<"\n";
                return;
            }
            mst.erase(mst.find(b[i]));
        }
    }
    bool flag = false;
    if(!mst.empty()){
        ll it = -1;
        for(ll i=m-1;i>=0;i--){
            if(mst.find(d[i]) != mst.end()){
                it = d[i];
            }
        }
        for(ll i=0;i<n;i++){
            if(b[i] == it){
                flag = true;
            }
        }
    }
    else{
        flag = true;
    }
    if(flag){
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // sieve(1e5);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}