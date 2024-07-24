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

ll power(ll x, ll y, ll p){
    ll res = 1;x = x % p;while (y > 0){if (y & 1)res = (res * x) % p;y = y >> 1;x = (x * x) % p;}return res;
}
ll modInverse(ll n, ll p){
    return power(n, p - 2, p);
}
vector<ll> fac;
void factorial(int n, int MOD){
    fac.resize(n + 1);fac[0] = 1;for (int i = 1; i < n; i++){fac[i] = fac[i - 1] * i % MOD;}
}
ll ncrmod(ll n, ll r, ll p){
    if (n < r)return 0;
    if (r == 0)return 1;
    return (((fac[n] * modInverse(fac[r], p)) % p) * modInverse(fac[n - r], p)) % p;
}
vector<ll> primes;
void seive(ll n){
    bool prime[n + 1];memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {for (int i = p * p; i <= n; i += p)prime[i] = false;}
    }
    for (int p = 2; p <= n; p++)if(prime[p])primes.push_back(p);
}
ll getNoOfFactors(ll num) {
    if( num < 2 ) { return 0;}ll cnt = 0;
    for ( auto x : primes ) {while( num % x == 0 ) {cnt++;num /= x ;}}
    if( num > 1){cnt++;}
    return cnt;
}
void solve()
{
    ll n,m;cin>>n>>m;
    vector<string> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    vector<vector<ll>> dis(n, vector<ll>(m, INT_MAX));
    vector<vector<ll>> vis(n, vector<ll>(m, 0));
    queue<pair<pair<ll,ll>,ll>> q;
    ll cnt = 0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(arr[i][j] == '.'){
                cnt++;
            }
            if(arr[i][j] == 'V'){
                q.push({{i, j}, 0});
                dis[i][j] = 0;
            }
        }
    }
    vis[q.front().first.first][q.front().first.second] = 1;
    ll dr[] = {0, 0, -1, 1};
    ll dc[] = {1, -1, 0, 0};
    while(!q.empty()){
        auto node = q.front();
        ll r = node.first.first;
        ll c = node.first.second;
        ll curr = node.second;
        q.pop();
        for(ll i=0;i<4;i++){
            ll nr = r + dr[i];
            ll nc = c + dc[i];
            if(nr >= 0 and nr < n and nc >=0 and nc < m and !vis[nr][nc] and arr[nr][nc] != '#'){
                vis[nr][nc] = 1;
                dis[nr][nc] = curr + 1;
                q.push({{nr,nc}, curr + 1});
            }
        }
    }
    ll exits = 0;
    ll mini = INT_MAX;
    for(ll i=0;i<n;i++){
        if(dis[i][0] != INT_MAX){
            mini = dis[i][0];
            exits++;
        }
        if(dis[i][m-1] != INT_MAX){
            mini = dis[i][m-1];
            exits++;
        }
    }
    for(ll j=0;j<m;j++){
        if(dis[0][j] != INT_MAX){
            mini = dis[0][j];
            exits++;
        }
        if(dis[n-1][j] != INT_MAX){
            mini = dis[n-1][j];
            exits++;
        }
    }
    // case 1
    if(exits == 0){
        cout<<cnt<<"\n";
        return;
    }
    
    // case 2
    if(exits == 1){
        cout<<cnt-mini<<"\n";
        return;
    }

    // case 3

    vector<vector<vector<pair<ll,ll>>>> temp(n, vector<vector<pair<ll,ll>>>(m));
    queue<vector<ll>> que;
    ll id = 1;
    for(ll i=0;i<n;i++){
        if(arr[i][0] != '#'){
            temp[i][0].push_back({0, id});
            que.push({i, 0, 0, id++});
        }
        if(arr[i][m-1] != '#'){
            temp[i][m-1].push_back({0, id});
            que.push({i, m-1, 0, id++});
        }
    }
    for(ll j=0;j<m;j++){
        if(arr[0][j] != '#'){
            temp[0][j].push_back({0, id});
            que.push({0, j, 0, id++});
        }
        if(arr[n-1][j] != '#'){
            temp[n-1][j].push_back({0, id});
            que.push({n-1, j, 0, id++});
        }
    }
    while(!que.empty()){
        auto node = que.front();
        ll r = node[0];
        ll c = node[1];
        ll curr = node[2];
        ll currID = node[3];
        que.pop();
        for(ll i=0;i<4;i++){
            ll nr = r + dr[i];
            ll nc = c + dc[i];
            if(nr >= 0 and nr < n and nc >= 0 and nc < m and temp[nr][nc].size()<2 and arr[nr][nc] != '#'){
                bool flag = true;
                for(auto it : temp[nr][nc]){
                    if(it.second == currID){
                        flag = false;
                    }
                }
                if(flag){
                    temp[nr][nc].push_back({curr + 1, currID});
                    que.push({nr, nc, curr + 1, currID});
                }
            }
        }
    }
    ll ans = INT_MAX;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(temp[i][j].size() == 2){
                ans = min(ans, temp[i][j][0].first + temp[i][j][1].first + dis[i][j]);
            }
        }
    }
    cout<<cnt - ans<<"\n";

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // seive(1e5);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}