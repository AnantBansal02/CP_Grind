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



ll bs(vector<ll>& temp, ll val){
    ll low = 0;
    ll high = temp.size()-1;
    ll idx = -1;
    while(low <= high){
        ll mid = low + high >> 1;
        if(temp[mid] > val){
            idx = temp[mid];
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return idx;
}
void solve()
{
    ll n,q;cin>>n>>q;
    vector<ll> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    map<ll, vector<ll>> mp;

    vector<ll> pre(n+1, 0);

    for(ll i=0;i<=n;i++){
        mp[pre[i]].push_back(i);
        if(i < n) pre[i+1] = (arr[i] ^ pre[i]);
    }
    for(ll i=0;i<q;i++){
        ll l, r;cin>>l>>r;
        if(r - l == 0){
            cout<<"NO"<<"\n";
        }
        else if((pre[r] ^ pre[l - 1]) == 0){
            cout<<"YES"<<"\n";
        }
        else{
            ll idx = bs(mp[pre[r]], l-1);
            if(idx == -1 || idx == r){
                cout<<"NO"<<"\n";
                continue;
            }
            ll idx2 = bs(mp[pre[l-1]], idx);
            if(idx2 == -1 || idx2 >= r){
                cout<<"NO"<<"\n";
                continue;
            }
            cout<<"YES"<<"\n";
        }
    }
    cout<<"\n";
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

// #pragma GCC optimize("-Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
// #pragma GCC optimize("unroll-loops")
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// #define dbg(x) cout << #x << " = " << x << "\n"
// #define pb push_back
// #define fi first
// #define se second
// #define INF 1e18
// #define all(x) (x).begin(), (x).end()
// #define set_bits(x) __builtin_popcountll(x)


// void solve()
// {
//     ll n,q;cin>>n>>q;
//     vector<ll> arr(n);
//     for(auto &it : arr){
//         cin>>it;
//     }
//     map<ll, vector<ll>> mp;
//     mp[0].push_back(0);
//     vector<ll> pre(n+1, 0);
//     for(ll i=0;i<n;i++){
//         pre[i+1] = (arr[i] ^ pre[i]);
//         // cout<<pre[i+1]<<" ";
//         mp[pre[i+1]].push_back(i+1);
//     }
//     // cout<<"\n";
//     for(ll i=0;i<q;i++){
//         ll l, r;cin>>l>>r;
//         if(r - l == 0){
//             cout<<"NO"<<"\n";
//         }
//         else if((pre[r] ^ pre[l - 1]) == 0){
//             cout<<"YES"<<"\n";
//         }
//         else{
//             ll cnt = 0;
//             vector<ll>& temp = mp[pre[r]];
//             ll low = 0;
//             ll high = temp.size()-1;
//             ll idx = -1;
//             while(low <= high){
//                 ll mid = low + high >> 1;
//                 if(temp[mid] >= l){
//                     idx = temp[mid];
//                     high = mid - 1;
//                 }
//                 else{
//                     low = mid + 1;
//                 }
//             }
//             // cout<<idx<<"\n";
//             if(idx == -1 || idx == r){
//                 cout<<"NO"<<"\n";
//                 continue;
//             }
        
//             vector<ll>& temp2 = mp[pre[l-1]];
//             low = 0;
//             high = temp2.size() - 1;
//             ll idx2 = -1;
//             while(low <= high){
//                 ll mid = low + high >> 1;
//                 if(temp2[mid] > idx){
//                     idx2 = temp2[mid];
//                     high = mid - 1;
//                 }
//                 else{
//                     low = mid + 1;
//                 }
//             }
//             if(idx2 == -1 || idx2 >= r){
//                 cout<<"NO"<<"\n";
//                 continue;
//             }
//             cout<<"YES"<<"\n";
//         }
//     }
//     cout<<"\n";
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     // factorial(1e5,1e9+7);
//     // sieve(1e5);
//     ll t = 1;
//     cin >> t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }