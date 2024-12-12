
#include <bits/stdc++.h>
#define int long long
using namespace std;



bool bfs(vector<set<pair<int, int>>> &g, int s, int t, vector<int> &p){
    vector<bool> vis((int)g.size(), false);
    queue<int> q;
    q.push(s);
    vis[s] = true;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        for(auto x: g[u]){
            if(vis[x.first] == 0 && x.second > 0){
                vis[x.first] = true;
                p[x.first] = u; // Actualizar predecesor
                if(x.first == t){
                    return true;
                }
                q.push(x.first);
            }
        }
    }
    return false; 
}


int edmond(vector<set<pair<int, int>>> &g, vector<int> & arr){
    int n = (int) g.size();
    vector<int> p(n, -1);
    int ans = 0;
    while(bfs(g, 0, n-1, p)){
          int x = n-1;
          int flowActual = 1e18;
          while(p[x] != -1){
                int flujo = 0;
                for(auto elem : g[x]){
                    if(elem.first == p[x]){
                       flujo = elem.second;
                    }
                }
                flowActual = min(flowActual, flujo);
                x = p[x];
          }
          //cout<<"flujo actual "<<flowActual<<endl;
          ans += flowActual;
          //actualizar las capacidades
          //{-1, 0, 0, 2}
          x = n-1;
         while (p[x] != -1) {
                // Nodo x
                for (auto &w : g[p[x]]) {
                    if (w.first == x) {
                        // Eliminar el par antiguo y agregar el actualizado
                        g[p[x]].erase(w);
                        g[p[x]].insert({w.first, w.second - flowActual});
                        break; // Ya no es necesario seguir buscando una vez modificado
                    }
                }

                for (auto &u : g[x]) {
                    if (u.first == p[x]) {
                        // Eliminar el par antiguo y agregar el actualizado
                        g[x].erase(u);
                        g[x].insert({u.first, u.second - flowActual});
                        break; // Ya no es necesario seguir buscando una vez modificado
                    }
                }

                  x = p[x];
           }

          
    }
    return ans;
}


void solve(){
      int n; cin>>n;
      vector<int> arr(n);
      for(int i = 0; i < n; i++){
          cin>>arr[i];
      }
      sort(arr.begin(), arr.end());
      vector<set<pair<int, int>>> g(n);
      for(int i = 0; i < n; i++){
          for(int j = i+1; j < n; j++){
              int x = __gcd(arr[i], arr[j]);
              if(x != 1){
                 g[i].insert({j, x});
                 g[j].insert({i,x});

              }
          }
      }
      //ya tengo el grafo
      cout<<edmond(g, arr);

}

signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    //int t;cin >> t;while (t--)
     solve();
    return 0;
}

/*
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

int edmond(vector<vector<int>> &g, vector<int> &arr) {
    int n = g.size();
    vector<int> p(n, -1);
    int ans = 0;

    while (bfs(g, 0, n - 1, p)) {
        int x = n - 1;
        int flowActual = 1e18;
        
        while (p[x] != -1) {
            int flujo = g[p[x]][x];
            flowActual = min(flowActual, flujo);
            x = p[x];
        }

        ans += flowActual;
        x = n - 1;
        while (p[x] != -1) {
            g[p[x]][x] -= flowActual;
            g[x][p[x]] += flowActual;
            x = p[x];
        }
    }

    return ans;
}

void solve() {
    int n; 
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<vector<int>> g(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = __gcd(arr[i], arr[j]);
            if (x != 1) {
                g[i][j] = x;
                g[j][i] = x;
            }
        }
    }
    
    cout<<edmond(g, arr) << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    solve();
    return 0;
}
*/
