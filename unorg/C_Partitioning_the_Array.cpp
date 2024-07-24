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
    vector<ll> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    ll ans = 0;
    for(ll i = 1; i*i <= n; i++){
        if(n % i == 0){
            vector<ll> temp;
            ll m1 = 0;
            for(ll j=i;j<n;j+=i){
                for(ll k=0;k<i;k++){
                    ll diff = abs(arr[j+k] - arr[j - i + k]);
                    m1 = __gcd(m1, diff);
                }
            }
            if(m1 != 1){
                ans++;
            }
            if(i*i != n){
                ll a = n / i;
                vector<ll> temp;
                ll m2 = 0;
                for(ll j=a;j<n;j+=a){
                    for(ll k=0;k<a;k++){
                        ll diff = abs(arr[j+k] - arr[j - a + k]);
                        m2 = __gcd(m2, diff);
                    }
                }
                if(m2 != 1){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}