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
std::string f(std::string &str, long long k) {
    int n = str.size();
    std::string ans;

    for (int i = 0; i < n; i++) {
        while (!ans.empty() && k > 0 && ans.back() > str[i]) {
            k--;ans.pop_back();
        }
        ans.push_back(str[i]);
    }

    if (k > 0) {
        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            --k;
        }
    }
    return ans;
}
void solve()
{
    string s;cin>>s;
    ll x;cin>>x;
    ll iter = 0;
    ll start = s.size();
    while(x > start){
        iter++;
        x -= start;
        start--;
    }
    // vector<ll> arr;
    // for(ll i=1;i<s.size();i++){
    //     if(s[i] < s[i-1]){
    //         arr.push_back(i);
    //     }
    // }
    // if(arr.size() == 0){
    //     cout<<s[x-1];
    //     return;
    // }
    // vector<pair<ll,ll>> temp;
    // if(iter >= arr[0]){
    //     temp.pb({0,arr[0]});
    //     iter -= arr[0];
    // }
    // else{
    //     s.erase(arr[0] - iter, iter);
    // }
    // for(ll i=1;i<arr.size();i++){
    //     if(iter >= arr[i] - arr[i-1]){
    //         temp.pb({arr[i-1], arr[i] - arr[i-1]});
    //         iter = iter - (arr[i] - arr[i-1]);
    //     }
    //     else{
    //         temp.pb({arr[i] - iter, iter});
    //         break;
    //     }
    // }
    // cout<<s[x-1];
    int n = s.size();
    std::vector<int> temp(n);
    x -= 1;
    if (iter == 0) {
        std::cout << s[x];
        return;
    }
    std::string a = f(s, iter);
    std::cout << a[x];
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