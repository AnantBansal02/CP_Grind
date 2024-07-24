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


ll mod;
class STLazy{
    public:
    vector<ll> st,lazy;
    static ll N;
    STLazy(ll n){
        st.resize(4*n+1);
        lazy.resize(4*n+1, 1);
        N = n;
    }
    void build(vector<ll>& arr, ll idx = 0, ll low = 0, ll high = N - 1){
        if(low==high){
            st[idx] = arr[low] % mod;
            return;
        }
        ll mid = (low + high) >> 1;
        build(arr, 2*idx+1, low, mid);
        build(arr, 2*idx+2, mid+1, high);
        st[idx] = (st[2*idx+1] + st[2*idx+2]) % mod;
    }
    void update(ll l, ll r, ll val, ll idx = 0, ll low = 0, ll high = N - 1){
        if(lazy[idx] != 1){
            (st[idx] *= lazy[idx]) %= mod;
            if(low != high){
                (lazy[2*idx+1] *= lazy[idx]) %= mod;
                (lazy[2*idx+2] *= lazy[idx]) %= mod;;
            }
            lazy[idx] = 1;
        }
        if(l>high || low>r){
            return;
        }
        if(low>=l and r>=high){
            (st[idx] *= val) %= mod;
            if(low!=high){
                (lazy[2*idx+1] *= val) %= mod; // check these two next time you use them!
                (lazy[2*idx+2] *= val) %= mod;
            }
            return;
        }
        ll mid = (low + high) >> 1;
        update(l, r, val, 2*idx+1, low, mid);
        update(l, r, val, 2*idx+2, mid+1, high);
        st[idx] = (st[2*idx+1] + st[2*idx+2]) % mod;
    }
    ll query(ll l, ll r, ll idx = 0, ll low = 0, ll high = N - 1){
        if(lazy[idx] != 1){
            (st[idx] *= lazy[idx]) %= mod;  
            if(low != high){
                (lazy[2*idx+1] *= lazy[idx]) %= mod;
                (lazy[2*idx+2] *= lazy[idx]) %= mod;
            }
            lazy[idx] = 1;
        }
        if(low>=l and r>=high){
            return (st[idx]) % mod;
        }
        if(l>high || low>r){
            return 0;
        }
        ll mid = (low + high) >> 1;
        return (query(l, r, 2*idx+1,low,mid) + query(l, r, 2*idx+2, mid+1, high)) % mod;
    }
};
ll STLazy::N;

void solve()
{
    ll n, k, m; cin >> n >> k >> m;
    mod = m;
    vector<ll> arr(n);
    for(auto &it : arr){ cin >> it; it %= m;}
    vector<ll> A(n, 1);
    STLazy st(n);
    st.build(A);
    ll ans = 0;
    for(ll i=0;i<n;i++){
        ll l = max(0LL, i - k + 1);
        ll r = i;
        st.update(l, r, arr[i]);
        ans = (ans + st.query(l, r) % m) % m;

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