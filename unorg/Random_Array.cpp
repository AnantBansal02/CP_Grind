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

void solve()
{
    ll n;cin>>n;
    vector<vector<ll>> arr(n), suff(n);
    vector<ll> main;
    for(ll i=0;i<n;i++){
        ll k;cin>>k;
        arr[i].resize(k);
        suff[i].resize(k);
        for(auto &it : arr[i]){
            cin>>it;
            main.emplace_back(it);
        }
    }
    for(ll i=0;i<n;i++){
        sort(all(arr[i]));
    }
    sort(all(main));
    for(ll i=0;i<n;i++){
        ll k = arr[i].size();
        suff[i][k-1] = arr[i][k-1];
        for(ll j=k-2;j>=0;j--){
            suff[i][j] = arr[i][j] + suff[i+1][j];
        }
    }
    ll N = main.size();
    vector<ll> suff2(N);
    suff2[N-1] = main[N-1];
    for(ll i=N-2;i>=0;i--){
        suff2[i] = suff2[i+1] + main[i];
    }
    ll sum = 0;
    for(ll i=0;i<n;i++){
        ll k = arr[i].size();
        for(ll j=0;j<k;j++){

        }
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