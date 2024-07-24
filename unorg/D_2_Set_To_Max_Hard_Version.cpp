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
vector<ll> NGE(vector<ll> arr)
{
    stack<ll> s;
    ll n = arr.size();
    vector<ll> ans(n, -1);
    s.push(0);
    for (ll i = 1; i < n; i++) {
 
        if (s.empty()) {
            s.push(arr[i]);
            continue;
        }
        while (s.empty() == false && arr[s.top()] < arr[i]) {
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return ans;
}
vector<ll> NGEr(vector<ll> arr)
{
    stack<ll> s;
    ll n = arr.size();
    vector<ll> ans(n, -1);
    s.push(n-1);
    for (ll i = n-2; i >= 0; i--) {
 
        if (s.empty()) {
            s.push(arr[i]);
            continue;
        }
        while (s.empty() == false && arr[s.top()] < arr[i]) {
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return ans;
}
vector<ll> NSE(vector<ll> arr)
{
    stack<ll> s;
    ll n = arr.size();
    vector<ll> ans(n, -1);
    s.push(0);
    for (ll i = 1; i < n; i++) {
 
        if (s.empty()) {
            s.push(arr[i]);
            continue;
        }
        while (s.empty() == false && arr[s.top()] > arr[i]) {
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return ans;
}
vector<ll> NSEr(vector<ll> arr)
{
    stack<ll> s;
    ll n = arr.size();
    vector<ll> ans(n, -1);
    s.push(n-1);
    for (ll i = n-2; i >= 0; i--) {
 
        if (s.empty()) {
            s.push(arr[i]);
            continue;
        }
        while (s.empty() == false && arr[s.top()] > arr[i]) {
            ans[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    return ans;
}
void solve()
{
    ll n;cin>>n;
    vector<ll> arr(n);
    vector<ll> b(n);
    vector<pair<ll,ll>> brr(n);
    map<ll, vector<ll>> mp;
    for(auto &it : arr){
        cin>>it;
    }
    for(ll i=0;i<n;i++){
        mp[arr[i]].push_back(i);
    }
    for(ll i=0;i<n;i++){
        cin>>b[i];
        brr[i].first = b[i];
        brr[i].second = i;
    }
    sort(all(brr));
    for(auto &it : mp){
        sort(all(it.second));
    }
    vector<ll> nger = NGE(arr);
    vector<ll> ngel = NGEr(arr);
    vector<ll> nser = NSE(b);
    vector<ll> nsel = NSEr(b);
    for(ll i=0;i<n;i++){
        ll el = brr[i].first;
        ll idx = brr[i].second;
        ll l = idx;
        ll r = idx;
        if(arr[idx] == b[idx]){
            continue;
        }
        bool flag1 = true;
        bool flag2 = true;
        l = lower_bound(mp[el].begin(), mp[el].end(), idx) - mp[el].begin();
        l--;
        if(l < 0){
            flag1 = false;
        }
        else{
            l = mp[el][l];
            if(nger[l] <= idx and nger[l] != -1){
                flag1 = false;
            }
            if(nsel[idx] > l ){
                flag1 = false;
            }
        }
        r = upper_bound(mp[el].begin(), mp[el].end(), idx) - mp[el].begin();
        if(r >= mp[el].size()){
            flag2 = false;
        }
        else{
            r = mp[el][r];
            if(ngel[r] >= idx){
                flag2 = false;
            }
            if(nser[idx] < r and nser[idx] != -1){
                flag2 = false;
            }
        }
        if(!flag1 and !flag2){
            cout<<"NO"<<"\n";
            return;
        }
    }
    cout<<"YES"<<"\n";
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