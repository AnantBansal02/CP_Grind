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
int dp[501][501];
int solve(int idx, vector<int>& arr, int x, int count){
    if(idx >= arr.size()){
        return 0;
    }
    if(dp[idx][count] != -1){
        return dp[idx][count];
    }
    int ans = INT_MAX;
    if(arr.size() - idx > count){
        ans = min(ans, arr[idx+1] - arr[idx] + solve(idx+2, arr, x, count));
        ans = min(ans, x + solve(idx+1, arr, x, count+1));
    }
    else{
        return 0;
    }
    return dp[idx][count] = ans;
}
int minOperations() {
    string s1,s2;cin>>s1>>s2;
    int x;cin>>x;
    vector<int> idx; 
    int n = s1.size();
    for(int i=0;i<n;i++){
        if(s1[i] != s2[i]){
            idx.push_back(i);
        }
    }
    if(idx.size()%2 == 1){
        return -1;
    }
    memset(dp,-1,sizeof(dp));
    return solve(0, idx, x, 0);
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
        cout<<minOperations()<<"\n";
    }
    return 0;
}