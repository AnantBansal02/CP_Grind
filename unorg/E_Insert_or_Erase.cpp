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

ll power(ll x, ll y, ll p){
    ll res = 1;x = x % p;while (y > 0){if (y & 1)res = (res * x) % p;y = y >> 1;x = (x * x) % p;}return res;
}
ll modInverse(ll n, ll p){
    return power(n, p - 2, p);
}
vector<ll> fac;
void factorial(int n, int MOD){
    fac.resize(n + 1);fac[0] = 1;for (int i = 1; i < n; i++){fac[i] = fac[i - 1] * i % MOD;}
}
ll ncrmod(ll n, ll r, ll p){
    if (n < r)return 0;
    if (r == 0)return 1;
    return (((fac[n] * modInverse(fac[r], p)) % p) * modInverse(fac[n - r], p)) % p;
}
vector<ll> primes;
void seive(ll n){
    bool prime[n + 1];memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {for (int i = p * p; i <= n; i += p)prime[i] = false;}
    }
    for (int p = 2; p <= n; p++)if(prime[p])primes.push_back(p);
}
ll getNoOfFactors(ll num) {
    if( num < 2 ) { return 0;}ll cnt = 0;
    for ( auto x : primes ) {while( num % x == 0 ) {cnt++;num /= x ;}}
    if( num > 1){cnt++;}
    return cnt;
}
class Node { 
public: 
    ll data; 
    Node* next; 
    Node* prev;
    Node()
    { 
        data = 0; 
        next = NULL; 
        prev = NULL;
    } 
    Node(ll data) 
    { 
        this->data = data; 
        this->next = NULL; 
        this->prev = NULL;
    } 
}; 
void solve()
{
    ll n;cin>>n;
    vector<ll> arr(n);
    for(auto &it : arr){
        cin>>it;
    }
    map<ll,Node*> mp;
    Node* start = NULL;
    for(auto it : arr){
        mp[it] = new Node(it);
    }
    for(ll i=0;i<n-1;i++){
        mp[arr[i]]->next = mp[arr[i+1]];
    }
    for(ll i=1;i<n;i++){
        mp[arr[i]]->prev = mp[arr[i-1]];
    }
    start = mp[arr[0]];
    ll q;cin>>q;
    while(q--){
        ll type;cin>>type;
        if(type == 1){
            ll x,y;cin>>x>>y;
            if(mp[x]->next == NULL){
                mp[y] = new Node(y);
                mp[x]->next = mp[y];
                mp[y]->prev = mp[x];
            }
            else{
                Node* temp = mp[x]->next;
                mp[y] = new Node(y);
                mp[x]->next = mp[y];
                mp[y]->next = temp;
                temp->prev = mp[y];
                mp[y]->prev = mp[x];
            }
        }
        else{
            ll x;cin>>x;
            if(mp[x] == start){
                Node* temp = mp[x]->next;
                temp->prev = NULL;
                start = temp;
                mp.erase(x);
            }
            else if(mp[x]->next == NULL){
                Node* p = mp[x]->prev;
                p->next = NULL;
                mp.erase(x);
            }
            else{
                Node* p = mp[x]->prev;
                Node* a = mp[x]->next;
                p->next = a;
                a->prev = p;
                mp.erase(x);
            }
        }
    }
    Node* curr = start;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<"\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // factorial(1e5,1e9+7);
    // seive(1e5);
    ll t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}