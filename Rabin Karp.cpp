#include<bits/stdc++.h>
#define int long long
using namespace std;
 



vector<int> rabin(string &s, string &t){
      int p = 31;
      int m = 1e9+9;
      int S = s.size(), T = t.size();
      vector<int> pot(max(S,T));
      pot[0] = 1;
      for(int i = 1; i < (int) pot.size(); i++){
          pot[i] = (pot[i-1]*p)%m;
      }
      vector<int> hash(T+1, 0);
      for(int i = 0; i < T; i++)
      hash[i+1] = (hash[i]+(t[i]-'a'+1)*pot[i])%m;

      int hash_s = 0;
      for(int i = 0; i < S; i++){
          hash_s = (hash_s + (s[i]-'a'+1)*pot[i])%m;
      }
      vector<int> ans;
      for(int i = 0; i+S-1 < T; i++){
          int cur = (hash[i+S]+m-hash[i])%m;
          if(cur == hash_s*pot[i]%m){
             ans.push_back(i);
          }
      }
      return ans;
}

void solve(){
     string t,s; cin>>t>>s;
     vector<int> ans = rabin(s,t);
     if(ans.size()){
        cout<<ans.size()<<endl;
        for(auto x: ans) cout<<x+1<<" ";
        cout<<endl;
     }else cout<<"Not Found"<<endl;
}

signed main(){
     
     int t; cin>>t; while(t--){
      solve();
      if(t) cout<<endl;
     }
     return 0;
}