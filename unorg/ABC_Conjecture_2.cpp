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
    ll n;cin>>n;
    string s;cin>>s;
    ll ans = 0;
    vector<ll> vec(n, -1);
    stack<ll> st;
    for(ll i=0;i<n;i++){
        if(s[i] == 'a'){
            st.push(i);
        }
        else if(s[i] == 'b'){
            if(!st.empty()){
                vec[i] = st.top();
                st.pop();
            }
        }
        else{
        }
    }
    ll last = n;
    for(ll i=n-1;i>=0;i--){
        if(s[i] == 'c'){
            last = i;
        }
        if(vec[i] != -1){
            ans += (vec[i] + 1) * (n - last);
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