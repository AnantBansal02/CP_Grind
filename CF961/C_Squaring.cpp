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
    ll ans = 0;
    ll n; cin >> n;
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;
    pair<ll,ll> maxi;
    maxi.fi = 1, maxi.se = 0;
    for(ll i = 0; i < n; i++){
        if(maxi.se == 0){
            if(arr[i] >= maxi.fi){
                maxi.fi = arr[i];
            }
            else{
                if(arr[i] == 1){
                    cout << "-1\n";
                    return;
                }
                ll cnt = 0;
                ll num = arr[i];
                while(num < maxi.fi){
                    num *= num;
                    cnt++;
                    ans++;
                }
                maxi.fi = arr[i];
                maxi.se = cnt;
            }
        }
        else{
            if(arr[i] == 1){
                cout << "-1" << "\n";
                return;
            }
            if(arr[i] > maxi.fi){
                ll num = maxi.fi;
                ll cnt = 0;
                while(num < arr[i]){
                    num *= num;
                    cnt++;
                }
                ll curr = maxi.se - cnt;
                if(num != arr[i]){
                    curr++;
                }
                ans += max(0LL, curr);
                maxi.fi = arr[i];
                maxi.se = max(0LL, curr);
            }
            else if(arr[i] < maxi.fi){
                ll num = arr[i];
                ll cnt = 0;
                while(num < maxi.fi){
                    num *= num;
                    cnt++;
                }
                maxi.fi = arr[i];
                maxi.se += cnt;
                ans += maxi.se;
            }
            else{
                ans += maxi.se;
            }
        }
        // dbg(maxi.fi);
        // dbg(maxi.se);
        // dbg(ans);
    }

    cout << ans << "\n";
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