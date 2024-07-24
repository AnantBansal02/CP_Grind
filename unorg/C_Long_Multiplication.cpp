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
    string a, b;cin>>a>>b;
    ll n = a.size();
    ll i = 0;
    while(i < n and a[i] == b[i]){
        i++;
    }
    if(i == n){
        cout<<a<<"\n";
        cout<<b<<"\n";
        return;
    }
    if(a[i] < b[i]){
        swap(a,b);
    }
    i++;
    for(;i<n;i++){
        if(a[i] > b[i]){
            swap(a[i], b[i]);
        }
    }
    cout<<a<<"\n";
    cout<<b<<"\n";
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