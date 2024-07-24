#include <bits/stdc++.h>
using namespace std;


void solve()
{
    vector<vector<int>> divisors(500001);
    for(int i = 1; i <= 500000; i++){
        for(int j = i; j <= 500000; j+=i){
            divisors[j].push_back(i);
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> arr(n);
        for(auto &it : arr) cin >> it;  
        long long ans = 0;
        vector<vector<int>> temp(11, vector<int>(n+1)), temp2(n + 1);
        for(int i = 1; i <= n; i++){
            int g = __gcd(arr[i - 1], i);
            int a = arr[i - 1] / g;
            int b = i / g;
            for(auto &it : divisors[a]){
                if(b <= 10){
                    ans += temp[b][it];
                }
                else{
                    for(auto &d : temp2[it]){
                        if(d == b){
                            ans++;
                        }
                    }
                }
            }
            for(auto &it : divisors[a]){
                if(it <= 10){
                    temp[it][b]++;
                }
                else{
                    temp2[b].push_back(it);
                }
            }
        }
        cout << ans << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}