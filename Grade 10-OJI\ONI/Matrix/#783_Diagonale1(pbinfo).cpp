#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    long long sum = 0;
    for (int i = 1; i < n; i++) {
        sum += matrix[i][i - 1];
        sum += matrix[i - 1][i];
    }
    cout << sum;
    return 0;
}
