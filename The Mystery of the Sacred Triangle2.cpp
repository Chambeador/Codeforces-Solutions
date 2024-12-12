#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Punto {
    int x, y;
    bool operator<(const Punto &other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
    Punto operator-(const Punto &other) const {
        return {x - other.x, y - other.y};
    }
};

int cross(const Punto &a, const Punto &b) {
    return a.x * b.y - a.y * b.x;
}

vector<Punto> hull(vector<Punto> &p) {
    int n = p.size();
    if (n <= 2) return p;
    sort(p.begin(), p.end());
    vector<Punto> h;
    // Parte inferior del hull
    for (int i = 0; i < n; i++) {
        while (h.size() >= 2 &&
               cross(h[h.size() - 1] - h[h.size() - 2], p[i] - h[h.size() - 1]) <= 0) {
            h.pop_back();
        }
        h.push_back(p[i]);
    }

    // Parte superior del hull
    int k = h.size();
    for (int i = n - 1; i >= 0; i--) {
        while (h.size() >= k + 2 &&
               cross(h[h.size() - 1] - h[h.size() - 2], p[i] - h[h.size() - 1]) <= 0) {
            h.pop_back();
        }
        h.push_back(p[i]);
    }

    h.pop_back(); 
    return h;
}

int area(vector<Punto> &ch) {
    int ans = 0;
    int n = ch.size();
    for (int i = 0; i < n; i++) {
        ans += ch[i].x * ch[(i + 1) % n].y - ch[i].y * ch[(i + 1) % n].x;
    }
    return abs(ans) / 2;
}

void solve(){
    int n = 3;
    vector<Punto> puntos;
    for (int i = 0; i < n; i++) {
        int x,y; cin>>x>>y;
        puntos.push_back({x,y});
        puntos.push_back({x,0});
    }

    vector<Punto> ch = hull(puntos);
    cout << area(ch) << endl;
}

signed main() {
    int t;cin >> t;while (t--) solve();
    return 0;
}
