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
    ll n, m, y;
    cin >> n >> m >> y;
    vector<vector<ll>> arr(n, vector<ll>(m));
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    vector<vector<ll>> vis(n, vector<ll>(m, 0));
    priority_queue<pair<ll, pair<ll,ll>>> pq;
    for(ll i = 0; i < n; i++){
        pq.push({-arr[i][0], {i, 0}});
        pq.push({-arr[i][m-1], {i, m-1}});
    }
    for(ll j = 1; j < m - 1; j++){
        pq.push({-arr[0][j], {0, j}});
        pq.push({-arr[n-1][j], {n-1, j}});
    }
    ll curr = n * m;
    vector<ll> di = {-1, 1, 0, 0};
    vector<ll> dj = {0, 0, -1, 1};
    function<void(ll, ll, ll)> dfs = [&](ll i, ll j, ll level){
        vis[i][j] = 1;
        curr--;
        for(ll d = 0; d < 4; d++){
            ll ni = i + di[d];
            ll nj = j + dj[d];
            if(ni < 0 || nj < 0 || ni >= n || nj >= m || vis[ni][nj]){
                continue;
            }
            if(arr[ni][nj] <= level){
                dfs(ni, nj, level);
            }
            else{
                pq.push({-arr[ni][nj], {ni, nj}});
            }
        }

    };
    for(ll i = 1; i <= y; i++){
        while(!pq.empty() and -(pq.top().fi) <= i){
            auto it = pq.top();pq.pop();
            if(!vis[it.se.fi][it.se.se]){
                dfs(it.se.fi, it.se.se, i);
            }
        }
        cout << curr << "\n";
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