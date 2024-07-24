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
#define all(x) (x).rbegin(), (x).rend()
#define set_bits(x) __builtin_popcountll(x)

void solve()
{
    ll N, M, K;cin>>N>>M>>K;
    vector<ll> A(N);
    for(auto &it : A){
        cin>>it;
    }
    if(M >= K){
        ll mini = *min_element(all(A));
        cout<<mini*K<<"\n";
        return;
    }
    ll div = (K + M - 1)/ M;
    ll m = K % M;
    priority_queue<ll> pq;
    for(auto it : A){
        if(pq.size() >= div){
            if(it < pq.top()){
                pq.push(it);
                pq.pop();
            }
        }
        else{
            pq.push(it);
        }
    }
    map<ll,deque<ll>> mp;
    if(m){
        mp[pq.top()].pb(m);
        pq.pop();
    }
    while(!pq.empty()){
        mp[pq.top()].pb(M);
        pq.pop(); 
    }
    for(auto it : mp){
        // cout<<it.first<<" -> ";
        // for(auto i : it.second){
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
        sort(all(it.second));
    }
    ll taken = 0;
    ll ans = 0;
    for(ll i=0;i<N;i++){
        if(mp[A[i]].size()){
            ans += mp[A[i]].back() * (taken + A[i]);
            taken += mp[A[i]].back();
            mp[A[i]].pop_back();
        }  
    }
    cout<<ans<<"\n";
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