#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Trie{
      map<char,Trie*>hijos;
      bool terminal;
      int cant,repeticiones;
      Trie(){
         repeticiones = cant  = 0;
         terminal = false;
         hijos = {};
      }
};

void insertar(string &s, Trie* raiz){
     Trie* actual = raiz;
     int n = (int)s.size();
     for(int i = 0; i < n; i++){
        char c = s[i];
        if(actual->hijos.find(c) == actual->hijos.end()){
           actual->hijos[c] = new Trie();
        }
        actual = actual->hijos[c];
        actual->cant++;
     }
     actual->terminal = true;
     actual->repeticiones++;
}

bool buscar(string &s, Trie* raiz){
     Trie* actual = raiz;
     for(auto c: s){
         if(actual->hijos.find(c) == actual->hijos.end()){
            return false;
         }
         actual = actual->hijos[c];
     }
     return actual->terminal;
}

bool eliminar(string &s, int pos, Trie* raiz) {
    if (pos == s.size()) {
        raiz->repeticiones--; 
        if (raiz->repeticiones == 0) {
            raiz->terminal = false;
        }
        raiz->cant--; 
        return raiz->cant == 0;
    }
    
    char c = s[pos];
    Trie* sig = raiz->hijos[c];
    bool debeEliminar = eliminar(s, pos + 1, sig);
    if (debeEliminar) {
        delete sig; 
        raiz->hijos.erase(c);
    }

    raiz->cant--;
    return raiz->cant == 0 && !raiz->terminal && raiz->hijos.empty();
}



void solve(){
     Trie* raiz = new Trie();
    
}
signed main(){
    solve();
    return 0;
}