#include <bits/stdc++.h>
 
using namespace std;
 

struct item{
     vector<int> hijos;
     bool final;
     item(){
         final = false;
         hijos.assign(26, 0);
     }
};
vector<item> trie;
void insertar(string &s){
    int pos = 0;
     for(int i = 0; i < (int)s.size(); i++){
        int ch = s[i]-'a';
        if(trie[pos].hijos[ch] == 0){
           trie[pos].hijos[ch] = trie.size();
           trie.push_back(item());
        }
        pos = trie[pos].hijos[ch];
     }
     trie[pos].final = true;
}

bool existe(string &s){
     int pos = 0;
     for(int i = 0; i < (int)s.size(); i++){
        int ch = s[i]-'a';
        if(trie[pos].hijos[ch] == 0) return false;
        pos = trie[pos].hijos[ch];
     }
     return trie[pos].final;
}


void solve(){
     trie.push_back(item());
     string s1 = "hola";
     insertar(s1);
     string s2 = "hola2";
     cout<<existe(s2)<<endl;
     cout<<existe(s1);

}
signed main(){
     solve();
}