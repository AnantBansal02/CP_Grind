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
    string s; cin >> s;
    vector<string> arr(2);
    arr[0].resize(k, '0');
    arr[1].resize(k, '1');
    if(n == k){
        if(s == arr[0] || s == arr[1]){
            cout<< n <<"\n";
        }
        else{
            cout<<"-1"<<"\n";
        }
        return;
    }
    auto check = [&](string& curr){
        ll idx = curr[0] - '0';
        for(ll i=0;i<n;i+=k){
            if(curr.substr(i, k) != arr[idx]){
                return false;
            }
            idx ^= 1;
        }  
        return true;
    };
    if(check(s)){
        cout << n << "\n";
        return;
    }
    vector<ll> suff(n, 0);
    ll cnt = 0;
    for(ll i=n-1;i>=0;i--){
        if(s[i] == s[n-1]){
            cnt++;
        }
        else{
            break;
        }
    }
    if(cnt < k){
        cnt = k - cnt;
        ll idx = s[0] - '0';
        for(ll i=0;i<n;i+=k){
            if(s.substr(i, k) != arr[idx]){
                ll ans = -1;
                {
                    string temp = s.substr(0, i + cnt);
                    string temp2 = s.substr(i+cnt);
                    reverse(all(temp));
                    temp2 += temp;
                    if(check(temp2)){
                        ans = temp.size();
                    }
                }
                if(i > 0){
                    i -= k;
                    string temp = s.substr(0, i + cnt);
                    string temp2 = s.substr(i+cnt);
                    reverse(all(temp));
                    temp2 += temp;
                    if(check(temp2)){
                        ans = temp.size();
                    }   
                }
                cout<<ans<<"\n";
                return;
            }
            idx ^= 1;
        }
    }
    else{
        ll idx = s[0] - '0';
        for(ll i=0;i<n;i+=k){
            if(s.substr(i, k) != arr[idx]){
                ll ans = -1;
                {
                    string temp = s.substr(0, i);
                    string temp2 = s.substr(i);
                    reverse(all(temp));
                    temp2 += temp;
                    if(check(temp2)){
                        ans = temp.size();
                    }
                }
                if(i > 0){
                    i -= k;
                    string temp = s.substr(0, i);
                    string temp2 = s.substr(i);
                    reverse(all(temp));
                    temp2 += temp;
                    if(check(temp2)){
                        ans = temp.size();
                    }   
                }
                cout<<ans<<"\n";
                return;
            }
            idx ^= 1;
        }
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