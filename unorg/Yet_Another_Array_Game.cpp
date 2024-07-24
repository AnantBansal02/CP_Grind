#pragma GCC optimize("-Ofast")
#pragma GCC tarrget("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
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
#define set_bits(x) __builtin_popcntll(x)

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
ll s;
void solve()
{
    ll n;cin>>n;
    vector<ll> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    sort(all(arr));
    vector<ll> pre(n, 0);
    pre[0] = arr[0];
    for(ll i=1;i<n;i++){
        pre[i] = pre[i-1]+arr[i];
    }
    ll ans = 0;
    if(n%2==0){
        ll i=1;
        ll cnt = n/2;
        while(i<n){
            ans = max(ans,pre[i+cnt-1]-pre[i-1]);
            i+=2;cnt--;
            if(s == 0){
                break;
            }
        }
    }else{
        ll i=0;
        ll cnt = n/2+1;
        while(i<n){
            if(i>0)
            ans = max(ans,pre[i+cnt-1]-pre[i-1]);
            else ans = pre[i+cnt-1];
            i+=2;cnt--;
            if(s == 0){
                break;
            }
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // seive(1e5);
    ll t = 1;
    cin >> t >> s;
    while(t--){
        solve();
    }
    return 0;
}