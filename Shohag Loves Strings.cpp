#include <bits/stdc++.h>
 
using namespace std;
 
 
 
void solve() {
     string s; cin>>s;
     int n = (int)s.size();
     for(int i = 0; i  <= n-3; i++){
         if(s[i] != s[i+1] and s[i+1] != s[i+2] and s[i] != s[i+2]){ 
             cout<<s[i]<<s[i+1]<<s[i+2]<<endl;
             return;
         }
     }
 
     for(int i = 0; i <= n-2; i++){
         if(s[i] == s[i+1]){
            cout<<s[i]<<s[i+1]<<endl;
            return;
         }
     }
     cout<<-1<<endl;
}

signed main(){
     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}