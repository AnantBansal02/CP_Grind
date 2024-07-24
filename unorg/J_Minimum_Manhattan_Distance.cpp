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
double dist(double a, double b, double c, double d){
    return sqrtl((a - c)*(a - c) + (b - d)*(b - d));
}
void solve()
{
    vector<vector<double>> arr(2, vector<double>(4));
    for(ll i=0;i<2;i++){
        for(ll j=0;j<4;j++){
            cin>>arr[i][j];
        }
    }
    double ans = 1e9;
    double x1 = (arr[0][0] + arr[0][2])/2.0;
    double y1 = (arr[0][1] + arr[0][3])/2.0;
    double x2 = (arr[1][0] + arr[1][2])/2.0;
    double y2 = (arr[1][1] + arr[1][3])/2.0;
    double rad = dist(arr[1][0], arr[1][1], arr[1][2], arr[1][3])/2.0;
    double m = (y1 - y2) / (x1 - x2);
    double cons = y2 - m*x2;
    double temp = sqrtl(rad*rad/(m*m + 1));
    cout<<rad<<" "<<m<<" "<<temp<<"\n";
    double x_ = x2 + temp;
    double y_ = m*x_ + cons;
    double x__ = x2 - temp;
    double y__ = m*x__ + cons;
    ans = min(ans, abs(x1 - x_) + abs(y1 - y_));
    ans = min(ans, abs(x1 - x__) + abs(y1 - y__));
    cout<<fixed<<setprecision(10)<<ans<<"\n";
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