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
    ll n, k;
    cin >> n >> k;
    if(n == 2){
        if(k == 1){
            cout<< "1 2" << "\n";
        }
        else{
            cout << "-1" << "\n";
        }
        return;
    }
    ll max = 0;
    ll temp = n;
    while(temp != 1){
        max++;
        temp = (temp + 1) / 2;
    }
    if(k > max){
        cout << "-1" << "\n";
        return;
    }
    vector<ll> ans;
    ans.push_back(n);
    ans.push_back(n-1);
    set<ll> st;
    for(ll i=1;i<n-1;i++){
        st.insert(i);
    }
    k--;
    while(k){
        ll sz = ans.size();
        ll nsz = 2 * sz - 1;
        vector<ll> temp;
        ll idx = 0;
        for(ll i=0;i<nsz;i++){
            ll val = -1;
            if(i%2 == 0){
                val = ans[idx++];
            }
            else if(!st.empty()){
                val = *st.rbegin();
                st.erase(*st.rbegin());
            }
            temp.push_back(val);
        }
        ans = temp;
        k--;
    }
    while(!st.empty()){
        ans.push_back(*st.rbegin());
        st.erase(*st.rbegin());
    }
    for(auto it : ans){
        cout << it << " ";
    }
    cout << "\n";
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