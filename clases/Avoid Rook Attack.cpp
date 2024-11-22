#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    set<int> filas,colum;
    for(int i=0;i<8;i++){
        string s;
        cin>>s;
        for(int j=0;j<8;j++){
            if(s[j]=='#'){
                filas.insert(i);
                colum.insert(j);
            }
        }
    }
    int ans=0;
    for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
            if(filas.find(i)==filas.end()&&colum.find(j)==colum.end()){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}


signed main(){
    //int t; cin>>t; while(t--)
    solve();
    return 0;
}
