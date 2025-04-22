#include <bits/stdc++.h>
#define int long long
using namespace std;
//hola uno dos tres
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

void convexHull() {
    int n; cin >> n;
    vector<Punto> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    sort(p.begin(), p.end());
    vector<Punto> ch;
    for (int it = 0; it < 2; it++) {
        int ori = ch.size();
        for (int i = 0; i < n; i++){
            while (ch.size() - ori >= 2 && orient(ch[ch.size() - 2], ch[ch.size() - 1], p[i]) > 0) {
                //giro a la izquierda entonces eliminar
                ch.pop_back();
            }
            ch.push_back(p[i]);
        }
        ch.pop_back();
        reverse(p.begin(), p.end());
    }

    cout << ch.size() << endl;
    for (auto &pt : ch) {
        cout << pt.x << " " << pt.y << endl;
    }
}



signed main(){
     convexHull();
     return 0;
}

//Sofocado por el sueño y la presion, pronta entrega porfavor