#include <bits/stdc++.h>
using namespace std;

string s, t;
int memo[5010][5010];

int dp() {
    int n = s.size();
    int m = t.size();

    // Inicializar bordes de la matriz
    for (int i = 0; i <= n; i++) memo[i][0] = i;
    for (int j = 0; j <= m; j++) memo[0][j] = j;

    // Rellenar la matriz DP
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cost = (s[i - 1] != t[j - 1]);
            memo[i][j] = min({
                memo[i - 1][j] + 1,       // Eliminación
                memo[i][j - 1] + 1,       // Inserción
                memo[i - 1][j - 1] + cost // Sustitución
            });
        }
    }

    return memo[n][m];
}

void reconstruct() {
    int i = s.size();
    int j = t.size();
    vector<string> operations;
    vector<int> pos_i; 
    vector<int> pos_j; 

    while (i > 0 || j > 0) {
        if (i > 0 && memo[i][j] == memo[i - 1][j] + 1) {
            // Eliminación
            operations.push_back("Eliminación de '" + string(1, s[i - 1]) + "'");
            pos_i.push_back(i);
            pos_j.push_back(j);
            i--; // Retrocede en la cadena `s`
        } else if (j > 0 && memo[i][j] == memo[i][j - 1] + 1) {
            // Inserción
            operations.push_back("Inserción de '" + string(1, t[j - 1]) + "'");
            pos_i.push_back(i);
            pos_j.push_back(j);
            j--; // Retrocede en la cadena `t`
        } else {
            // Sustitución o mantener el carácter (sin cambio)
            if (i > 0 && j > 0) {
                if (s[i - 1] != t[j - 1]) {
                    operations.push_back("Sustitución de '" + string(1, s[i - 1]) + "' por '" + string(1, t[j - 1]) + "'");
                    pos_i.push_back(i);
                    pos_j.push_back(j);
                }
            }
            i--;
            j--;
        }
    }

    // Invertir para mostrar las operaciones en el orden correcto
    reverse(operations.begin(), operations.end());
    reverse(pos_i.begin(), pos_i.end());
    reverse(pos_j.begin(), pos_j.end());

    // Mostrar las operaciones
    for (int k = 0; k < operations.size(); k++) {
        cout << operations[k] << " en posición (s: " << pos_i[k] << ", t: " << pos_j[k] << ")" << endl;
    }
}

void solve() {
    cin >> s >> t;
    cout <<dp() << endl;
    reconstruct();
}

int main() {
    solve();
    return 0;
}
