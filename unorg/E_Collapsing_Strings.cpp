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
class Trie {

public:
    struct Node{
        Node *links[26];
        bool flag = false;
        ll num = 0;
        bool containskey(char ch){
            return links[ch-'a'] != NULL;
        }
        void setkey(char ch,Node *node){
            links[ch-'a'] = node;
        }
        Node *next(char ch){
            return links[ch-'a'];
        }
        void setEnd(){
            flag = true;
        }
        bool isEnd(){
            return flag;
        }
    };

    /** Initialize your data structure here. */
    Node *root = new Node();
    Trie() {
        
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        ll n = word.length();
        for(ll i=0;i<n;i++){
            if(!node->containskey(word[i])){
                node->setkey(word[i], new Node());
            }
            node->links[word[i] - 'a']->num += 1;
            node = node->next(word[i]);
        }
        node->setEnd();
    }   
    ll find(string s)
    {
        Node* node = root;
        ll ans = 0;
        ll sz = (ll)s.length();
        for (ll i = 0; i < sz; i++) {
            if (!node->containskey(s[i]))
                return ans + (i) * (ll)node->num;
            
            ll prev = node->num;
            node = node->next(s[i]);
            
            ll curr = node->num;
            ans += max(prev - curr, 0LL) * (i);
        }
        ans += sz * (ll)node->num;
        return ans;
    }
};
void solve()
{
    ll n;cin>>n;
    vector<string> arr(n);
    Trie *trie = new Trie();
    ll tot = 0;
    for(auto &it : arr){
        cin>>it;
        tot += it.size();
        reverse(all(it));
        trie->insert(it);
        reverse(all(it));
    }
    ll ans = 2*n*tot;
    for(auto it : arr){
        ll curr = trie->find(it);
        ans -= curr*2;
    }
    cout<<ans<<"\n";
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