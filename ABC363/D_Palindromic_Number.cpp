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
    ll n; cin >> n;
    if(n == 1){
        cout << 0 << "\n";
        return;
    }
    vector<ll> num(36);
    num[0] = 1;num[1] = 9;
    for(ll i = 2; i < 36; i++){
        if(i & 1){
            num[i] = num[i-1] * 10LL;
        }
        else{
            num[i] = num[i-1];
        }
    }
    for(ll i = 1; i < 36; i++){
        num[i] += num[i - 1];
    }
    ll len = 0;
    for(ll i = 0; i < 36; i++){
        if(num[i] >= n){
            len = i;
            break;
        }
    }


    n -= num[len - 1];
    // dbg(n);dbg(len);
    string ans = "";
    for(ll idx = 0; idx < (len + 1)/2; idx++){
        // dbg(n);
        if(idx == 0){
            ll curr = 1;
            for(ll j = idx + 1; j < (len + 1)/2; j++){
                curr *= 10LL;
            }
            for(char ch = '1'; ch <= '9'; ch++){
                ll pos = ch - '0';
                if(curr * pos >= n){
                    ans += ch;
                    n -= (pos - 1)*curr;
                    break;
                }
                
            }
        }
        else{
            ll curr = 1;
            for(ll j = idx + 1; j < (len + 1)/2; j++){
                curr *= 10LL;
            }
            for(char ch = '0'; ch <= '9'; ch++){
                ll pos = ch - '0' + 1;
                if(curr * pos >= n){
                    ans += ch;
                    n -= (pos - 1)*curr;
                    break;
                }
            }
        }
    }
    // cout << ans << "\n";
    if(len & 1){
        string temp = ans;
        temp.pop_back();
        reverse(all(temp));
        ans += temp;
    }
    else{
        string temp = ans;
        reverse(all(temp));
        ans += temp;
    }
    cout << ans << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // sieve(1e5);
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}