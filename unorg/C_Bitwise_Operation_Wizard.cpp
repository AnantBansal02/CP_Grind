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
void solve()
{
    ll n;cin>>n;
    ll maxi = -1;
    ll cand1 = 0;
    ll cand2 = 1;
    for(ll i=2;i<=n;i++){
        cout<<"? "<<cand1<<" "<<cand1<<" "<<cand2<<" "<<cand2<<endl;
        char ch;cin>>ch;
        if(ch == '>'){
            maxi = cand1;
            cand2 = i;
        }
        else{
            maxi = cand2;
            cand1 = i;
        }
    }
    vector<ll> indices;
    ll idx = 0;
    for(ll i=0;i<n;i++){
        cout<<"? "<<maxi<<" "<<idx<<" "<<maxi<<" "<<i<<endl;
        char ch;cin>>ch;
        if(ch == '>'){
        }
        else if(ch == '='){
            indices.push_back(i);
        }
        else{
            indices.clear();
            indices.push_back(i);
            idx = i;
        }
    }
    if(indices.size() > 1){
        ll mini = -1;
        cand1 = indices[0];
        cand2 = indices[1];
        for(ll i=2;i<=indices.size();i++){
            cout<<"? "<<cand1<<" "<<cand1<<" "<<cand2<<" "<<cand2<<endl;
            char ch;cin>>ch;
            if(ch == '<'){
                mini = cand1;
                cand2 = indices[i];
            }
            else{
                mini = cand2;
                cand1 = indices[i];
            }
        }
        cout<<"! "<<maxi<<" "<<mini<<endl;
    }
    else{
        cout<<"! "<<maxi<<" "<<indices[0]<<endl;
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