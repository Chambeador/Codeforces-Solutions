#include <bits/stdc++.h>
#define int long long
using namespace std;
 


void solve(){
      int n; cin>>n;
      vector<int> arr;
      for(int i  = 0; i < n-1; i++){
         int x; cin>>x;
         arr.push_back(x);
     
      }
    sort(arr.begin(), arr.end());
    int ans = 1;
    
    for(auto x: arr){
        if(x != ans){
           cout<<ans<<endl;
           return;
        }
        ans++;
    }
    cout<<n<<endl;
    return;
}
signed main(){
     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}