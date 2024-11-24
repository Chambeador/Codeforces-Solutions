#include <bits/stdc++.h>
#define int long long
using namespace std;
 


void solve() {
    vector<int> arr(101, 0); 
    int n; cin >> n;
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        arr[x]++;
        maxi = max(maxi, x);
    }
    

    bool bandera = false; 
    for (int i = 0; i <= maxi; i++) {
        if (arr[i] > 0 && bandera) {
           
            cout<<"NO"<<endl;
            return;
        }

        if (i > 0 && arr[i] > arr[i - 1]) {
           
            cout<<"NO"<<endl;
            return;
        }
        if (arr[i] == 0) bandera = true;
    }

    cout << "YES\n";
}
signed main(){
     ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t; while(t--)
    solve();
    return 0;
}