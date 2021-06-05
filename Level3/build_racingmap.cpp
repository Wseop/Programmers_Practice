// https://programmers.co.kr/learn/courses/30/lessons/67259?language=cpp#

#include <string>
#include <vector>
#include <queue>

using namespace std;

struct pos {
    int dir, x, y, cost;
};

const int INF = 987654321;

// BFS를 base로 cost까지 생각해야하는 문제
// 방향 전환 시, 전환 후 이동까지 하므로 500이 아닌 600을 더해주어야 함!
// 특정 좌표에 진입 시, 진입한 방향에 따라 cost가 다를 수 있으므로 queue에 들어갈 좌표 정보 각각이 자신의 cost를 기억하고 있어야 함
// (cost 비교 시, visited[ny][nx] vs (visited[y][x] + cost)가 아님!)
int solution(vector<vector<int>> board) {
    int answer = INF;
    queue<pos> q;
    int n = board.size();
    vector<vector<int>> visited(n, vector<int>(n, INF));
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    visited[0][0] = 0;
    q.push({1, 0, 0, 0});
    q.push({3, 0, 0, 0});

    while (!q.empty()) {
        pos p = q.front();
        int x = p.x;
        int y = p.y;
        int dir = p.dir;
        int cost = p.cost;

        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if ((nx >= 0) && (nx < n) && 
                (ny >= 0) && (ny < n) && 
                (board[ny][nx] == 0)) {
                if (i == dir) {
                   if (visited[ny][nx] >= (cost + 100)) {
                       visited[ny][nx] = (cost + 100);
                       q.push({i, nx, ny, cost + 100});
                   }
                } else {
                   if (visited[ny][nx] >= (cost + 600)) {
                       visited[ny][nx] = (cost + 600);
                       q.push({i, nx, ny, cost + 600});
                   }
                }
            }
        }
    }
    answer = visited[n - 1][n - 1];
    
    return answer;
}