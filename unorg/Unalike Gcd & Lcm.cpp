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
vector<ll> spf;
void sieve(ll MAXN)
{   
    spf.resize(MAXN);
    spf[1] = 1;
    for (ll i = 2; i < MAXN; i++)
 
        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;
 
    // separately marking spf for every even
    // number as 2
    for (ll i = 4; i < MAXN; i += 2)
        spf[i] = 2;
 
    for (ll i = 3; i * i < MAXN; i++) {
        // checking if i is prime
        if (spf[i] == i) {
            // marking SPF for all numbers divisible by i
            for (ll j = i * i; j < MAXN; j += i)
 
                // marking spf[j] if it is not
                // previously marked
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}
map<ll,ll> get(ll num){
    map<ll,ll> mp;
    while(num != 1){
        mp[spf[num]]++;
        num /= spf[num];
    }
    return mp;
}
void solve()
{
    ll x,q;cin>>x>>q;
    map<ll,ll> main = get(x);
    for(auto it : main){
        cout<<it.first<<" "<<it.second<<"\n";
    }
    vector<ll> div;
    for(ll i=1;i*i<=x;i++){
        if(x%i == 0){
            div.push_back(i);
            if(i*i != x){
                div.push_back(x/i);
            }
        }
    }
    ll mod = 1e9 + 7;
    ll ans = 0;
    while(q--){
        ll p;cin>>p;
        for(auto it : div){
            map<ll,ll> temp;
            temp = get(it);
            
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    sieve(1e5+10);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}