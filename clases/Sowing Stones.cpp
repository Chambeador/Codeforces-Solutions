#include <bits/stdc++.h>
#define int long long
using namespace std;

int gauss(int x) {
    return (x * (x + 1)) / 2LL; 
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> posiciones(m);
    vector<int> cantidad(m);
    for (int i = 0; i < m; i++) cin >> posiciones[i];

    int sumita = 0;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        sumita += x;
        cantidad[i] = x - 1; 
    }
    if (sumita != n) {
        cout << -1 << endl;
        return;
    }

    vector<pair<int, int>> pares(m);
    for (int i = 0; i < m; i++) {
        pares[i] = {posiciones[i], cantidad[i]};
    }
    sort(pares.begin(), pares.end());

    int ans = 0;

    if (pares[0].first != 1) {
        cout << -1 << endl;
        return;
    } else {
        for (int i = 1; i < (int)pares.size(); i++) {
            int dif = pares[i].first - pares[i - 1].first - 1;
            if (pares[i - 1].second >= dif) {
                ans += gauss(dif);
                int sobrante = pares[i - 1].second - dif;
                ans += sobrante * (dif + 1);
                pares[i].second += sobrante;
                pares[i - 1].second = 0;
            } else {
                cout << -1 << endl;
                return;
            }
        }

        if (pares[m - 1].first != n) {
            int dif = n - pares[m - 1].first;
            if (pares[m - 1].second == dif) {
                ans += gauss(dif);
            } else {
                cout << -1 << endl;
                return;
            }
        }

        cout << ans << endl;
    }
}

signed main() {
    solve();
    return 0;
}
