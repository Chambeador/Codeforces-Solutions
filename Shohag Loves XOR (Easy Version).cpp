#include <bits/stdc++.h>
 
using namespace std;

void solve(){
     int x, m; cin>>x>>m;
     set<int> ans;
     for(int i = 1; i <= min((x*2), m); i++){
         int z = (x^i);
         if(z >= 1 and z<= m
             and ( x % z == 0 or i % z == 0)){
             ans.insert(i);
         }
 
     }
     cout<<ans.size()<<endl;
 
}
signed main(){
     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}