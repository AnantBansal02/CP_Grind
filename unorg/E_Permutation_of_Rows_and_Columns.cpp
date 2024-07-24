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
    ll n, m; cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m));
    vector<vector<ll>> b(n, vector<ll>(m));
    
    ll sz = n * m + 1;
    map<ll, pair<ll, ll>> mp; 
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>a[i][j];
        }
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>b[i][j];
            mp[b[i][j]] = {i, j};
        }
    }
    for(ll i=0;i<n;i++){
        ll row = mp[a[i][0]].first;
        for(ll j=0;j<m;j++){
            if(mp[a[i][j]].first != row){
                cout<<"NO"<<"\n";
                return;
            }
        }
    }
    for(ll j=0;j<m;j++){
        ll col = mp[a[0][j]].second;
        for(ll i=0;i<n;i++){
            if(mp[a[i][j]].second != col){
                cout<<"NO"<<"\n";
                return;
            }
        }
    }
    cout<<"YES"<<"\n";
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