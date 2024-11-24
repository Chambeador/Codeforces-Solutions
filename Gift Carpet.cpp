#include <bits/stdc++.h>
#define int long long
using namespace std;
 


void solve(){
    int n, m; cin>>n>> m;
    vector<vector<char>>mat(n, vector<char>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    string s = "vika";  
    int indice = 0;     
    int c = 0; 

    for(int j = 0; j < m && indice < (int)s.size(); j++){
       // cout<<s[indice]<<endl;
        for(int i = 0; i < n; i++){
            if(mat[i][j] == s[indice]){
                indice++;  
                //cout<<"entre aqui sig fila"<<endl;
                c++;
                break; 
            }
        }
    }

    if(c == s.size())cout << "YES" << endl;  
     else cout << "NO" << endl;  
}
signed main(){
     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}