#include<bits/stdc++.h>

using namespace std;


class Trie{
   private:
    bool terminal;
    map<char, Trie*> hijos;
    Trie *nodoEscape;
    set<string> patrones;
   public :
   Trie(){
       terminal = false;
       hijos = {};
       nodoEscape = nullptr;
       patrones  = {};
   }   
   void insertar(string &cadena){
        Trie *act = this;
        int n = (int)(cadena.size());
        for(int i = 0; i < n; i++){
            char c = cadena[i];
            if(act->hijos.find(c) == act->hijos.end()){
               Trie *aux = new Trie();
               act->hijos[c] = aux;
               act = act->hijos[c];
            }else{
               act = act->hijos[c];
            }
        }
        act->terminal = true;
        act->patrones.insert(cadena);

   }
   //conmstruir nodos fallidos
   void build(){
       Trie *act = this;
       queue<Trie*> cola;
       for(auto &x: act->hijos){
           //este x es un par que tiene caracter e hijos
           cola.push(x.second);
           Trie *hijo = x.second;
           //no olvidar referencia a un atributo con la flechita
           hijo->nodoEscape = this;
       }

       while(!cola.empty()){
          act = cola.front();
          cola.pop();
          //nodo escape a mis hijos
          for(auto &x: act->hijos){
              //tengo a mi hijo x aqui 
              char ch = x.first;
              Trie *hijo = x.second;
              Trie *escapeAct = act->nodoEscape;
              //si no es nulo
              while(escapeAct && escapeAct->hijos.find(ch) ==escapeAct->hijos.end()){
                    escapeAct = escapeAct->nodoEscape;
              }
              //no es nulo
              if(escapeAct){
                 hijo->nodoEscape = escapeAct->hijos[ch];
              }else{
                 hijo->nodoEscape = this;
              } 
              Trie *nodoEscapeHijo = hijo->nodoEscape;
              if(nodoEscapeHijo && !nodoEscapeHijo->patrones.empty()){
                //si el escape de mi hijo no es nulo y tiene patrones lo pongo en los patrones de mi hijo 
                 hijo->patrones.insert(nodoEscapeHijo->patrones.begin(),nodoEscapeHijo->patrones.end());
              }
              cola.push(hijo);
              
          }
       }
   } 

   map<string, set<int>> buscarPatrones(string &texto){
      map<string, set<int>> mapita;
      Trie *act = this;
      int n = (int)(texto.size());
      for(int i = 0; i < n; i++){
          char ch = texto[i];
          //tengo el caracter y voy a buscar patrones
          while(act && act->hijos.find(ch) == act->hijos.end()){
                act = act->nodoEscape;
          }
          //si no es nulo entra
          if(act){
             act = act->hijos[ch];
          }else{
             act = this;
          }
          if(!act->patrones.empty()){
            for(auto& x: act->patrones){
                mapita[x].insert(i-x.size()+1);
            }
          }
      }
      return mapita;
   }
};

void solve(){
     int n; 
     while(cin>>n){
        vector<string> patrones1;
        string s;
        cin.ignore();
        Trie arbol;
        for(int i = 0; i < n; i++){
            getline(cin, s);
            arbol.insertar(s);
            patrones1.push_back(s);
        }
        string t; 
        getline(cin, t);
        arbol.build();
        map<string, set<int>> ans = arbol.buscarPatrones(t);
        for(int i = 0; i < n; i++){
            set<int> aux = ans[patrones1[i]];
            for(auto y: aux){
                cout<<y<<" ";
            }
            cout<<endl;
        }
     }
}

signed main(){
     
     solve();
}