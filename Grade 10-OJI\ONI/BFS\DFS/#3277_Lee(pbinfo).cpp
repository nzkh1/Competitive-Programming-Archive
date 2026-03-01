#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, a[101][101];
int b[5][101][101]; 
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
struct Point {
    int x, y;
};
bool inmat(int i, int j) {
    return i >= 1 && j >= 1 && i <= n && j <= n;
}
void lee(int k, int istart, int jstart) {
    queue<pair<int, int>> Q;
    Q.push({istart, jstart});
    b[k][istart][jstart] = 1;
  
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int d = 0; d < 4; d++) {
            int inou = dx[d] + x;
            int jnou = dy[d] + y;

            if (inmat(inou, jnou) && a[inou][jnou] == 0 && b[k][inou][jnou] == 0) {
                b[k][inou][jnou] = b[k][x][y] + 1;
                Q.push({inou, jnou});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    Point p[5];
    p[0] = {1, 1};
    cin >> p[1].x >> p[1].y;
    cin >> p[2].x >> p[2].y;
    cin >> p[3].x >> p[3].y;
    p[4] = {n, n};

    for (int k = 0; k < 5; k++) {
        lee(k, p[k].x, p[k].y);
    }
    vector<int> order = {1, 2, 3};
    long long min_total = -1;

    do {
        long long current_sum = 0;
        bool possible = true;
        int path[] = {0, order[0], order[1], order[2], 4};

        for (int i = 0; i < 4; i++) {
            int start_idx = path[i];
            int target_x = p[path[i+1]].x;
            int target_y = p[path[i+1]].y;

            int dist = b[start_idx][target_x][target_y];
            if (dist == 0) {
                possible = false;
                break;
            }
            current_sum += (dist - 1);
        }

        if (possible) {
            if (min_total == -1 || current_sum < min_total)
                min_total = current_sum;
        }
    } while (next_permutation(order.begin(), order.end()));

    cout << min_total;
    return 0;
}
