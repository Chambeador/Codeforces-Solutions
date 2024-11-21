#include <bits/stdc++.h>
 
#define int long long
using namespace std;

vector<int> st2;  
string s;
int n;

void build(int v = 1, int l = 0, int r = n - 1) {
    if (l == r) {
        st2[v] = 1LL << (s[l] - 'a'); 
    } else {
        int m = (l + r) / 2;
        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);
        st2[v] = st2[v * 2] | st2[v * 2 + 1]; 
    }
}
 
void update(int idx, char value, int v = 1, int l = 0, int r = n - 1) {
    if (l == r) {
        st2[v] = 1LL << (value - 'a');  
    } else {
        int m = (l + r) / 2;
        if (idx <= m) {
            update(idx, value, v * 2, l, m);
        } else {
            update(idx, value, v * 2 + 1, m + 1, r);
        }
        st2[v] = st2[v * 2] | st2[v * 2 + 1];  
    }
}
 
int query(int l, int r, int v = 1, int sl = 0, int sr = n - 1) {
    if (sl > r || sr < l) {
        return 0;  //neutro del or
    }
    if (sl >= l && sr <= r) {
        return st2[v]; 
    }
    int m = (sl + sr) / 2;
    return query(l, r, v * 2, sl, m) | query(l, r, v * 2 + 1, m + 1, sr);  // Unión de las máscaras
}
 

void solve() {
    cin >> s;
    n = s.size();
    st2.resize(4 * n);  
    build();
    
    int q; cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t == 1){
            int l;
            char c; cin >> l >> c;
            update(l - 1, c); 
        } else {
            int l, r; cin >> l >> r;
            int result = query(l - 1, r - 1);
            int ans12 =  __builtin_popcountll(result);
            cout<<ans12<<endl;
        }
    }
}
 
signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}