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
    if( num < 2 ) { return 0;}ll ans = 0;
    for ( auto x : primes ) {while( num % x == 0 ) {ans++;num /= x ;}}
    if( num > 1){ans++;}
    return ans;
}
std::vector<ll> calculateFactors(ll a, ll b) {
    ll divisor = b;
    std::vector<ll> result;

    while (divisor <= a) {
        result.push_back(a / divisor);
        if (divisor > (a + b - 1) / b) break;
        divisor *= b;
    }

    return result;
}

void solve() {
    ll left, right, divisor;
    std::cin >> left >> right >> divisor;

    std::vector<ll> factorsRight = calculateFactors(right, divisor);
    std::vector<ll> factorsLeft = calculateFactors(left - 1, divisor);

    for (ll i = 0; i < (int)factorsLeft.size(); i++) {
        factorsRight[i] -= factorsLeft[i];
    }

    ll size = factorsRight.size();
    for (ll i = 0; i < size - 1; i++) {
        factorsRight[i] -= factorsRight[i + 1];
    }

    ll xorResult = 0;
    for (ll i = 0; i < size; i++) {
        xorResult ^= ((factorsRight[i] & 1) * (i + 1LL));
    }

    if (xorResult) {
        std::cout << "First" << "\n";
    } else {
        std::cout << "Second" << "\n";
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