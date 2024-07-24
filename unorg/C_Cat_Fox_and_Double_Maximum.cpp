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


vector<ll> fun(vector<ll>& arr){
    ll n = arr.size();
    vector<ll> ans(n);
    set<ll> st(all(arr));
    map<ll,ll> mp, mp2;
    for(ll i=1;i<n-1;i+=2){
        mp[arr[i]] = i;
    }
    for(ll i=0;i<n;i+=2){
        mp2[arr[i]] = i;
    }
    mp2[arr[n-1]] = n-1;
    // cout<<st.size()<<"\n";
    for(auto it : mp){
        ans[it.second] = *st.rbegin();
        st.erase(*st.rbegin());
    }
    for(auto it : mp2){
        ans[it.second] = *st.rbegin();
        st.erase(*st.rbegin());
    }
    return ans;
}
vector<ll> fun2(vector<ll>& arr){
    ll n = arr.size();
    vector<ll> ans(n);
    set<ll> st(all(arr));
    map<ll,ll> mp, mp2;
    for(ll i=2;i<n-1;i+=2){
        mp[arr[i]] = i;
    }
    for(ll i=1;i<n;i+=2){
        mp2[arr[i]] = i;
    }
    mp2[arr[0]] = 0;
    // cout<<st.size()<<"\n";
    for(auto it : mp){
        ans[it.second] = *st.rbegin();
        st.erase(*st.rbegin());
    }
    for(auto it : mp2){
        ans[it.second] = *st.rbegin();
        st.erase(*st.rbegin());
    }
    return ans;
}

ll check(vector<ll>& temp, vector<ll>& arr){
    ll n = arr.size();
    vector<ll> curr(n);
    for(ll i=0;i<n;i++){
        curr[i] = arr[i] + temp[i];
    }
    ll cnt = 0;
    for(ll i=1;i<n-1;i++){
        if(curr[i] > curr[i-1] and curr[i] > curr[i+1]){
            cnt++;
        }
    }   
    return cnt;
}

void solve()
{
    ll n;cin>>n;
    vector<ll> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    vector<ll> temp = fun(arr);
    vector<ll> temp2 = fun2(arr);
    ll cnt = check(temp, arr);
    ll cnt2 = check(temp2, arr);
    if(cnt > cnt2){
        for(auto it : temp){
            cout<<it<<" ";
        }
        cout<<"\n";
    }
    else{
        for(auto it : temp2){
            cout<<it<<" ";
        }
        cout<<"\n";
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