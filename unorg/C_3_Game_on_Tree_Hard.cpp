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
    ll n, t;cin>>n>>t;
    vector<vector<ll>> tree(n);
    for(ll i=0;i<n-1;i++){
        ll u,v;cin>>u>>v;u--;v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<ll> rounds(t);
    for(ll i=0;i<t;i++){
        cin>>rounds[i];
        rounds[i]--;
    }
    vector<ll> sub(n, -1);
    function<void(ll, ll)> dfs = [&] (ll node, ll par) {
        for(auto it : tree[node]){
            if(it == par) continue;
            dfs(it, node);
            if(sub[it] == 0){
                sub[node] = 1;
            }
        }
        if(sub[node] == -1){
            sub[node] = 0;
        }
    };
    dfs(0, -1);
    vector<ll> win(n, -1);
    win[0] = sub[0];
    function<void(ll, ll, ll)> reroot = [&] (ll node, ll par, ll curr) {
        vector<ll> pre, suff;
        for(auto it : tree[node]){
            if(it == par) continue;
            pre.pb(sub[it]);
            suff.pb(sub[it]);
        }
        ll sz = pre.size();
        for(ll i=1;i<sz;i++){
            pre[i] += pre[i-1];
        }
        for(ll i=sz-2;i>=0;i--){
            suff[i] += suff[i+1];
        }
        ll i = 0;
        for(auto it : tree[node]){
            if(it == par) continue;
            ll left = (i == 0 ? 0 : pre[i-1]);
            ll right = (i == sz - 1 ? 0 : suff[i+1]);
            
            ll newCurr = 0;
            if(left + right < sz - 1 || curr == 0){
                newCurr = 1;
            }
            win[it] = sub[it];
            if(newCurr == 0){
                win[it] = 1;
            }
            reroot(it, node, newCurr);
            i++;
        }
    };
    reroot(0, -1, 1);
    for(auto it : rounds){
        if(win[it]){
            cout<<"Ron"<<"\n";
        }
        else{
            cout<<"Hermione"<<"\n";
        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // sieve(1e5);
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}