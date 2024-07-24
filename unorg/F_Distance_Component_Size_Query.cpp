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
    ll q, k; 
    cin >> q >> k;
    vector<array<ll, 2>> arr(q);
    map<ll,ll> mp;
    for(auto &it : arr){
        cin>>it[0]>>it[1];
        mp[it[1]]++;
    }
    ll id = 0;
    for(auto &it : mp){
        it.second = id++;
    }
    STLazy tree(id);
    set<ll> st, rep;
    st.insert(-k-100);
    for(auto it : arr){
        if(it[0] == 1){
            if(st.find(it[1]) == st.end()){
                auto iter = st.lower_bound(it[1]);
                if(iter != st.end()){
                    if(*iter - it[1] <= k){
                        rep.erase(*iter);
                    }
                }
                iter--;
                if(it[1] - *iter > k){
                    rep.insert(it[1]);
                }
                st.insert(it[1]);
                tree.update(mp[it[1]], mp[it[1]], 1);
            }
            else{
                st.erase(it[1]);
                rep.erase(it[1]);
                tree.update(mp[it[1]], mp[it[1]], -1);
                auto iter = st.lower_bound(it[1]);
                if(iter == st.end()){
                    continue;
                }
                ll right = *iter;
                iter--;
                if(right - *iter > k){
                    rep.insert(right);
                }
            }
        }
        else{
            ll left, right;
            auto iter1 = rep.lower_bound(it[1]);
            if(rep.find(it[1]) != rep.end()){
                left = mp[*iter1];
            }
            else{
                iter1--;
                left = mp[*iter1];
            }
            auto iter2 = rep.lower_bound(it[1]+1);
            if(iter2 == rep.end()){
                right = id-1;
            }
            else{
                right = mp[*iter2] - 1;
            }
            cout<<tree.query(left, right)<<"\n";
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