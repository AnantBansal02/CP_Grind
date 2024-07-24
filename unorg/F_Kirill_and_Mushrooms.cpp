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


// sorted_range_sum
class SRM{
    public:
    vector<ll> st, cnt;
    static ll N;
    SRM(ll n){
        st.resize(4*n + 1, 0);
        cnt.resize(4*n + 1, 0);
        N = n;
    }
    void update(ll id, ll val, ll idx = 0, ll low = 0, ll high = N - 1){
        if(low == high and low == id){
            st[idx] += val;
            if(val > 0){
                cnt[idx] += 1;
            }
            else{
                cnt[idx] -= 1;
            }
            return;
        }
        ll mid = (low + high) >> 1;
        if(mid >= id){
            update(id, val, 2*idx+1, low, mid);
        }
        else{
            update(id, val, 2*idx+2, mid+1, high);
        }
        st[idx] = st[2*idx+1] + st[2*idx+2];
        cnt[idx] = cnt[2*idx+1] + cnt[2*idx+2];
    }
    ll ask(ll r, ll idx = 0, ll low = 0, ll high = N - 1, ll l = 0){
        if(low>=l and r>=high){
            return  cnt[idx];
        }
        if(l>high || low>r){
            return 0;
        }
        ll mid = (low + high) >> 1;
        return (ask(r, 2*idx+1, low, mid, l) + ask(r, 2*idx+2, mid+1, high, l));
    }

    ll sum(ll r, ll idx = 0, ll low = 0, ll high = N - 1, ll l = 0){
        if(low>=l and r>=high){
            return  st[idx];
        }
        if(l>high || low>r){
            return 0;
        }
        ll mid = (low + high) >> 1;
        return (sum(r, 2*idx+1, low, mid, l) + sum(r, 2*idx+2, mid+1, high, l));
    }
    ll query(ll cap){
        ll low = 0;
        ll high = N-1;
        ll ans = -1;
        while(low <= high){
            ll mid = low + high >> 1;
            if(ask(mid) >= cap){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        assert(ans != -1);
        assert((ask(ans) - ask(ans-1)) != 0);
        ll val = (sum(ans) - sum(ans-1)) / (ask(ans) - ask(ans-1));
        return val;
    }
};
ll SRM::N;

void solve()
{
    ll n; cin >> n;
    vector<ll> arr(n), perm(n);
    for(auto &it : arr) cin >> it;
    for(auto &it : perm) cin >> it;   
    set<ll> st(all(arr));
    map<ll,ll> mp;
    ll id = 0;
    for(auto it : st){
        mp[it] = id++;
    }
    vector<pair<ll,ll>> A;
    for(ll i = 0; i < n; i++){
        A.pb({perm[i], arr[i]});
    }
    SRM srm(id);
    for(ll i = 0; i < n; i++){
        srm.update(mp[arr[i]], arr[i]);
    }
    pair<ll,ll> ans;
    ans.fi = 0;
    for(ll i = 0; n - 2*i >= 1; i++){
        ll curr = ((i + 1) * srm.query(n - 2*i));
        if(curr > ans.fi){
            ans.fi = curr;
            ans.se = i + 1;
        }
        ll idx = A[i].fi;
        srm.update(mp[A[idx-1].se], -A[idx-1].se);
    }
    cout << ans.fi << " " << ans.se << "\n";
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