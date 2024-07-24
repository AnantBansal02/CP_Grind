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
void sieve(ll MAXN)
{
    bool prime[MAXN + 1];memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= MAXN; p++) {
        if (prime[p] == true) {for (int i = p * p; i <= MAXN; i += p)prime[i] = false;}
    }
    for (int p = 2; p <= MAXN; p++)if(prime[p])primes.push_back(p);
}

class string_hash{
    vector<ll> h, p_pow;
    ll m = 1e9 + 7;
    ll p, n;
    public:
    string_hash(string& s){
        n = s.size();
        h.resize(n+1, 0);
        p_pow.resize(n);
        std::srand(std::time(0));
        p = primes[(rand() % (9000 - 50 + 1)) + 50];
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
};

void solve()
{
    string s; cin >> s;
    ll n = s.size();
    string_hash sh(s);
    vector<ll> idx;
    for(ll i=0;i<n;i++){
        if(s[i] != 'a'){
            idx.pb(i);
        }
    }
    if(idx.size() == 0){
        cout << n - 1 << "\n";
        return;
    }
    ll ans = 0;
    for(ll len = 1; len <= n; len++){
        if(idx[0] + len - 1 >= n){
            break;
        }
        ll val = sh.hash_value(idx[0], idx[0] + len - 1);
        ll last = idx[0] + len;
        ll flag = 1;
        ll mini = idx[0];
        ll sz = idx.size();
        while(1){
            ll low = 0;
            ll high = sz - 1;
            ll next = -1;
            while(low <= high){
                ll mid = low + high >> 1;
                if(idx[mid] >= last){
                    next = idx[mid];
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            if(next == -1){
                break;
            }
            if(sh.hash_value(next, next + len - 1) != val){
                flag = 0;
                break;
            }
            else{
                mini = min(mini, next - last);
            }
            last = next + len;
        }
        if(flag){
            ans += mini + 1;
        }
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