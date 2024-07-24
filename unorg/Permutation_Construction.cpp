#pragma GCC optimize("-Ofast")
#pragma GCC tansget("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
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
vector<ll> even(ll n, ll x){
    vector<ll> ans(n);
    ans[0] = x;
    if (x > n / 2) {
        int i = n / 2 - 1;
        int j = n / 2;
        int a = n;
        int b = 1;
        while (i >= 1) {
            if (a != ans[0]) {
                ans[i] = a;a--;
                ans[j] = b;b++;
                i--;j++;
            } else {
                ans[n - 1] = b;b++;a--;
                ans[i] = a;a--;
                ans[j] = b;b++;
                i--;j++;
            }
        }
        if (ans[n - 1] == 0)
            ans[n - 1] = b;
    } else {
        int i = n / 2 - 1;
        int j = n / 2;
        int a = 1;
        int b = n;
        while (i >= 1 && j < n - 1) {
            if (a != ans[0]) {
                ans[i] = a;a++;
                ans[j] = b;b--;
                i--;j++;
            } else {
                ans[n - 1] = b;b--;a++;
                ans[i] = a;a++;
                ans[j] = b;b--;
                i--;j++;
            }
        }
        if (ans[n - 1] == 0)
            ans[n - 1] = b;
    }
    return ans;
}
vector<ll> odd(ll n, ll x){
    vector<ll> ans(n);
    ans[0] = x;
    if (x > n / 2) {
        int i = n / 2 - 1;
        int j = n / 2 + 1;
        ans[n / 2] = n / 2 + 1;
        int a = n;
        if (i == 0)
            ans[j] = 1;
        int b = 1;
        while (i >= 1 && j < n - 1) {
            if (a != ans[0]) {
                ans[i] = a;a--;
                ans[j] = b;b++;
                i--;j++;
            } else {
                ans[n - 1] = b;b++;a--;
                ans[i] = a;a--;
                ans[j] = b;b++;
                i--;j++;
            }
        }
        if (ans[n - 1] == 0)
            ans[n - 1] = b;
    } else {
        int i = n / 2 - 1;
        int j = n / 2 + 1;
        ans[n / 2] = n / 2 + 1;
        int a = 1;
        int b = n;
        if (i == 0) {
            ans[j] = b;
        }
        while (i >= 1 && j < n - 1) {
            if (a != ans[0]) {
                ans[i] = a;a++;
                ans[j] = b;b--;
                i--;j++;
            } else {
                ans[n - 1] = b;b--;a++;
                ans[i] = a;a++;
                ans[j] = b;b--;
                i--;j++;
            }
        }
        if (ans[n - 1] == 0)ans[n - 1] = b;
    }
    return ans;
}
void solve()
{
    ll n,x;cin>>n>>x;
    if(n%2 == 1 and x == n/2 + 1){
        cout<<"-1"<<"\n";
        return;
    }
    vector<ll> ans;
    if (n % 2 == 0) {
        ans = even(n, x);
    } else {
        ans = odd(n, x);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
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