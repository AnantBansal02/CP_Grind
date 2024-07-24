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
    ll N, M, K;cin>>N>>M>>K;
    vector<ll> A(N), B(M);
    map<ll,ll> a, b;
    for(auto &it : A){
        cin>>it;
    }    
    for(auto &it : B){
        cin>>it;
        b[it]++;
    }
    ll ans = 0;
    ll cnt = 0;
    for(ll i=0;i<M;i++){
        a[A[i]]++;
        if(b.count(A[i]) and a[A[i]] <= b[A[i]]){
            cnt++;
        }
    }
    if(cnt >= K){
        ans++;
    }
    for(ll i=M;i<N;i++){
        a[A[i - M]]--;
        if(b.count(A[i - M]) and a[A[i - M]] < b[A[i - M]]){
            cnt--;
        }
        a[A[i]]++;
        if(b.count(A[i]) and a[A[i]] <= b[A[i]] ){
            cnt++;
        }
        if(cnt >= K){
            ans++;
        }
    }
    cout<<ans<<"\n";
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