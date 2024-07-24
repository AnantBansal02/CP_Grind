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
    ll a,b,c;cin>>a>>b>>c;
    if((a + b + c) % 2 != 0){
        cout<<"-1"<<"\n";
        return;
    }
    priority_queue<ll> pq;
    pq.push(b);pq.push(c);
    ll ans = 0;
    while(a){
        a--;
        ans++;
        auto it = pq.top();
        pq.pop();
        pq.push(it-1);
    }
    ll d = pq.top();
    pq.pop();
    ll e = pq.top();
    pq.pop();
    ans += min(d, e);
    cout<<ans<<"\n";
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