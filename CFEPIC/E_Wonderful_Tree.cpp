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

void solve(ll test)
{
    ll n; cin >> n;
    vector<ll> a(n);
    for(auto &it : a) cin >> it;
    vector<vector<ll>> t(n);
    for(ll i = 1; i < n; i++){
        ll p; cin >> p; p--;
        t[p].pb(i);
    }    
    vector<ll> b(n, 0);
    ll ans = 0;
    function<void(ll)> dfs = [&](ll node){
        ll isLeaf = 1;
        for(auto it : t[node]){
            isLeaf = 0;
            dfs(it);
        }
        if(isLeaf){
            b[node] = INF;
        }
        else{
            ll sum = 0;
            for(auto it : t[node]){
                sum += a[it];
            }
            if(sum >= a[node]){
                b[node] = sum - a[node];
            }
            else{
                ll req = a[node] - sum;
                queue<ll> q;
                q.push(node);
                ll level = 1;
                while(req > 0){
                    ll sz = q.size();
                    while(sz-- and req > 0){
                        auto curr = q.front();q.pop();
                        for(auto it : t[curr]){
                            q.push(it);
                            if(b[it] == INF){
                                ans += (level * req);
                                req = 0;
                                break;
                            }
                            else{
                                if(b[it] >= req){
                                    ans += (level * req);
                                    b[it] -= req;
                                    req = 0;
                                    break;
                                }
                                else{
                                    ans += (level * b[it]);
                                    req -= b[it];
                                    b[it] = 0;
                                }
                            }
                        }
                    }
                    level++;
                }
            }
        }
    };
    dfs(0);
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // sieve(1e5);
    ll t = 1;
    cin >> t;
    for(ll i = 1; i <= t; i++){
        solve(i);
    }
    return 0;
}