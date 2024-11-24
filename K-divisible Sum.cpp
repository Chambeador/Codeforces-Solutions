#include <bits/stdc++.h>
#include <sstream>
#define int ll
using namespace std;
 


void solve(){
     int n,k; cin>>n>>k;
     cout<<((((n+k-1)/k)*k+n-1)/n)<<endl;

}
signed main(){
     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}