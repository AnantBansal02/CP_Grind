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

void solve()
{
    ll n, k; cin >> n >> k;
    string s; cin >> s;
    sort(all(s));
    ll ans = 0;
    do{
        bool flag = 1;
        for(ll i = 0; i <= n - k; i++){
            ll f = 1;
            for(ll j = i; j < i + k; j++){
                if(s[j] != s[i + k - (j - i) - 1]){
                    f = 0;
                    break;
                }
            }
            if(f){
                flag = 0;
                break;
            }
        }
        if(flag){
            ans++;
        }
    }   
    while(next_permutation(all(s)));

    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // sieve(1e5);
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}