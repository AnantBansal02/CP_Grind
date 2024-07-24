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
    vector<ll> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    vector<pair<ll,ll>> temp;
    for(ll i=0;i<n;i++){
        if(arr[i] != -1){
            temp.pb({i, arr[i]});
        }
    }
    if(temp.size() == 0){
        for(ll i=0;i<n;i++){
            if(i&1){
                cout<<1<<' ';
            }
            else{
                cout<<2<<' ';
            }
        }
        cout<<"\n";
        return;
    }
    for(ll i=temp[0].first, flag=1;i>=0;i--){
        if(flag){
            arr[i] = temp[0].second;
            flag = 0;
        }
        else{
            arr[i] = temp[0].second * 2;
            flag = 1;
        }
    }
    for(ll i=temp.back().first, flag=1;i<n;i++){
        if(flag){
            arr[i] = temp.back().second;
            flag = 0;
        }
        else{
            arr[i] = temp.back().second * 2;
            flag = 1;
        }
    }
    auto fun = [&](ll l, ll r, ll val1){
        for(ll i=l+1, flag=1;i<r;i++){
            if(flag){
                arr[i] = val1*2;
                flag = 0;
            }
            else{
                arr[i] = val1;
                flag = 1;
            }
        }
    };
    for(ll i=0;i<temp.size()-1;i++){
        ll l = temp[i].first;
        ll r = temp[i+1].first;
        ll val1 = temp[i].second;
        ll val2 = temp[i+1].second;
        set<ll> st1, st2;
        ll temp1 = val1;
        ll temp2 = val2;
        while(temp1){
            st1.insert(temp1);
            temp1 /= 2;
        }
        while(temp2){
            st2.insert(temp2);
            temp2 /= 2;
        }
        // dbg(l);dbg(r);
        // dbg(val1);dbg(val2);
        if(val1 < val2){
            ll curr = val2;
            for(ll i=r-1;i>l;i--){
                curr /= 2;
                arr[i] = curr;
                if(st1.find(curr) != st1.end()){
                    ll idx = l+1;
                    ll curr2 = val1;
                    while(curr2 != curr){
                        curr2 /= 2;
                        arr[idx++] = curr2;
                    }
                    fun(idx-1, i, curr);
                    break;
                }  
            }
        }   
        else if(val1 > val2){
            ll curr = val1;
            for(ll i=l+1;i<r;i++){
                curr /= 2;
                arr[i] = curr;
                if(st2.find(curr) != st2.end()){
                    ll idx = r-1;
                    ll curr2 = val2;
                    while(curr2 != curr){
                        curr2 /= 2;
                        arr[idx--] = curr2;
                    }
                    fun(i, idx+1, curr);
                    break;
                }  
            }
        } 
        else{
            fun(l, r, val1);
        }

    }
    for(ll i=0;i<n-1;i++){
        if(arr[i] != arr[i+1]/2 and arr[i+1] != arr[i]/2){
            cout<<"-1"<<"\n";
            return;
        }
    }
    for(auto it : arr){
        cout<<it<<" ";
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