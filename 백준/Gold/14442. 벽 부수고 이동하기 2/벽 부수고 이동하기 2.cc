#include <bits/stdc++.h>
#define endl '\n'
#define X first
#define Y second
#define MAX 1000000000
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, m, k;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
char board[1005][1005];
int dist[1005][1005][12];

bool OutOfBound(int x, int y){
    return x < 0 || x >= n || y < 0 || y >= m;
}

inline int bfs(){
    memset(dist, -1, sizeof(dist));
    dist[0][0][0] = 1;
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    while(!q.empty()){
        int x, y, broken;
        tie(x, y, broken) = q.front(); q.pop();
        if(x == n-1 && y == m-1) return  dist[x][y][broken];
        int nextdist = dist[x][y][broken] + 1;
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(OutOfBound(nx, ny)) continue;
            if(broken < k && board[nx][ny] == '1' && dist[nx][ny][broken+1] == -1){
                dist[nx][ny][broken+1] = nextdist;
                q.push({nx, ny, broken+1});
            }
            if(board[nx][ny] == '0' && dist[nx][ny][broken] == -1){
                dist[nx][ny][broken] = nextdist;
                q.push({nx, ny, broken});
            }
        }
    }
    return -1;
}

int main() {
    fastio;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    cout << bfs() << endl;
}