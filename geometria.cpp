#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

const double EPS = 1e-9;

typedef long long T;
struct Punto {
    T x, y;
    Punto(){}
    Punto(T x1, T y2){
          x = x1;
          y = y2;
    }
    bool operator<(const Punto &other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
    Punto operator-(const Punto &other) const {
        return {x - other.x, y - other.y};
    }
};

T cross(Punto a, Punto b){
    return (a.x*b.y-a.y*b.x);
}
 
T orient(Punto a, Punto b, Punto c){
    //Negativo, si c derecha de a-b
    //Positivo si c izquierda de a-b
    //Cero si son colinealess
    return cross(b-a,c-a);
}

bool eq(double a, double b){
     return fabs(a-b) < EPS;
}
bool mayor(double a, double b){
     return a > b + EPS;
}

bool menor(double a, double b){
    return a < b-EPS; 
}
double dist(Punto a, Punto b){
  return hypot(a.x-b.x, a.y-b.y);
}
 
struct line{
    double a,b,c; 
    line(Punto p, Punto q){
         a = p.y-q.y;
         b = q.x-p.x;
         c = -a*p.x - b*p.y;
    }
    void setOrigin(Punto p){
        c+=a*p.x+b*p.y;
    }
};

double det(double a, double b, double c, double d){
    return a*d - b*c;
}
Punto intersec(line a, line b){
      //primero verificar que no sean paralelas
      double d = -det(a.a, a.b, b.a, b.b);
      double comX = det(a.c,a.b,b.c,b.b)/d;
      double comY = det(a.a,a.c,b.a,b.c)/d;
      Punto interL = {comX, comY};
      return interL;
}

Punto rotate(Punto v, double theta){
      theta *= acos(-1)/180.0;
      return Punto(v.x*cos(theta)-v.y*sin(theta), v.x*sin(theta)+v.y*cos(theta));
}
vector< Punto > convex_hull( vector< Punto > v ){
  sort( v.begin(), v.end() );//remove repeated points if needed
  const int n = v.size();
  if( n < 3 ) return v;
  vector< Punto > ch( 2 * n );

  int k = 0;
  for( int i = 0; i < n; ++ i ) {
    while( k > 1 && orient( ch[k-2], ch[k-1], v[i] ) > 0 )
      --k;
    ch[k++] = v[i];
  }

  const int t = k;
  for( int i = n - 2; i >= 0; -- i ) {
    while( k > t && orient( ch[k-2], ch[k-1], v[i] ) > 0 )
      --k;
    ch[k++] = v[i];
  }
  ch.resize( k - 1 );
  return ch;
}
 
bool onSegment(Punto a, Punto b, Punto p) {
    //verifica si el punto p esta en el segmento
    return orient(a, b, p) == 0 &&
           min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
           min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
}

 int verificar(vector<Punto> &p, Punto puntin) {
    int n = p.size();
    bool inside = false;
    for (int i = 0; i < n - 1; i++) {
        if (onSegment(p[i], p[i + 1], puntin)) {
            return 2; 
        }

        Punto a = p[i], b = p[i + 1];
        if ((a.y > puntin.y) != (b.y > puntin.y)) {
            int det = (puntin.x - a.x) * (b.y - a.y) - (b.x - a.x) * (puntin.y - a.y);
            if (det == 0) return 2; 
            if ((b.y > a.y) != (det > 0)) {
                inside = !inside;
            }
        }
    }
    return inside ? 1 : 0; 
    //1 inside 
    //0 outside
}


long long min_Distance(vector<Punto> pts){
    //min_Distance two points 
    int n = pts.size();
    sort(pts.begin(), pts.end());
    set<pair<int, int>> s;

    long long best_dist = 1e20;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        int d = ceil(sqrt(best_dist));
        while (pts[i].x - pts[j].x >= d) {
            s.erase({pts[j].y, pts[j].x});
            j += 1;
        }

        auto it1 = s.lower_bound({pts[i].y - d, pts[i].x});
        auto it2 = s.upper_bound({pts[i].y + d, pts[i].x});
        
        for (auto it = it1; it != it2; ++it) {
            int dx = pts[i].x - it->second;
            int dy = pts[i].y - it->first;
            best_dist = min(best_dist, 1LL * dx * dx + 1LL * dy * dy);      
        } 
        s.insert({pts[i].y, pts[i].x}); 
    }
    return best_dist;
}

signed main(){
    int n; cin>>n;
    vector<Punto> p(n);
    for(int i = 0; i <  n; i++){
        cin>>p[i].x>>p[i].y;
        }
    cout<<min_Distance(p);
    return 0;
}
