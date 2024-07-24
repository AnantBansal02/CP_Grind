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
    ll m;cin>>m;
    vector<vector<ll>> arr(m);
    multiset<ll> mst;
    for(ll i=0;i<m;i++){
        ll n;cin>>n;
        vector<ll> temp(n);
        for(auto &it : temp){
            cin>>it;
            mst.insert(it);
        }
        arr[i] = temp;
    } 
    vector<ll> ans(m);
    for(ll i=0;i<m;i++){
        ll flag = false;
        for(ll j=0;j<arr[i].size();j++){
            mst.erase(mst.find(arr[i][j]));
            if(!flag and mst.find(arr[i][j]) == mst.end()){
                ans[i] = arr[i][j];
                flag = true;
            }
        }
        if(!flag){
            cout<<"-1"<<"\n";
            return;
        }
    }
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<"\n";

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