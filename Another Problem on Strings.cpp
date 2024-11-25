#include <bits/stdc++.h>
#define int long long
using namespace std;
 
 
void solve(){
     int k;
    string s;cin>>k>>s;
    map<int, int> mapita;
    mapita[0]++;  
    int unos = 0;  
    int ans = 0;
    for(char c : s){
        if(c == '1')unos++;
        if(mapita.find(unos - k) != mapita.end()) 
           ans += mapita[unos - k];
        mapita[unos]++;
    }
    cout<<ans<<endl;
}
signed main() {
    solve();
    return 0;
}