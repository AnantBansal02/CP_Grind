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

ll power(ll x, ll y, ll p){
    ll res = 1;x = x % p;while (y > 0){if (y & 1)res = (res * x) % p;y = y >> 1;x = (x * x) % p;}return res;
}
ll modInverse(ll n, ll p){
    return power(n, p - 2, p);
}
vector<ll> fac;
void factorial(int n, int MOD){
    fac.resize(n + 1);fac[0] = 1;for (int i = 1; i < n; i++){fac[i] = fac[i - 1] * i % MOD;}
}
ll ncrmod(ll n, ll r, ll p){
    if (n < r)return 0;
    if (r == 0)return 1;
    return (((fac[n] * modInverse(fac[r], p)) % p) * modInverse(fac[n - r], p)) % p;
}
vector<ll> primes;
void seive(ll n){
    bool prime[n + 1];memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {for (int i = p * p; i <= n; i += p)prime[i] = false;}
    }
    for (int p = 2; p <= n; p++)if(prime[p])primes.push_back(p);
}
ll getNoOfFactors(ll num) {
    if( num < 2 ) { return 0;}ll cnt = 0;
    for ( auto x : primes ) {while( num % x == 0 ) {cnt++;num /= x ;}}
    if( num > 1){cnt++;}
    return cnt;
}
vector<long long> p_pow;
const ll p = 31;
const ll m = 1e9 + 9;
ll func(string const& s) {
    ll n = s.size();
    map<ll, vector<ll>> mp;
    mp[0].pb(0);
    for (ll i = 0; i < n; i++){
        if(s[i] != '?'){
            for(auto it : mp[i]){
                mp[i+1].pb((it + (s[i] - 'a' + 1) * p_pow[i]) % m);
            }
        }
        else{
            for(auto it : mp[i]){
                for(ll c=0;c<26;c++){
                    mp[i+1].pb((it + (c + 1) * p_pow[i]) % m);
                }
            }
        }
    }
    ll ans = 0;
    for (ll l = 1; l <= n/2; l++) {
        for (ll i = 0; i <= n - l; i++) {
            map<ll, ll> hs;
            for(auto it : mp[i+l]){
                for(auto at : mp[i]){
                    ll num = (it + m - at) % m;
                    num = (num * p_pow[n-i-1]) % m;
                    hs[num]++;
                }
            }
            for(auto it : mp[i+2*l]){
                for(auto at : mp[i+l]){
                    ll num = (it + m - at) % m;
                    num = (num * p_pow[l]) % m;
                    if(hs.count(num)){
                        ans = 2*l;
                    }
                }
            }
            
        }
    }
    return ans;
}
class STLazy{
    vector<ll> st,lazy;
    public:
    STLazy(ll n){
        st.resize(4*n+1);
        lazy.resize(4*n+1);
    }
    public:
    void build(ll idx, ll low, ll high, vector<ll>& arr){
        if(low==high){
            st[idx] = arr[low];
            return;
        }
        ll mid = (low + high) >> 1;
        build(2*idx+1, low, mid, arr);
        build(2*idx+2, mid+1, high, arr);
        st[idx] = st[2*idx+1] + st[2*idx+2];
    }
    public:
    void update(ll idx, ll low, ll high, ll l, ll r, ll val){
        // update the previous while traversing
        if(lazy[idx] != 0){
            st[idx] += (high - low + 1)*lazy[idx];  
            // propogate the lazy update downwards
            if(low != high){
                lazy[2*idx+1] += lazy[idx];
                lazy[2*idx+2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        // no overlap
        // low high l r || l r low high
        if(l>high || low>r){
            return;
        }
        // complete overlap
        // l low high r
        if(low>=l and r>=high){
            st[idx] += (high - low + 1)*val;
            if(low!=high){
                lazy[2*idx+1] = val;
                lazy[2*idx+2] = val;
            }
            return;
        }
        ll mid = (low + high) >> 1;
        update(2*idx+1, low, mid, l, r, val);
        update(2*idx+2, mid+1, high, l, r, val);
        st[idx] = st[2*idx+1] + st[2*idx+2];
    }
    public:
    ll query(ll idx, ll low, ll high, ll l, ll r){
        // if updates remaining!!! lazy!!
        if(lazy[idx] != 0){
            st[idx] += (high - low + 1)*lazy[idx];  
            // propogate the lazy update downwards
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
        return (query(2*idx+1,low,mid,l,r) + query(2*idx+2, mid+1, high, l, r));
    }
};
void solve()
{
    string s;cin>>s;
    ll n = s.size();
    if(s.size() == 1){
        cout<<"0"<<"\n";
        return;
    }
    vector<vector<ll>> arr(n/2 + 1);
    for(ll l=1;l<=n/2;l++){
        for(ll i=0;i<n-l;i++){
            if(s[i] == s[i+l] || s[i] == '?' || s[i+l] == '?'){
                arr[l].pb(1);
            }
            else{
                arr[l].pb(0);
            }
        }
    }
    ll ans = 0;
    for(ll l=1;l<=n/2;l++){
        ll x = arr[l].size();
        // STLazy st(x);
        // st.build(0, 0, x-1, arr[l]);
        for(ll i=1;i<x;i++){
            arr[l][i] += arr[l][i-1]; 
        }
        if(arr[l][l-1] == l){
            ans = 2*l;
        }
        for(ll i=l;i<x;i++){
            if(arr[l][i] - arr[l][i-l] == l){
                ans = 2*l;
            }
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    p_pow.resize(5005);
    p_pow[0] = 1;
    for (ll i = 1; i < 5005; i++){
        p_pow[i] = (p_pow[i-1] * p) % m;
    }
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}