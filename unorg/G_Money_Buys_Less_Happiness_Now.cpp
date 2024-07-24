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
        st.resize(4*n+1, 0);
        lazy.resize(4*n+1, -1);
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
        if(lazy[idx] != -1){
            st[idx] = (high - low + 1)*lazy[idx];  
            if(low != high){
                lazy[2*idx+1] = lazy[idx];
                lazy[2*idx+2] = lazy[idx];
            }
            lazy[idx] = -1;
        }
        if(l>high || low>r){
            return;
        }
        if(low>=l and r>=high){
            st[idx] = (high - low + 1)*val;
            if(low!=high){
                lazy[2*idx+1] = val;
                lazy[2*idx+2] = val;
            }
            return;
        }
        ll mid = (low + high) >> 1;
        update(l, r, val, 2*idx+1, low, mid);
        update(l, r, val, 2*idx+2, mid+1, high);
        st[idx] = st[2*idx+1] + st[2*idx+2];
    }
    ll query(ll l, ll r, ll idx = 0, ll low = 0, ll high = N - 1){
        if(lazy[idx] != -1){
            st[idx] = (high - low + 1)*lazy[idx];  
            if(low != high){
                lazy[2*idx+1] = lazy[idx];
                lazy[2*idx+2] = lazy[idx];
            }
            lazy[idx] = -1;
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
    ll m,x;cin>>m>>x;
    vector<ll> arr(m), temp(m);
    for(auto &it : arr){
        cin>>it;
    }
    STLazy st(m);
    st.update(0, m-1, x);
    iota(all(temp), 0);
    sort(all(temp), [&] (ll& a, ll& b) -> bool {
        return arr[a] < arr[b];
    });
    ll ans = 0;
    for(ll i=0;i<m;i++){
        ll cost = arr[temp[i]];
        ll low = 0;
        ll high = temp[i] - 1;
        ll idx = - 1;
        while(low <= high){
            ll mid = (low + high) >> 1;
            if(st.query(mid, temp[i] - 1) >= cost){
                idx = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }  
        if(idx != -1){
            // cout<<idx<<" "<<temp[i]<<"\n";
            ll val = 0;
            if(idx+1 <= temp[i] - 1){
                val += st.query(idx+1, temp[i] - 1);
                st.update(idx+1, temp[i] - 1, 0);
            }
            // cout<<temp[i]<<" "<<idx<<" "<<val<<"\n";
            ll initial = st.query(idx, idx);
            st.update(idx, idx, initial - (cost - val));
            // for(ll j=0;j<m;j++){
            //     cout<<st.query(j , j)<<" ";
            // }
            // cout<<"\n";
            ans++;
        } 
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