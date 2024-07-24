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
    ll n; cin >> n;
    string s, t; cin >> s >> t;
    ll f = 1;
    for(ll i = 0; i < n; i++){
        if(s[i] == '1'){
            f = 0;
        }
        if(s[i] == '0' and t[i] == '1'){
            if(f){
                cout << "NO" << "\n";
                return;
            }
        }
    }

    cout << "YES" << "\n";

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // sieve(1e5);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}