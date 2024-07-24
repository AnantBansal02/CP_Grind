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
    ll n; cin >> n;
    vector<vector<ll>> tree(n);
    for(ll i = 1; i < n; i++){
        ll u, v; cin >> u >> v;
        u--;v--;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    vector<ll> sub(n, INF);
    function<void(ll, ll)> dfs = [&] (ll node, ll par){
        vector<ll> child;
        for(auto it : tree[node]){
            if(it == par) continue;
            dfs(it, node);
            child.pb(sub[it]);
        }
        ll last = 1;
        ll f = 1;
        sort(all(child));
        for(auto it : child){
            if(it <= last){
                last += it;
            }
            else{
                sub[node] = INF;
                f = 0;
                break;
            }
        }
        if(f){
            sub[node] = last;
        }
    };  
    dfs(0, -1);
    if(sub[0] == n){
        cout << "YES" << "\n";
        return;
    }
    ll ans = 0;
    function<void(ll, ll, ll)> reroot = [&] (ll node, ll par, ll prev){
        vector<pair<ll,ll>> arr;
        for(auto it : tree[node]){
            if(it == par){
                arr.pb({it, prev});
            }
            else{
                arr.pb({it, sub[it]});
            }
        }
        sort(all(arr), [&](pair<ll,ll>&a, pair<ll,ll>&b){
            return a.second < b.second;
        });
        ll sz = arr.size();
        ll flag = 1;
        ll last = 1;
        for(ll i = 0; i < sz; i++){
            auto it = arr[i];
            if(it.second <= last){
                last += it.second;
            }
            else if(flag){
                for(ll j = i + 1; j < sz; j++){
                    if(last >= arr[j].second){
                        last += arr[j].second;
                    }
                    else{
                        flag = 0;
                        break;
                    }
                }
                if(it.first == par){
                    flag = 0;
                }
                if(flag){
                    reroot(it.first, node, last);
                }
                flag = 0;
            }
            else{
                break;
            }
        }
        if(flag){
            ans = 1;
        }
    };

    reroot(0, -1, 0);

    if(ans){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
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