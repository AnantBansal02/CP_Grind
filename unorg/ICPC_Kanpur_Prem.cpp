#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;cin>>t;
    while(t--){
        ll N;cin>>N;
        vector<ll> A(N);
        for(auto &it : A){
            cin>>it;
        }
        vector<ll> B(N+1);
        B[0] = A[0];B[N] = A[N-1];
        for(ll i=1;i<N;i++){
            B[i] = A[i]*A[i-1]/__gcd(A[i], A[i-1]);
        }
        bool f = true;
        for(ll i=1;i<=N;i++){
            if(__gcd(B[i], B[i-1]) != A[i-1]){
                f = false;
            }
        }
        if(f){
            cout<<"YES"<<'\n';
        }
        else{
            cout<<"NO"<<'\n';
        }
    }
}
