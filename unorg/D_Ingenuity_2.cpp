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
    vector<ll> Hel = {0, 0, 0};
    vector<ll> Rov = {0, 0, 0};
    string ans = "";
    for(auto it : s){
        if(it == 'N'){
            if(Hel[0] > Rov[0]){
                ans += 'R';
                Rov[0]++;Rov[2]++;
            }
            else if(Rov[0] > Hel[0]){
                ans += 'H';
                Hel[0]++;Hel[2]++;
            }
            else{
                if(Hel[2] > Rov[2]){
                    ans += 'R';
                    Rov[0]++;Rov[2]++;
                }
                else{
                    ans += 'H';
                    Hel[0]++;Hel[2]++;
                }
            }
        }
        if(it == 'S'){
            if(Hel[0] > Rov[0]){
                ans += 'H';
                Hel[0]--;Hel[2]++;
            }
            else if(Rov[0] > Hel[0]){
                ans += 'R';
                Rov[0]--;Rov[2]++;
            }
            else{
                if(Hel[2] > Rov[2]){
                    ans += 'R';
                    Rov[0]--;Rov[2]++;
                }
                else{
                    ans += 'H';
                    Hel[0]--;Hel[2]++;
                }
            }
        }
        if(it == 'E'){
            if(Hel[1] > Rov[1]){
                ans += 'R';
                Rov[1]++;Rov[2]++;
            }
            else if(Rov[1] > Hel[1]){
                ans += 'H';
                Hel[1]++;Hel[2]++;
            }
            else{
                if(Hel[2] > Rov[2]){
                    ans += 'R';
                    Rov[1]++;Rov[2]++;
                }
                else{
                    ans += 'H';
                    Hel[1]++;Hel[2]++;
                }
            }
        }
        if(it == 'W'){
            if(Hel[1] > Rov[1]){
                ans += 'H';
                Hel[1]--;Hel[2]++;
            }
            else if(Rov[1] > Hel[1]){
                ans += 'R';
                Rov[1]--;Rov[2]++;
            }
            else{
                if(Hel[2] > Rov[2]){
                    ans += 'R';
                    Rov[1]--;Rov[2]++;
                }
                else{
                    ans += 'H';
                    Hel[1]--;Hel[2]++;
                }
            }
        }
    }
    ll cnt1 = count(all(ans), 'R');
    ll cnt2 = count(all(ans), 'H');
    if(Hel[0] == Rov[0] and Hel[1] == Rov[1] and cnt1 and cnt2){
        cout<<ans<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
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