#include <bits/stdc++.h>
#define int long long
using namespace std;
 

void solve(){
      int n; cin>>n;
      int b,c,a;
      a = n/100;
      b = (n/10)%10;
      c = n%10;
      cout<<b<<c<<a<<" "<<c<<a<<b<<endl;
}
 
signed main() {
    //int t; cin>>t;while(t--)
    solve();
    return 0;
}