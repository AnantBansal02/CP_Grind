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

vector<ll> primes;
vector<ll> spf;
void sieve(ll MAXN)
{
    bool prime[MAXN + 1];memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= MAXN; p++) {
        if (prime[p] == true) {for (int i = p * p; i <= MAXN; i += p)prime[i] = false;}
    }
    for (int p = 2; p <= MAXN; p++)if(prime[p])primes.push_back(p);
    // spf.resize(MAXN);
    // spf[1] = 1;
    // for (ll i = 2; i < MAXN; i++)spf[i] = i;
    // for (ll i = 4; i < MAXN; i += 2)spf[i] = 2;
 
    // for (ll i = 3; i * i < MAXN; i++) {
    //     if (spf[i] == i) {
    //         for (ll j = i * i; j < MAXN; j += i)if (spf[j] == j)spf[j] = i;
    //     }
    // }
}
vector<ll> getFactorization(ll x)
{
    // vector<ll> ret;
    // while (x != 1) {
    //     ret.push_back(spf[x]);
    //     x = x / spf[x];
    // }
    // return ret;
}
ll getNoOfFactors(ll num) {
    return getFactorization(num).size();
}

class string_hash{
    public:
    vector<ll> h, p_pow;
    ll m = 1e9 + 7;
    ll p, n;
    string_hash(string s){
        n = s.size();
        h.resize(n+1, 0);
        p_pow.resize(n);
        std::srand(std::time(0));
        p = primes[(rand() % (9000 - 50 + 1)) + 100];
        p_pow[0] = 1;
        for (int i = 1; i < n; i++){
            p_pow[i] = (p_pow[i-1] * p) % m;
        }
        for (int i = 0; i < n; i++){
            h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
        }
    }

    ll hash_value(ll i, ll j){
        if(i >= 0 and j >= 0 and i < n and j < n and i <= j){
            ll val = (h[j+1] - h[i] + m) % m;
            (val *= p_pow[n - i - 1]) %= m;
            return val;
        }
        return -1;
    }
    ll fun(ll r, ll i){
        (r *= p_pow[i + 1]) %= m;
        return r;
    }
};

void solve()
{
    string s; cin >> s;
    ll n = s.size();
    if(n & 1){ cout << "0" << "\n"; return; }
    string_hash sh(s);
    ll m = sh.m;
    ll ans = 0;
    ll val1 = sh.hash_value(0, n/2-1);
    ll val2 = sh.hash_value(n/2, n-1);
    if(val1 == val2){
        ans++;
    }
    ll i = 0;
    ll j = n/2;
    for(ll cnt = 0; cnt < n/2; cnt++){
        ll p = sh.hash_value(0, i);
        ll q = sh.hash_value(i+1, j);
        if(j == n - 1){
            if(p == q) ans++;
            continue;
        }
        ll r = sh.hash_value(j+1, n-1);
        r = sh.fun(r, i);
        if((p + r)%m == q) ans++;
        i++;j++;
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    sieve(1e5);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}