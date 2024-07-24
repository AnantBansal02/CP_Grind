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
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;

   
    ll idx = -1;
    ll mini = n - 1;
    for(ll i = 0; i < n; i++){
        ll curr = 0;
        ll num = arr[i];
        for(ll j = i + 1; j < n; j++){
            if(arr[j] != num + (j - i) * k){
                curr++;
            }
        }
        num = arr[i];
        for(ll j = i - 1; j >= 0; j--){
            if(arr[j] != num + (j - i) * k){
                curr++;
            }
        }
        if(curr < mini){
            mini = curr;
            idx = i;
        }
    }
    // dbg(idx);
    cout << mini << "\n";
    if(mini > 0){
        for(ll i = 0; i < n; i++){
            if(arr[i] > arr[idx] + (i - idx) * k){
                cout << "- " << i+1 << " " << arr[i] -  (arr[idx] + (i - idx) * k) << "\n";
            }
            if(arr[i] < arr[idx] + (i - idx) * k){
                cout << "+ " << i+1 << " " << (arr[idx] + (i - idx) * k) - arr[i] << "\n";
            }
        }
    }
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