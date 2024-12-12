#include<bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

signed main(){
     int n,r; cin>>n>>r;
     double angulo = (2*PI)/n;
     double ans = (r*sin(angulo/2))/(1-sin(angulo/2));
     cout<<setprecision(7)<<fixed<<ans<<endl;
}
