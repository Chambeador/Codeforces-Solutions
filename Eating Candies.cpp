#include <bits/stdc++.h>
#define int long long
using namespace std;
 


void solve(){
     int n; cin>>n;
     vector<int> arr(n);
     for(int i = 0; i < n; i++){
         cin>>arr[i];
     }
     int l = 0, r = n-1;
     int suml = 0;
     int sumr = 0;
     int ans = 0;
     while(l <= r){
         if(sumr <= suml){
            sumr+=arr[r];
            if(sumr == suml){
                ans = max(ans, n- (r-l));
            }
            r--;
         }else{
            suml+=arr[l];
            if(sumr == suml){
                ans = max(ans, n -(r-l));
            }
            l++;
         } 
     }
     cout<<ans<<endl;
}
signed main(){
     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}