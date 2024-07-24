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
    vector<ll> st,lazy;
    static ll N;
    STLazy(ll n){
        st.resize(4*n+1);
        lazy.resize(4*n+1);
        N = n;
    }
    void build(vector<ll>& arr, ll idx = 0, ll low = 0, ll high = N - 1){
        if(low==high){
            st[idx] = arr[low];
            return;
        }
        ll mid = (low + high) >> 1;
        build(arr, 2*idx+1, low, mid);
        build(arr, 2*idx+2, mid+1, high);
        st[idx] = st[2*idx+1] + st[2*idx+2];
    }
    void update(ll l, ll r, ll val, ll idx = 0, ll low = 0, ll high = N - 1){
        if(lazy[idx] != 0){
            st[idx] += (high - low + 1)*lazy[idx];  
            if(low != high){
                lazy[2*idx+1] += lazy[idx];
                lazy[2*idx+2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if(l>high || low>r){
            return;
        }
        if(low>=l and r>=high){
            st[idx] += (high - low + 1)*val;
            if(low!=high){
                lazy[2*idx+1] += val; // check these two next time you use them!
                lazy[2*idx+2] += val;
            }
            return;
        }
        ll mid = (low + high) >> 1;
        update(l, r, val, 2*idx+1, low, mid);
        update(l, r, val, 2*idx+2, mid+1, high);
        st[idx] = st[2*idx+1] + st[2*idx+2];
    }
    ll query(ll l, ll r, ll idx = 0, ll low = 0, ll high = N - 1){
        if(lazy[idx] != 0){
            st[idx] += (high - low + 1)*lazy[idx];  
            if(low != high){
                lazy[2*idx+1] += lazy[idx];
                lazy[2*idx+2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if(low>=l and r>=high){
            return st[idx];
        }
        if(l>high || low>r){
            return 0;
        }
        ll mid = (low + high) >> 1;
        return (query(l, r, 2*idx+1,low,mid) + query(l, r, 2*idx+2, mid+1, high));
    }
};
ll STLazy::N;

void solve()
{
    ll n, m; cin >> n >> m;
    vector<ll> arr(n + 1), end(n + 1, 0), f(n + 1, 0);
    for(ll i = 1; i <= n; i++) cin >> arr[i];
    vector<vector<ll>> ranges(m, vector<ll>(3));
    for(ll i = 0; i < m; i++){
        auto &it = ranges[i];
        cin >> it[0] >> it[1];
        it[2] = i;
        end[it[1]]++;
    }
    vector<vector<ll>> ind(n + 1);
    for(ll i = 1; i <= n; i++){
        ind[arr[i]].push_back(i);
    }
    sort(all(ranges));
    // offline queries
    {
        // maximum 2*n queries
        vector<vector<ll>> quer;
        for(ll i = 1; i <= n; i++){
            if(ind[i].size() > 0){
                ll sz = ind[i].size();
                if(ind[i][0] != 1){
                    quer.push_back({1, ind[i][0] - 1, i});
                }
                if(ind[i][sz - 1] != n){
                    quer.push_back({ind[i][sz - 1] + 1, n, i});
                }
                for(ll j = 1; j < sz; j++){
                    ll l = ind[i][j-1] + 1;
                    ll r = ind[i][j] - 1;
                    if(l > r) continue;
                    quer.push_back({l, r, i});
                }
            }
        }
        sort(all(quer));
        STLazy st(n + 1);
        st.build(end);
        ll sz = quer.size();
        ll idx = 0, id = 0;
        ll curr = m;
        for(ll i = 1; i <= n; i++){
            while(idx < sz and quer[idx][0] == i){
                ll l = i;
                ll r = quer[idx][1];
                ll num = quer[idx][2];
                ll val = st.query(l, r);
                f[num] += val;
                idx++;
            }
            while(id < m and ranges[id][0] == i){
                ll l = i;
                ll r = ranges[id][1];
                st.update(r, r, -1);
                id++;
            }
        }
    }
    {
        // Use Mo's Algorithm or segment tree!
        vector<ll> ans(m, 0);
        STLazy st(n + 1);
        for(ll i = 1; i <= n; i++){
            if(ind[i].size() > 0){
                st.update(ind[i][0], ind[i][0], f[i]);
            }
        }
        ll id = 0;
        for(ll i = 1; i <= n; i++){
            while(id < m and ranges[id][0] == i){
                ll l = i;
                ll r = ranges[id][1];
                ll idx = ranges[id][2];
                ans[idx] = st.query(l, r);
                id++;
            }
            ll sz = ind[arr[i]].size();
            auto it = lower_bound(all(ind[arr[i]]), i) - ind[arr[i]].begin();
            st.update(ind[arr[i]][it], ind[arr[i]][it], -f[arr[i]]);
            if(it != sz - 1){
                st.update(ind[arr[i]][it+1], ind[arr[i]][it+1], f[arr[i]]);
            }
        }
        for(auto it : ans){
            cout << it << " ";
        }
        cout << "\n";
    }
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