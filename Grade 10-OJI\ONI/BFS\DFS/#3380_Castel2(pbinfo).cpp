#include <iostream>
#include <fstream>
#include <queue>
#include <cmath>
#include <string>
using namespace std;
ifstream fin("castel2.in");
ofstream fout("castel2.out");
int n, m, k;
char a[1001][1001];
int distZ[1001][1001];
int dist[1001][1001];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
struct point { 
int x, y;
};
bool inmat(int i, int j) {
    return i >= 1 && j >= 1 && i <= n && j <= m;
}
int main() {
    fin >> n >> m >> k;
    queue<point> qZ;
    for(int i = 1; i <= n; i++) {
        string row;
        fin >> row;
        for(int j = 1; j <= m; j++) {
            a[i][j] = row[j-1];
            distZ[i][j] = -1;
            dist[i][j] = -1;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] == 'Z') {
                distZ[i][j] = 0;
                point p; p.x = i; p.y = j;
                qZ.push(p);
            }
        }
    }

    while(!qZ.empty()) {
        point curr = qZ.front();
        qZ.pop();

        if(distZ[curr.x][curr.y] >= k) continue;

        for(int d = 0; d < 4; d++) {
            int inou = curr.x + dx[d];
            int jnou = curr.y + dy[d];

            if(inmat(inou, jnou) && a[inou][jnou] != '#' && distZ[inou][jnou] == -1) {
                distZ[inou][jnou] = distZ[curr.x][curr.y] + 1;
                point p; p.x = inou; p.y = jnou;
                qZ.push(p);
            }
        }
    }
    auto blocked = [&](int i, int j) {
        if(a[i][j] == '#') return true;
        if(a[i][j] == 'Z') return true;
        if(distZ[i][j] != -1) return true;
        return false;
    };

    if(blocked(1,1) || blocked(n,m)) {
        fout << -1;
        return 0;
    }

    point st; st.x = 1; st.y = 1;
    dist[1][1] = 0;
    queue<point> q;
    q.push(st);

    while(!q.empty()) {
        point curr = q.front();
        q.pop();

        if(curr.x == n && curr.y == m) {
            fout << dist[n][m] + 1;
            return 0;
        }

        for(int d = 0; d < 4; d++) {
            int inou = curr.x + dx[d];
            int jnou = curr.y + dy[d];

            if(inmat(inou, jnou) && !blocked(inou, jnou) && dist[inou][jnou] == -1) {
                dist[inou][jnou] = dist[curr.x][curr.y] + 1;
                point p; p.x = inou; p.y = jnou;
                q.push(p);
            }
        }
    }

    fout << -1;
    return 0;
}
