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
ll dp1[1001];
ll f1(ll idx, vector<pair<ll,ll>>& arr){
    if(idx >= arr.size()){
        return 0;
    }
    if(dp1[idx] != -1){
        return dp1[idx];
    }
    ll ans = INT_MIN;
    ll mini = INT_MAX;
    ll add = 0;
    for(ll i=idx;i<arr.size();i++){
        if(arr[i].first < mini){
            mini = arr[i].first;
            add = arr[i].second;
        }
        ans = max(ans, add + f1(i+1, arr));
    }
    return dp1[idx] = ans;
}
ll dp2[1001];
ll f2(ll idx, vector<pair<ll,ll>>& arr){
    if(idx >= arr.size()){
        return 0;
    }
    if(dp2[idx] != -1){
        return dp2[idx];
    }
    ll ans = INT_MIN;
    ll maxi = INT_MIN;
    ll add = 0;
    for(ll i=idx;i<arr.size();i++){
        if(arr[i].first > maxi){
            maxi = arr[i].first;
            add = arr[i].second;
        }
        ans = max(ans, add + f2(i+1, arr));
    }
    return dp2[idx] = ans;
}
void solve()
{
    ll n;cin>>n;
    vector<pair<ll,ll>> arr(n);
    for(ll i=0;i<n;i++){
        ll x;cin>>x;
        arr[i].first = x;
        char y;cin>>y;
        ll z;cin>>z;
        arr[i].second = z;
    }
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));
    cout<<max(f1(0, arr), f2(0, arr))<<"\n";
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