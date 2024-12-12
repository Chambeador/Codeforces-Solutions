#include<bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
     int n; cin>>n;
     //cout<<"este es mi n "<<n<<endl;
     vector<int> xs;
     vector<int> ys;
     vector<pair<pair<int, int>, pair<int, int>>> pares(n);
     for(int i = 0; i < n; i++){
         int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
         xs.push_back(x1);
         xs.push_back(x2);
         ys.push_back(y1);
         ys.push_back(y2);
         pares[i] = {{x1,y1},{x2,y2}};
     }
     sort(xs.begin(), xs.end());
     sort(ys.begin(), ys.end());
     int xMedio = xs[xs.size()/2];
     int yMedio = ys[ys.size()/2];
     int ans = 0;
     //cout<<xMedio<<" "<<yMedio<<" "<<endl;
     for(int i = 0; i < n; i++){
         pair<pair<int, int>, pair<int, int>> parsitos = pares[i];
         pair<int, int> par1 = parsitos.first; 
         pair<int, int> par2 = parsitos.second;
         if (par1.first > xMedio)  ans += (par1.first - xMedio);
         if (par2.first < xMedio)  ans += (xMedio - par2.first);
         if (par1.second > yMedio) ans += (par1.second - yMedio);
         if (par2.second < yMedio) ans += (yMedio - par2.second);
        }
         cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}