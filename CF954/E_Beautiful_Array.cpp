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
    ll n, k; cin >> n >> k;
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;
    map<ll,vector<ll>> mp;
    for(auto it : arr){
        mp[it % k].push_back(it);
    }
    ll ans = 0;
    if(n % 2 == 0){
        for(auto &it : mp){
            sort(all(it.second));
            auto vec = it.second;
            ll sz = vec.size();
            if(sz & 1){
                cout << "-1" << "\n";
                return;
            }
            for(ll i=0;i<sz;i+=2){
                ans += (abs(vec[i+1] - vec[i]))/k;
            }
        }
    }
    else{
        bool flag = false;
        for(auto &it : mp){
            sort(all(it.second));
            auto vec = it.second;
            ll sz = vec.size();
            if(sz & 1){
                if(flag){
                    cout << "-1" << "\n";
                    return;
                }
                flag = true;
                if(sz == 1) continue;
                vector<ll> pre(sz), suff(sz);
                for(ll i = 1; i < sz; i += 2) pre[i] = abs(vec[i] - vec[i - 1])/k;
                for(ll i = 1; i < sz; ++i) pre[i] += pre[i - 1];
                for(ll i = sz - 2; i >= 0; i -= 2) suff[i] = abs(vec[i + 1] - vec[i])/k;
                for(ll i = sz - 2; i >= 0; --i) suff[i] += suff[i + 1];
                ll curr = INF;
                for(ll i = 0; i < sz; ++i) {
                    ll sum;
                    if(i & 1) {
                        sum = abs(vec[i + 1] - vec[i - 1])/k;
                        if(i - 2 >= 0) sum += pre[i - 2];
                        if(i + 2 < sz) sum += suff[i + 2];
                    } else {
                        sum = 0;
                        if(i - 1 >= 0) sum += pre[i - 1];
                        if(i + 1 < sz) sum += suff[i + 1];
                    }
                    curr = min(curr, sum);
                }
                ans += curr;
            }
            else{
                for(ll i=0;i<sz;i+=2){
                    ans += (vec[i+1] - vec[i])/k;
                }
            }
        }
    }

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
    while(t--){
        solve();
    }
    return 0;
}