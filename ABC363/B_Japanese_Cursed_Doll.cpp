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
    ll n, t, p;
    cin >> n >> t >> p;
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;
    priority_queue<ll> pq;
    for(auto it : arr){
        pq.push(it);
    }
    ll curr = 0;
    for(ll i = 0; i < p; i++){
        auto it = pq.top();pq.pop();
        if(it + curr >= t){
            continue;
        }
        else{
            curr += t - (it + curr);
        }
    }
    cout << curr << "\n";

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