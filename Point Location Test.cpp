#include <bits/stdc++.h>
#define int long long
using namespace std;

//convex hull monotone chain algorithm 
struct Punto{
     int x,y;
     bool operator < (const Punto &other) const {
            return x < other.x || (x == other.x && y < other.y);
     }
     Punto operator - (const Punto &other) const {
       return {x - other.x, y - other.y};
     }
};
int cross(Punto a, Punto b){
    return (a.x*b.y-a.y*b.x);
}

int orient(Punto a, Punto b, Punto c){
    //Negativo, si c derecha de a-b
    //Positivo si c izquierda de a-b
    //Cero si son colinealess
    return cross(b-a,c-a);
}

void convexHull(){
     int n; cin>>n;
     vector<Punto> p(n);
     for(int i = 0; i < n; i++){
         cin>>p[i].x>>p[i].y;
     }
     sort(p.begin(), p.end());
     vector<Punto> ch;
     for(int it = 0; it < 2; it++){
        int k = 0;
        int ori = ch.size();
        for(int i = 0; i < n; i++){
            while(k-ori >= 2 && orient(ch[k-2], ch[k-1], p[i]) > 0){ 
                 //hay un giro a la izquierda -> Borrar el last no sirve
                 ch.pop_back();
                 k--;
            }
            ch.push_back(p[i]);
            k++;
        }
        ch.pop_back();
        k--;
        reverse(p.begin(), p.end());
     }
}

void solve(){
     vector<Punto> p(3);
     for(int i = 0; i< 3; i++){
        cin>>p[i].x>>p[i].y;
     }
     int ans = orient(p[0], p[1], p[2]);
     if(ans == 0){
        cout<<"TOUCH"<<endl;
     }else if (ans < 0){
        //c a la derecha de a-b
        cout<<"RIGHT"<<endl;
     }else{
        cout<<"LEFT"<<endl;
          //c a la izquierda de a-b
     }


}

signed main(){
     int t; cin>>t; while(t--)
     solve();
     return 0;
}

//Sofocado por el sueño y la presion, pronta entrega porfavor