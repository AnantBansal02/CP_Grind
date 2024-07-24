#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> A(n);
        for(auto &it : A){
            cin>>it;
        }
        vector<int> B(n+1);
        B[0] = A[0];
        B[n] = A[n-1];
        for(int i=1;i<n;i++){
            B[i] = A[i]*A[i-1]/__gcd(A[i], A[i-1]); 
        }
        bool flag = true;
        for(int i=1;i<=n;i++){
            if(__gcd(B[i], B[i-1]) != A[i-1]){
                flag = false;
            }
        }
        if(flag){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
}