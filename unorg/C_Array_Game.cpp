#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define ll long long
using namespace std;

void solve() {
    ll n;cin>>n;
    vector<ll> arr(n);
    ll k;cin>>k;
    set<ll> s;
    for (ll i = 0; i < n; i++) {
        cin>>arr[i];
        s.insert(arr[i]);
    }
    if (k > 2) {
        cout << 0 << endl;
        return;
    }
    sort(arr.begin(), arr.end());
    ll maxi = *s.begin();
    if (k == 1) {
        for (ll i = 1; i < n; i++) {
            maxi = min(maxi, arr[i] - arr[i - 1]);
        }
        cout << maxi << endl;
        return;
    }
    for (ll i = 1; i < n; i++) {
        maxi = min(maxi, arr[i] - arr[i - 1]);
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = i + 1; j < n; j++) {
            ll val = arr[j] - arr[i];
            if (s.count(val)) {
                cout << 0 << endl;
                return;
            }
            if (*s.begin() < val) {
                maxi = min(maxi, val - *prev(s.lower_bound(val)));
            }
            maxi = min(maxi, *s.upper_bound(val) - val);
        }
    }
    cout << maxi << endl;
}

int main() {
    ll t;cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}
