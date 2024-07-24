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

void f(string const& s) {
    int n = s.size();
    string srev = s;
    reverse(all(srev));
    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    vector<long long> hrev(n + 1, 0);
    for (int i = 0; i < n; i++)
        hrev[i+1] = (hrev[i] + (srev[i] - 'a' + 1) * p_pow[i]) % m;

    for(ll i = 1; i <= n; i++){
        // abcdef
        // fedcba
        ll cur_h = h[i];
        cur_h = (cur_h * p_pow[n - i]) % m;
        ll left = (hrev[n] - hrev[n - i] + m) % m;
        // cout<<cur_h<<" "<<left<<" "<<s.substr(0, i)<<"\n";
        ll cur_hrev = hrev[n - i];
        cur_hrev = (cur_hrev * p_pow[i]) % m;
        ll right = (h[n] - h[i] + m) % m;
        // cout<<cur_hrev<<" "<<right<<" "<<s.substr(i)<<"\n";
        if(cur_h != left and (cur_hrev != right || i == n)){
            cout<<"YES"<<"\n";
            if(i == n)cout<<1<<"\n";
            else cout<<2<<"\n";
            cout<<s.substr(0, i)<<" "<<s.substr(i)<<"\n";
            return;
        }
        // cout<<(h[i] * p_pow[n - i - 1])%m<<" "<<(hrev[n - 1] - hrev[n - i - 1] + m)%m<<" "<<s.substr(0, i+1)<<"\n";
    }
    cout<<"NO"<<"\n";
}

void solve()
{
    string s;cin>>s;
    f(s);
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