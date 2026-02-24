#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<vector<int>> matrix(n, vector<int>(n));
    int f1 = 1, f2 = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k = i * n + j + 1;
            if (k <= 2) {
                matrix[i][j] = 1;
            } else {
                int next = (f1 + f2) % 10;
                matrix[i][j] = next;
                f1 = f2;
                f2 = next;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << (j == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
