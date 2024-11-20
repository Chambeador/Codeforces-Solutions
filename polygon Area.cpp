#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Punto{
      int x,y;
};
signed main(){
       int n; cin>>n;
       vector<Punto> puntos;
       for(int i = 0; i < n; i++){
           int x,y; cin>>x>>y;
           puntos.push_back({x,y});
       }
       int area = 0;
       puntos.push_back(puntos[0]);
       for(int i = 1; i < (int)puntos.size(); i++){
           Punto p1 = puntos[i-1];
           Punto p2 = puntos[i];
           area += (p1.x*p2.y)- (p1.y*p2.x);
       }
       cout<<abs(area)<<endl;
}