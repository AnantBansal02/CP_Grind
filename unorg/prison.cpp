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

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    using Cell = pair<ll, pair<ll, ll>>;
    priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
    vector<vector<ll>> dis(n, vector<ll>(m, INF));

    for (ll i = 0; i < n; i++) {
        ll val1 = (arr[i][0] == '1') ? 1 : 0;
        ll val2 = (arr[i][m - 1] == '1') ? 1 : 0;
        pq.push({val1, {i, 0}});
        dis[i][0] = val1;
        pq.push({val2, {i, m - 1}});
        dis[i][m - 1] = val2;
    }
    for (ll j = 1; j < m - 1; j++) {
        ll val1 = (arr[0][j] == '1') ? 1 : 0;
        ll val2 = (arr[n - 1][j] == '1') ? 1 : 0;
        pq.push({val1, {0, j}});
        dis[0][j] = val1;
        pq.push({val2, {n - 1, j}});
        dis[n - 1][j] = val2;
    }

    ll dr[] = {-1, 1, 0, 0};
    ll dc[] = {0, 0, 1, -1};

    while (!pq.empty()) {
        auto it = pq.top();
        ll curr = it.first;
        ll r = it.second.first;
        ll c = it.second.second;
        pq.pop();
        for (ll i = 0; i < 4; i++) {
            ll nr = r + dr[i];
            ll nc = c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                ll val = (arr[nr][nc] == '1') ? 1 : 0;
                if (dis[nr][nc] > val + curr) {
                    dis[nr][nc] = val + curr;
                    pq.push({val + curr, {nr, nc}});
                }
            }
        }
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (arr[i][j] == '0') {
                ans = max(ans, dis[i][j]);
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
