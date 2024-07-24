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
    vector<ll> arr(n);
    for(auto &it : arr){
        cin>>it;
    } 
    function<ll(ll)> f = [&] (ll mask) -> ll {
        ll ans = 0;
        ll i = 0;
        while(i < n){
            while(i < n and ((1 << i) & mask)){
                ans += arr[i];
                i++;
            }
            ll len = 0;
            while(i < n  and !((1 << i) & mask)){
                len++;
                i++;
            }
            ans += len * len;
        }
        return ans;
    };
    ll mask = 0;
    ll ans = INT_MIN;
    ll finmask = 0;
    while(mask < (1 << n)){
        ll curr = f(mask);
        if(curr > ans){
            ans = curr;
            finmask = mask;
        }
        mask++;
    }
    vector<pair<ll,ll>> temp;
    function<void(ll, ll, ll)> help = [&](ll el, ll start, ll end){
        if(end == start and el == 1){
            temp.pb({start, end});
            return;
        }
        help(el-1, start, end-1);
        temp.pb({start, end});
        temp.pb({start+1, end});
        help(el-1, start+1, end);
    };
    ll i = 0;
    while(i < n){
        while(i < n and ((1 << i) & finmask)){
            i++;
        }
        ll len = 0;
        ll start = i+1;
        while(i < n  and !((1 << i) & finmask)){
            i++;
            len++;
        }
        if(len){
            ll l = start;
            ll r = i;
            l--;r--;
            set<ll> st;
            for(ll i=0;i<=r-l+1;i++){
                st.insert(i);
            }
            for(ll i=l;i<=r;i++){
                st.erase(arr[i]);
            }
            ll mex = *st.begin();
            if(mex == 0){
                temp.pb({start, i});
            }
            else{
                temp.pb({start, i});
                temp.pb({start, i});
            }
            if(len > 1){
                help(len-1, start, i-1);
            }
            temp.pb({start, i});
        }
    }
    cout<<ans<<" "<<temp.size()<<"\n";
    for(auto &it : temp){
        cout<<it.first<<" "<<it.second<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // seive(1e5);
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}