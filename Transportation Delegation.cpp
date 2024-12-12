#include <bits/stdc++.h>
#define int long long
using namespace std;

bool bfs(vector<vector<int>> &g, int s, int t, vector<int> &p) {
    vector<bool> vis(g.size(), false);
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < g.size(); v++) {
            if (!vis[v] && g[u][v] > 0) {  
                vis[v] = true;
                p[v] = u;  
                if (v == t) return true;
                q.push(v);
            }
        }
    }
    return false;
}

int edmond(vector<vector<int>> &g, int n) {
    vector<int> p(n, -1);
    int ans = 0;

    while (bfs(g, 0, n - 1, p)) {
        int x = n - 1;
        int flowActual = LLONG_MAX;

        // Encuentra la capacidad mínima del camino
        while (p[x] != -1) {
            flowActual = min(flowActual, g[p[x]][x]);
            x = p[x];
        }

        ans += flowActual;

        // Actualiza las capacidades hacia adelante y residuales
        x = n - 1;
        while (p[x] != -1) {
            g[p[x]][x] -= flowActual; // Reducir capacidad hacia adelante
            g[x][p[x]] += flowActual; // Incrementar capacidad residual
            x = p[x];
        }
    }

    return ans;
}

void solve() {
    int s, r, f, t;
    cin >> s >> r >> f >> t;

    map<string, int> estados;
    set<string> prov, fabri;
    vector<int> provs, fabris;
    vector<vector<int>> g(3000, vector<int>(3000, 0)); // Tamaño suficientemente grande

    int index = 1;
    for (int i = 0; i < r; i++) {
        string x;
        cin >> x;
        prov.insert(x);
        provs.push_back(index);
        estados[x] = index++;
    }

    for (int i = 0; i < f; i++) {
        string x;
        cin >> x;
        fabri.insert(x);
        fabris.push_back(index);
        estados[x] = index++;
    }

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<int> u, v, w;

        for (int j = 0; j < n; j++) {
            string x;
            cin >> x;
            if (estados.find(x) == estados.end()) {
                estados[x] = index++;
            }
            if (prov.count(x)) {
                u.push_back(estados[x]);
            } else if (fabri.count(x)) {
                v.push_back(estados[x]);
            } else {
                w.push_back(estados[x]);
            }
        }

        for (auto z : u) {
            for (auto k : v) {
                g[z][k] = 1;
            }
        }
        for (auto z : u) {
            for (auto k : w) {
                g[z][k] = 1;
            }
        }
        for (auto z : w) {
            for (auto k : v) {
                g[z][k] = 1;
            }
        }
    }

    // Conectar los proveedores a la fuente (nodo 0)
    for (auto x : provs) {
        g[0][x] = 1;
    }

    // Conectar los fábricas al sumidero (nodo index)
    for (auto x : fabris) {
        g[x][index] = 1;
    }

    // Ejecutar el algoritmo de flujo máximo
    cout << edmond(g, index + 1) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    solve();
    return 0;
}
