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
    ll N, K;cin>>N>>K;
    if(N < K){
        cout<<"NO"<<"\n";
        return;
    }
    if(N - (K * (N / K)) < (N / K)){
        cout<<"YES"<<"\n";
        cout<<1<<"\n";
        cout<<N/K<<"\n";
        return;
    }   
    if(N - K + 1 == 0  || N / (N - K + 1) > 1){
        cout<<"NO"<<"\n";
        return;
    }
    cout<<"YES"<<"\n";
    cout<<2<<"\n";
    cout<<N-K+1<<" "<<1<<"\n";

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