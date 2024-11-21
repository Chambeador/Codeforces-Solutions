#include <bits/stdc++.h>
#define int long long
using namespace std;
 
 
vector<int> topSort(vector<vector<int>> &g, vector<int> & in){
      int n = in.size();
      vector<int> topo;
      queue<int> q;
      for(int i = 0; i < n; i++){
          if(in[i] == 0){
             q.push(i);
          }
      }
      while(!q.empty()){
           int node = q.front(); q.pop();
           topo.push_back(node);
           for(int x: g[node]){
               if(--in[x] == 0){
                   q.push(x);
               }
           }
      }
      return topo;
}
int bb(int x, vector<int> & arr){
    int pos = -1;
    int l = 0, r = arr.size()-1;
    while(l <= r){
        int m = l + (r-l)/2;
        if(arr[m] == x){
           pos = m;
           break;
        }else if(arr[m] > x){
           r = m-1;
        }else l = m+1;
    }
    return pos;
}
void solve(){
     int n; cin>>n; 
     vector<int> arr(n);
     for(int i = 0; i < n; i++) cin>>arr[i];
     sort(arr.begin(), arr.end());
     vector<int> in(n);
     vector<vector<int>> g(n);
     for(int i = 0; i < n; i++){
         int pos = bb(arr[i]*2, arr);
         if(pos != -1){
         g[i].push_back(pos);
         in[pos]++;
         }
         if(arr[i]%3 == 0){
            pos = bb(arr[i]/3, arr);
            if(pos != -1){
               g[i].push_back(pos);
               in[pos]++;
            }  
         }
     }
     vector<int> topito = topSort(g, in);
     for(auto x: topito){
         cout<<arr[x]<<" ";
     }
 
}
 
signed main() {
    //int t; cin>>t;while(t--)
    solve();
    return 0;
}