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
ll n,m,k;
void solve()
{  
    cin>>n>>m>>k;
    vector<ll> a(n), d(m), f(k);
    for(auto &it : a)cin>>it;
    for(auto &it : d)cin>>it;
    for(auto &it : f)cin>>it;
    sort(all(f));
    sort(all(d));
    vector<ll> temp;
    for(ll i=1;i<n;i++){
        temp.pb(a[i] - a[i-1]);
    }
    sort(all(temp));
    ll sz = temp.size();
    if(sz > 1 and temp[sz - 2] == temp[sz - 1]){
        cout<<temp[sz - 1]<<"\n";
        return;
    }
    ll l,r;
    for(ll i=1;i<n;i++){
        if(a[i] - a[i-1] == temp[sz - 1]){
            r = a[i];
            l = a[i-1];
            break;  
        }
    }
    ll ans = INT_MAX;
    for(ll i=0;i<m;i++){
        ll low = 0;
        ll high = k - 1;
        ll tar = (r + l)/2 - d[i];
        ll lb = -1;
        while(low <= high){
            ll mid = (low + high) >> 1;
            if(f[mid] <= tar){
                lb = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        if(lb != -1){
            if(f[lb] + d[i] >= l and f[lb] + d[i] <= r){
                ll maxi = max(f[lb] + d[i] - l, r - f[lb] - d[i]);
                ans = min(ans, maxi);
            }
        }
        low = 0;
        high = k - 1;
        ll ub = -1;
        while(low <= high){
            ll mid = (low + high) >> 1;
            if(f[mid] >= tar){
                ub = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        if(ub != -1){
            if(f[ub] + d[i] >= l and f[ub] + d[i] <= r){
                ll maxi = max(f[ub] + d[i] - l, r - f[ub] - d[i]);
                ans = min(ans, maxi);
            }
        }
    }
    if(ans == INT_MAX){
        ans = temp[sz - 1]; 
    }
    if(sz > 1)
        cout<<max(ans, temp[sz - 2])<<"\n";
    else{
        cout<<ans<<"\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // seive(1e5);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}