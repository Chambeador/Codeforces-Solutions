#include <bits/stdc++.h>
#define int long long
using namespace std;
 
struct nodo {
    nodo* hijos[2];
    bool final;
    int canh;
    int contador;
    nodo() {
        contador = 0;
        canh = 0;
        final = false;
        for (int i = 0; i < 2; i++) {
            hijos[i] = NULL;
        }
    }
};
 
nodo* raiz = new nodo();
 
void insertar(string s) {
    nodo* aux = raiz;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i] - '0';
        if (aux->hijos[ch] == NULL) {
            aux->hijos[ch] = new nodo();
            aux->canh++;
        }
        aux = aux->hijos[ch];
        aux->contador++;
    }
    aux->final = true;
}
 
bool eliminar(string s, int pos, nodo* aux) {
    if (pos == s.size()) {
        aux->contador--;
        if (aux->contador == 0) {
            aux->final = false;
        }
        return aux->contador == 0;
    }
    char ch = s[pos] - '0';
    if (aux->hijos[ch] != NULL) {
        bool puedeEliminar = eliminar(s, pos + 1, aux->hijos[ch]);
 
        if (puedeEliminar) {
            delete aux->hijos[ch];
            aux->hijos[ch] = NULL;
            aux->canh--;
        }
        aux->contador--;
        return aux->canh == 0 && !aux->final && aux->contador == 0;
    }
    return false;
}
 
int xoor(string s) {
    int x = 0;
    nodo* aux = raiz;
    int j = 31;
    for (int i = 0; i < s.size(); i++) {
        char ch = s[i] - '0';
        if (aux->hijos[!ch] != NULL) {
            x |= (1 << j);
            aux = aux->hijos[!ch];
        } else if (aux->hijos[ch] != NULL) {
            aux = aux->hijos[ch];
        }
        j--;
    }
    return x;
}
 
void solve() {
    int q; cin >> q;
    int c1 = 0;
    while (q--) {
        char c;
        int x;
        cin >> c >> x;
        string aux = "";
        for (int i = 31; i >= 0; i--) {
            if (x & (1 << i)) {
                aux += '1';
            } else {
                aux += "0";
            }
        }
        if (c == '+') {
            c1++;
            insertar(aux);
        } else if (c == '-') {
            c1++;
            eliminar(aux, 0, raiz);
        } else {
            cout<<max(x, xoor(aux))<<endl;
            c1++;
        }
    }
}
 
signed main() {
    solve();
    return 0;
}