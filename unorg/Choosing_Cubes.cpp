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
    ll n, f, k;
    cin >> n >> f >> k;
    vector<ll> arr(n);
    for(auto &it : arr){
        cin>>it;
    }    
    vector<ll> temp(n);
    iota(all(temp), 0LL);
    sort(all(temp), [&] (ll &a, ll &b)-> bool {
        return arr[a] > arr[b];
    });
    if(k != n and arr[temp[k-1]] == arr[f-1] and arr[temp[k]] == arr[f-1]){
        cout<<"MAYBE"<<"\n";
    }
    else if(arr[temp[k-1]] > arr[f-1]){
        cout<<"NO"<<"\n";
    }
    else{
        cout<<"YES"<<"\n";
    }

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