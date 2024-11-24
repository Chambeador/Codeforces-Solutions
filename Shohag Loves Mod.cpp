#include <bits/stdc++.h>
using namespace std;
 
 
 
void solve() {
     int n; cin>>n;
     int amigo = 1;
     for(int i = 0; i < n; i++){
        cout<<amigo<<" ";
        amigo += 2;
     }
     cout<<endl;
}
 
signed main(){
     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}