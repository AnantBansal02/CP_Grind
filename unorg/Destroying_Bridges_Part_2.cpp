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

void solve()
{
    ll n, c; cin >> n >> c;
    vector<ll> arr(n);
    for(auto &it : arr) cin >> it;
    if(n == 1){
        cout << 1 << "\n";
        return;
    }
    sort(arr.begin() + 1, arr.end());
    ll S = accumulate(all(arr), 0LL);
    if(arr[0] * (S - arr[0]) <= c){
        cout << 1 << "\n";
        return;
    }
    set<ll> st;
    ll cost = 0;
    for(ll relax = 0; relax < n; relax++){
        ll mini = INF;
        ll idx = -1;
        for(ll i=1;i<n;i++){
            if(st.find(i) != st.end()) continue;
            ll sum = 0;
            for(ll j=0;j<n;j++){
                if(i == j) continue;
                if(st.find(j) != st.end()) sum -= arr[i] * arr[j];
                else sum += arr[i] * arr[j];
            }
            if(sum < mini){
                mini = sum;
                idx = i;
            }
        }
        if(mini + cost > c) break;

        cost += mini;
        st.insert(idx);
    }
    cout << n - st.size() << "\n";
   
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