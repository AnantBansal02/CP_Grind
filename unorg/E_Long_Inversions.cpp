// #pragma GCC optimize("-Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
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

void solve(ll test)
{
    ll N;cin>>N;
    string s;cin>>s;
    for(ll k=N;k>=1;k--){
        queue<ll> q;
        bool flag = true;
        for(ll i=0;i<N;i++){
            if(!q.empty() and q.front() + k <= i){
                q.pop();
            }
            if(s[i] == '0'){
                if((ll)q.size() % 2 == 0){
                    if(N - i < k){
                        flag = false;
                    }
                    q.push(i);
                }
            }
            if(s[i] == '1'){
                if((ll)q.size() % 2 == 1){
                    if(N - i < k){
                        flag = false;
                    }
                    q.push(i);
                }
            }
        }
        if(flag){
            cout<<k<<"\n";
            return;
        }
        
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // seive(1e5);
    ll t = 1;
    cin >> t;
    for(ll i=1;i<=t;i++){
        solve(i);
    }
    return 0;
}