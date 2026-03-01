#include <iostream>
#include <queue>

using namespace std;

int n, m;
char a[1001][1001];
int dist[1001][1001];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
struct Point { int x, y; };

bool inmat(int i, int j) {
    return i >= 1 && j >= 1 && i <= n && j <= m;
}
int lee(Point start, Point end) {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) dist[i][j] = -1;
    queue<Point> q;
    q.push(start);
    dist[start.x][start.y] = 0;

    while(!q.empty()) {
        Point curr = q.front();
        q.pop();

        if(curr.x == end.x && curr.y == end.y) return dist[curr.x][curr.y];

        for(int d = 0; d < 4; d++) {
            int inou = curr.x + dx[d];
            int jnou = curr.y + dy[d];

            if(inmat(inou, jnou) && a[inou][jnou] != '#' && dist[inou][jnou] == -1) {
                dist[inou][jnou] = dist[curr.x][curr.y] + 1;
                q.push({inou, jnou});
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Point A, M, G;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'A') A = {i, j};
            else if(a[i][j] == 'M') M = {i, j};
            else if(a[i][j] == 'G') G = {i, j};
        }
    }
    int d1 = lee(A, M);
    int d2 = lee(M, G);
    if(d1 == -1 || d2 == -1) cout << -1;
    else cout << d1 + d2;
    return 0;
}
