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
    ll n, m, k; cin >> n >> m >> k;
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;

    vector<vector<ll>> q(m, vector<ll>(3));
    for(ll i=0;i<m;i++){
        cin >> q[i][0] >> q[i][1];
        q[i][2] = i;
    }
    const ll sz = sqrt(n);
    sort(all(q), [&](vector<ll>&a, vector<ll>&b){
        ll x = (a[0] - 1)/sz;
        ll y = (b[0] - 1)/sz;
        if(x == y){
            return a[1] < b[1];
        } 
        return x < y;
    });
    vector<ll> pre(n+1, 0);
    for(ll i=1;i<=n;i++){
        pre[i] = (arr[i-1] ^ pre[i-1]);
    }
    vector<ll> ans(m);
    vector<ll> mp(1 << 20, 0);
    ll left = 1;
    ll right = 0;
    ll curr = 0;
    for(auto it : q){
        ll l = it[0];
        ll r = it[1];
        while(left < l){
            ll num = pre[left];
            mp[num]--;
            curr -= mp[num ^ k];
            left++;            
        }
        while(left > l){
            left--;
            ll num = pre[left];
            curr += mp[num ^ k];
            mp[num]++;
        }
        while(right < r){
            right++;
            ll num = pre[right];
            curr += mp[num ^ k];
            mp[num]++;

        }
        while(right > r){
            ll num = pre[right];
            mp[num]--;
            curr -= mp[num ^ k];
            right--;
        }
        ans[it[2]] = curr + mp[pre[l-1] ^ k];
    }

    for(auto it : ans){
        cout << it << '\n';
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