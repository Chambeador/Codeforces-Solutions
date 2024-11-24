#include <bits/stdc++.h>
#define int long long
using namespace std;
 


void solve(){
     int n,k,q; cin>>n>>k>>q;
     vector<int> puntos(k+1);
     vector<int> tiempos(k+1);
     puntos[0] = 0;
     tiempos[0] = 0;
     for(int i = 1; i <= k; i++) cin>>puntos[i];
     for(int i = 1; i <= k; i++) cin>>tiempos[i];
     while(q--){
        int d; cin>>d;
        int i = 0;
        int l = 0, r = k;
        while(l <= r){
             int m = l + (r-l)/2;
             if(puntos[m] > d){
                r = m-1;
             }else{
                i = m;
                l = m+1; 
             }
        }
        if(puntos[i] == d){
           cout<<tiempos[i]<<" ";
        }else{
          int tiempo = tiempos[i]+(d-puntos[i])*(tiempos[i+1]-tiempos[i])/(puntos[i+1]-puntos[i]);
            cout << tiempo<<" ";
        }
     }
     cout<<endl;
}
signed main(){
     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}