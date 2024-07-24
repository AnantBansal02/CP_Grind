#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int LOCATION = 4020;
const int MAXP = 1001;
const int SHIFT = 1010;
long long dp[MAXP][LOCATION];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), p(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    for(int i = 0; i < n; i++){
        dp[p[i]][a[i] + SHIFT] += 1ll;
        if(p[i] != 0)
            dp[p[i] - 1][a[i] + SHIFT] += 1ll;
    }
    for(int s = MAXP - 2; s >= 0; s--){
        for(int i = 1; i < LOCATION - 1; i++){
            dp[s][i] += dp[s + 1][i - 1] + dp[s + 1][i + 1] - (s + 2 < MAXP ? dp[s + 2][i] : 0);
        }
    }
    for(int i = 0; i < MAXP; i++){
        for(int j = 1; j < LOCATION; j++){
            dp[i][j] += dp[i][j - 1];
        }
    }
    while(q--){
        int l, r, s;
        cin >> l >> r >> s;
        l += SHIFT;
        r += SHIFT;
        cout << dp[s][r] - dp[s][l - 1] << endl;
    }

    return 0;
}