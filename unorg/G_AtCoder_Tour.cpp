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
    ll n, m, k; cin >> n >> m >> k;
    ll x, y; cin >> x >> y; x--, y--;
    vector<vector<ll>> arr(n, vector<ll>(m));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin >> arr[i][j];
        }
    } 
    vector<ll> di = {-1, 1, 0, 0, 0};
    vector<ll> dj = {0, 0, 1, -1, 0};
    ll ans = arr[x][y] * k;
    vector<vector<ll>> dp(n, vector<ll>(m, -INF));
    dp[x][y] = 0;

    for(ll moves=1;moves<=min(n*m, k);moves++){
        vector<vector<ll>> curr(n, vector<ll>(m, -INF));
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                for(ll d=0;d<5;d++){
                    ll prow = i + di[d];
                    ll pcol = j + dj[d];
                    if(prow < 0 || pcol < 0 || prow >= n || pcol >= m){
                        continue;
                    }
                    curr[i][j] = max(curr[i][j], arr[i][j] + dp[prow][pcol]);
                    ans = max(ans, curr[i][j] + (k-moves) * arr[i][j]);
                }
            }
        }
        dp = curr;
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
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}