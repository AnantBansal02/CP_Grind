#include<bits/stdc++.h>
using namespace std;
bool cmp(string&a, string&b){
    string temp1 = a + b;
    string temp2 = b + a;
    for(int i=0;i<temp1.size();i++){
        if(temp1[i] < temp2[i]){
            return false;
        }
        else if(temp2[i] < temp1[i]){
            return true;
        }
    }
    return true;
}
string largestNumber(vector<int> &A) {
    vector<string> arr;
    for(auto it : A){
        arr.push_back(to_string(it));
    }
    sort(arr.begin(), arr.end(), cmp);
    string ans = "";
    for(int i=0;i<arr.size();i++){
        for(auto it : arr[i]){
            ans += it;
        }
    }
    return ans;
}

int main(){
    int n;cin>>n;
    vector<int> a(n);
    for(auto &it : a){
        cin>>it;
    }
    cout<<largestNumber(a)<<"\n";
}
