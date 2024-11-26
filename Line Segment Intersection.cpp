#include <bits/stdc++.h>
#define int long long
using namespace std;
double const esp = 1e-9;

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

bool compare(double a, double b){
     return fabs(a-b) < esp;
}
double pendiente(Punto p1, Punto p2){
       return (p2.y-p1.y)/(p2.x-p1.x);
}
void solve(){
     vector<Punto> p(4);
     for(int i = 0; i< 4; i++){
        cin>>p[i].x>>p[i].y;
     }
     if(compare(pendiente(p[0], p[1]), pendiente(p[2], p[3]))){
        cout<<"YES"<<endl;
     }else{
        cout<<"NO"<<endl;
     }
}

signed main(){
     int t; cin>>t; while(t--)
     solve();
     return 0;
}

//Sofocado por el sueño y la presion, pronta entrega porfavor