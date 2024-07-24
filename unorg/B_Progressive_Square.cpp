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
    ll N, C, D;
    cin>>N>>C>>D;
    ll sz = N*N;
    vector<ll> A(sz);
    multiset<ll> mst;
    for(auto &it : A){
        cin>>it;
    }
    for(auto it : A){
        mst.insert(it);
    }
    vector<vector<ll>> ans(N, vector<ll>(N, 0));
    ll start = *min_element(all(A));
    for(ll i=0;i<N;i++){
        for(ll j=0;j<N;j++){
            if(i == 0 and j == 0){
                ans[i][j] = start;
                mst.erase(mst.find(start));
                continue;
            }
            if(i >= 1 and mst.find(ans[i-1][j] + C) == mst.end()){
                cout<<"NO"<<"\n";
                return;
            }
            if(j >= 1 and mst.find(ans[i][j-1] + D) == mst.end()){
                cout<<"NO"<<"\n";
                return;
            }
            if(i >= 1 and j >= 1 and (ans[i-1][j] + C) != (ans[i][j-1] + D)){
                cout<<"NO"<<"\n";
                return;
            }
            if(i >= 1){
                ans[i][j] = ans[i-1][j] + C;
                mst.erase(mst.find(ans[i-1][j] + C));
            }
            else if(j >= 1){
                ans[i][j] = ans[i][j-1] + D;
                mst.erase(mst.find(ans[i][j-1] + D));
            }
        }
    }
    cout<<"YES"<<"\n";
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