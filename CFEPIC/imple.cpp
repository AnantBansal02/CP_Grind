#include"bits/stdc++.h"
using namespace std;

struct offers{
    string type;
    string name;
    int qnt;
};

int main(){ 

    int n;
    cin>>n;

    vector<offers> v(n);

    for(int i=0;i<n;i++){
        string tpe,nme;
        cin>>tpe>>nme;
        int qt;
        cin>>qt;

        offers offer;
        offer.type=tpe;
        offer.name=nme;
        offer.qnt=qt;

        v[i]=offer;
    }

    queue<offers> q;
    vector<pair<pair<string,string>,int>> ans;


    q.push(v[0]);

    for(int i=1;i<n;i++){
        auto &it=q.front();
        auto &cur=v[i];
        if(cur.type!=it.type){
            if(it.qnt < cur.qnt){
                ans.push_back({{it.name,cur.name},it.qnt});
                cur.qnt-=it.qnt;
                q.pop();
                i--;
            }
            else if(it.qnt> cur.qnt){
                ans.push_back({{it.name,cur.name},cur.qnt});
                it.qnt-=cur.qnt;
            }
            else{
                ans.push_back({{it.name,cur.name},cur.qnt});
                q.pop();
            }
        }
        else{
            q.push(v[i]);
        }
    }

    for(auto it:ans){
        cout<<it.first.first<<" : "<<it.first.second<<" "<<it.second<<endl;
    }

}