#include<bits/stdc++.h>

#define int long long
using namespace std;

const int MOD = 1e9 + 7;
vector<int> h1, p1;

void hash1(const string &s) {
    int n = s.size();
    h1.resize(n + 1);
    p1.resize(n + 1);
    int p11 = 29;

    h1[0] = 0;
    p1[0] = 1;

    for (int i = 1; i <= n; i++) {
        p1[i] = (p1[i-1]*p11)%MOD;
        h1[i] = (h1[i-1]+(s[i-1]-'a'+1)*p1[i])%MOD;
    }
}

int binpow(int a, int b, int m) {
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int inversoFermat(int a, int m) {
    return binpow(a, m - 2, m);
}

signed main() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    hash1(s);
    while (q--) {
        int l, r;cin>>l>>r;
        int cad1 = ((h1[r]-h1[l]+MOD)%MOD*inversoFermat(p1[l],MOD))%MOD;
        cout<<cad1;
    }
    return 0;
}