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
    string s;cin>>s;
    ll n = s.size();
    ll cum = 0;
    vector<ll> pre(n, 0);
    for(ll i=0;i<n;i++){
        cum += (s[i] == '(') - (s[i] == ')');
        pre[i] = cum;
    }
    map<ll, vector<ll>> mp;
    for(ll i=0;i<n;i++){
        mp[pre[i]].push_back(i);
    }

    ll LOG = 20;
    vector<vector<ll>> sparse(LOG, vector<ll>(n));
    for(ll j=0;j<n;j++){
        sparse[0][j] = pre[j];
    }
    for(ll i=1;i<LOG;i++){
        for(ll j=0;j+(1 << (i-1))<n;j++){
            sparse[i][j] = max(sparse[i-1][j], sparse[i-1][j+(1 << (i-1))]);
        }
    }
    ll lg[n+1] = {0};
    lg[1] = 0;
    for(ll i=2;i<=n;i++){
        lg[i] = lg[i/2] + 1;
    }
    auto query = [&](ll L, ll R){
        ll val = lg[R - L + 1];
        return max(sparse[val][L], sparse[val][R - (1 << val)+1]);
    };
    auto cnt = [&](vector<ll>& arr, ll idx, ll l){
        return max(0, upper_bound(arr.begin(), arr.end(), idx) - lower_bound(arr.begin(), arr.end(), l));
    };
    ll ans = 0;
    for(ll i=1;i<n;i++){
        ll low = i+1;
        ll high = n-1;
        ll idx = -1;
        while(low <= high){
            ll mid = low + high >> 1;
            ll q = query(i, mid);
            if(q <= 2*pre[i-1]){
                idx = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        vector<ll>& arr = mp[pre[i-1]];
        ans += cnt(arr, idx, i);
    }
    cout<<ans<<"\n";
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