#include <bits/stdc++.h>
#define int long long
using namespace std;

struct nodo {
    nodo* hijos[2];
    int canh;
    nodo() {
        canh = 0;
        hijos[0] = hijos[1] = NULL;
    }
};

nodo* raiz = new nodo();

void insertar(int x) {
    nodo* aux = raiz;
    for (int i = 63; i >= 0; i--) {
        int bit = (x >> i) & 1;
        if (aux->hijos[bit] == NULL) {
            aux->hijos[bit] = new nodo();
        }
        aux = aux->hijos[bit];
    }
}

int xoor(int x) {
    int resultado = 0;
    nodo* aux = raiz;
    for (int i = 63; i >= 0; i--) {
        int bit = (x >> i) & 1;
        if (aux->hijos[!bit] != NULL) {
            resultado |= (1LL << i);
            aux = aux->hijos[!bit];
        } else if (aux->hijos[bit] != NULL) {
            aux = aux->hijos[bit];
        }
    }
    return resultado;
}

void solve() {
    int q;
    cin >> q;
    vector<int> nums;
    
    while (q--) {
        int x;
        cin >> x;
        insertar(x);
        nums.push_back(x);
    }
    
    int ans = 0;
    for (int i = 0; i < nums.size(); i++) {
        ans = max(ans, xoor(nums[i]));
    }
    cout << ans << endl;
}

signed main() {
    solve();
    return 0;
}
