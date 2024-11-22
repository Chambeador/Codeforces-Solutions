#include <bits/stdc++.h>
 
using namespace std;
 
void solve(){
     string p; cin>>p;//patron
     int n = p.size();
     int i = 0;
     vector<int> pi(n);
     pi[0] = 0;
     for(int j = 1; j < n; j++){
         while(i > 0  && p[i] != p[j]) i = pi[i-1];
         if(p[i] == p[j]) i++;
         pi[j] = i;
     }

     ///for(auto x: pi) cout<<x<<" ";
     string t; cin>>t;//cadena
     int ans = 0;
     i = 0;
     for(int j = 0; j < t.size(); j++){
         while(i > 0 && t[j] != p[i]) i = pi[i-1]; 
         if(p[i] == t[j]) i++;
         if(i == p.size()){
            ans++;
            i = pi[i-1];
         }       
     } 
     cout<<ans<<endl;
}
signed main(){
     solve();
}