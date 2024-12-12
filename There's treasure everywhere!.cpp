#include<bits/stdc++.h>
#define double long double
using namespace std;

const double PI = acos(-1);


double dist(int x, int y){
       return sqrtl(x*x + y*y);
}

signed main(){
     string s;
     int n;
     char ch, ch1;
     double x,y,hhh = 1.0/sqrt(2.0), aumento;
     int con = 0;
     while(cin>>s && s != "END"){
         x = y = 0;
         con++;
         stringstream ss(s);
         while(ss >> n){
              ss >>ch;
              ss>>ch1;
              if(ch1 != ',' and ch1 != '.'){
                aumento = (double)n*hhh;
                if(ch == 'N'){
                    y+= aumento;
                }else y-=aumento;
                if(ch1 == 'W'){
                   x-=aumento;
                }else x+=aumento;
                ss>>ch1;
              }else{
                  if(ch == 'N') y+= n;
                  if(ch == 'S') y-=n;
                  if(ch == 'E') x+= n;
                  if(ch == 'W') x-=n;
              }
         }
         cout<<fixed<<setprecision(3)<<"Map #"<<con
         <<endl<<"The treasure is located at ("<<x<<","<<y<<
         ")."<<endl<<"The distance to the treasure is "<<hypot(x,y)<<"."<<endl<<endl;
     }
}
