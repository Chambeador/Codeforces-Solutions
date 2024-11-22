#include <bits/stdc++.h>
#define int long long
using namespace std;
 

void solve(){
     int n,k; cin>>n>>k;
     string s; cin>>s;
     s = 'X'+s;
     int ans = 0;
     int c = 0;
     for(int i = 0; i < (int)s.size(); i++){
         if(s[i] == 'O'){
            c++;
         }else{
            c = 0;
         }
         if(c >= k){
            ans++;
            c = 0;
         }
     }
     cout<<ans<<endl;
}
 
signed main() {
    //int t; cin>>t;while(t--)
    solve();
    return 0;
}