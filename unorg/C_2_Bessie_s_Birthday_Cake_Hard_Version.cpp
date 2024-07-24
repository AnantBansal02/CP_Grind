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
    ll N, X, Y;
    cin>>N>>X>>Y;
    vector<ll> arr(X);
    for(ll i=0;i<X;i++){
        cin>>arr[i];
    }
    sort(all(arr));
    ll ans = 0;
    ll cnt = 0, extra = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for(ll i=0;i<X-1;i++){
        if(arr[i] + 2 == arr[i+1]){
            ans++;
        }
        else if((arr[i+1] - arr[i]) % 2 == 0){
            pq.push((arr[i+1] - arr[i])/2 - 1);
        }   
        else if(arr[i+1] - arr[i] > 1){
            cnt += (arr[i+1] - arr[i]) >> 1;
        }
    }
    if(arr[X - 1]+2 == arr[0]+N){
        ans++;
    }
    else if(abs(arr[X - 1]+2 - (arr[0]+N)) % 2 == 0){
        // cout<<abs(arr[X - 1]+2 - (arr[0]+N))<<"\n";
        pq.push((abs(arr[X - 1]+2 - (arr[0]+N)))/2);
    }
    else if(abs(arr[X - 1] - (arr[0]+N)) > 1){
        cnt += (abs(arr[X - 1] - (arr[0]+N)))/2;
    }
    // cout<<cnt<<"\n";
    // cout<<pq.top()<<"\n";
    while(Y > 0 and !pq.empty()){
        auto it = pq.top();
        pq.pop();
        if(it <= Y){
            ans += it + 1;
            extra += it;
            Y -= it;
        }
        else{
            ans += Y;
            extra += Y;
            Y = 0;
        }
    } 
    if(Y > 0){
        ans += min(Y, cnt);
        extra += min(Y, cnt);
    }
    X += extra;
    while(X > 2){
        ans += (X >> 1);
        if(X & 1){
            X++;
        }
        X = X >> 1;
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
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}