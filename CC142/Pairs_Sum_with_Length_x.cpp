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


class STLazy{
    public:
    vector<ll> st, cnt;
    static ll N;
    STLazy(ll n){
        st.resize(4*n+1, 0);
        cnt.resize(4*n+1, 0);
        N = n;
    }
    void update(ll i, ll val, ll idx = 0, ll low = 0, ll high = N - 1){
        if(low == high and low == i){
            st[idx] += val;
            if(val > 0){
                cnt[idx]++;
            }
            else{
                cnt[idx]--;
            }
            return;
        }
        ll mid = (low + high) >> 1;
        if(mid >= i){
            update(i, val, 2*idx+1, low, mid);
        }
        else{
            update(i, val, 2*idx+2, mid+1, high);
        }
        st[idx] = st[2*idx+1] + st[2*idx+2];
        cnt[idx] = cnt[2*idx+1] + cnt[2*idx+2];
    }
    ll query1(ll l, ll r, ll idx = 0, ll low = 0, ll high = N - 1){
        if(low>=l and r>=high){
            return st[idx];
        }
        if(l>high || low>r){
            return 0;
        }
        ll mid = (low + high) >> 1;
        return (query1(l, r, 2*idx+1,low,mid) + query1(l, r, 2*idx+2, mid+1, high));
    }
    ll query2(ll l, ll r, ll idx = 0, ll low = 0, ll high = N - 1){
        if(low>=l and r>=high){
            return cnt[idx];
        }
        if(l>high || low>r){
            return 0;
        }
        ll mid = (low + high) >> 1;
        return (query2(l, r, 2*idx+1,low,mid) + query2(l, r, 2*idx+2, mid+1, high));
    }
};
ll STLazy::N;

void solve()
{
    ll n, k; cin >> n >> k;
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;
    auto calc = [&](ll val){
        ll curr = 0;
        while(val > 0){
            curr++;
            val /= 10;
        }
        return curr;
    };
    set<ll> stt(all(arr));
    unordered_map<ll,ll> mp;
    ll id = 0;
    for(auto it : stt){
        mp[it] = id++;
    }
    STLazy st(id);
    for(ll i = 0; i < n; i++){
        st.update(mp[arr[i]], i + 1);
    }
    
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        st.update(mp[arr[i]], -i - 1);
        if(calc(arr[i]) > k) continue;
        {
            ll lim = 0;
            ll low = 0;
            ll high = INF;
            while(low <= high){
                ll mid = (low + high) >> 1;
                if(calc(arr[i] + mid) <= k){
                    lim = mid;
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            auto it = stt.upper_bound(lim);
            if(it == stt.begin()){
                continue;
            }
            it--;
            ll prev = ans;
            ans += ((i + 1) * (((n+1) * st.query2(0, mp[*it])) - st.query1(0, mp[*it])));
        }
        if(calc(arr[i]) < k){
            ll lim = INF;
            ll low = 0;
            ll high = INF;
            while(low <= high){
                ll mid = (low + high) >> 1;
                if(calc(arr[i] + mid) < k){
                    lim = mid;
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
            auto it = stt.lower_bound(lim);
            if(*it != lim){ 
                if(it == stt.begin()){
                    continue;
                }
                it--;
            }
            ans -= ((i + 1) * (((n+1) * st.query2(0, mp[*it])) - st.query1(0, mp[*it])));
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