// https://programmers.co.kr/learn/courses/30/lessons/60063?language=cpp#

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Robot {
    int x, y;
    int state;
    int count;
};

bool visited[101][101][4];

bool IsAnswer(Robot& r, int n) {
    if ((r.x == n) && (r.y == n)) return true;
    else {
        switch (r.state) {
            case 0:
                if (((r.x + 1) == n) && (r.y == n)) return true;
                break;
            case 1:
                if ((r.x == n) && ((r.y + 1) == n)) return true;
                break;
            case 2:
                if (((r.x - 1) == n) && (r.y == n)) return true;
                break;
            case 3:
                if ((r.x == n) && ((r.y - 1) == n)) return true;
                break;
        }
    }
    return false;
}

bool CheckMove(vector<vector<int>>& board, int x, int y, int state, int move) {
    int n = board.size();

    switch (state) {
        case 0:
            switch (move) {
                case 0:
                    if (((x + 2) < n) && (board[y][x + 2] == 0) && !visited[y][x + 1][state]) {
                        visited[y][x + 1][state] = true;
                        return true;
                    }
                    break;
                case 1:
                    if (((y + 1) < n) && (board[y + 1][x] == 0) && (board[y + 1][x + 1] == 0) && !visited[y + 1][x][state]) {
                        visited[y + 1][x][state] = true;
                        return true;
                    }
                    break;
                case 2:
                    if (((x - 1) >= 0) && (board[y][x - 1] == 0) && !visited[y][x - 1][state]) {
                        visited[y][x - 1][state] = true;
                        return true;
                    }
                    break;
                case 3:
                    if (((y - 1) >= 0) && (board[y - 1][x] == 0) && (board[y - 1][x + 1] == 0) && !visited[y - 1][x][state]) {
                        visited[y - 1][x][state] = true;
                        return true;
                    }
                    break;
            }
            break;
        case 1:
            switch (move) {
                case 0:
                    if (((x + 1) < n) && (board[y][x + 1] == 0) && (board[y + 1][x + 1] == 0) && !visited[y][x + 1][state]) {
                        visited[y][x + 1][state] = true;
                        return true;
                    }
                    break;
                case 1:
                    if (((y + 2) < n) && (board[y + 2][x] == 0) && !visited[y + 1][x][state]) {
                        visited[y + 1][x][state] = true;
                        return true;
                    }
                    break;
                case 2:
                    if (((x - 1) >= 0) && (board[y][x - 1] == 0) && (board[y + 1][x - 1] == 0) && !visited[y][x - 1][state]) {
                        visited[y][x - 1][state] = true;
                        return true;
                    }
                    break;
                case 3:
                    if (((y - 1) >= 0) && (board[y - 1][x] == 0) && !visited[y - 1][x][state]) {
                        visited[y - 1][x][state] = true;
                        return true;
                    }
                    break;
            }
            break;
        case 2:
            switch (move) {
                case 0:
                    if (((x + 1) < n) && (board[y][x + 1] == 0) && !visited[y][x + 1][state]) {
                        visited[y][x + 1][state] = true;
                        return true;
                    }
                    break;
                case 1:
                    if (((y + 1) < n) && (board[y + 1][x] == 0) && (board[y + 1][x - 1] == 0) && !visited[y + 1][x][state]) {
                        visited[y + 1][x][state] = true;
                        return true;
                    }
                    break;
                case 2:
                    if (((x - 2) >= 0) && (board[y][x - 2] == 0) && !visited[y][x - 1][state]) {
                        visited[y][x - 1][state] = true;
                        return true;
                    }
                    break;
                case 3:
                    if (((y - 1) >= 0) && (board[y - 1][x] == 0) && (board[y - 1][x - 1] == 0) && !visited[y - 1][x][state]) {
                        visited[y - 1][x][state] = true;
                        return true;
                    }
                    break;
            }
            break;
        case 3:
            switch (move) {
                case 0:
                    if (((x + 1) < n) && (board[y][x + 1] == 0) && (board[y - 1][x + 1] == 0) && !visited[y][x + 1][state]) {
                        visited[y][x + 1][state] = true;
                        return true;
                    }
                    break;
                case 1:
                    if (((y + 1) < n) && (board[y + 1][x] == 0) && !visited[y + 1][x][state]) {
                        visited[y + 1][x][state] = true;
                        return true;
                    }
                    break;
                case 2:
                    if (((x - 1) >= 0) && (board[y][x - 1] == 0) && (board[y - 1][x - 1] == 0) && !visited[y][x - 1][state]) {
                        visited[y][x - 1][state] = true;
                        return true;
                    }
                    break;
                case 3:
                    if (((y - 2) >= 0) && (board[y - 2][x] == 0) && !visited[y - 1][x][state]) {
                        visited[y - 1][x][state] = true;
                        return true;
                    }
                    break;
            }
            break;
    }
    return false;
}

bool CheckRotate(vector<vector<int>>& board, int x, int y, int state, int move) {
    int n = board.size();

    switch (state) {
        case 0:
            switch (move) {
                case 0:
                    if (((y - 1) >= 0) && ((x + 1) < n) && (board[y - 1][x] == 0) && (board[y - 1][x + 1] == 0) && !visited[y - 1][x + 1][1]) {
                        visited[y - 1][x + 1][1] = true;
                        return true;
                    }
                    break;
                case 1:
                    if (((y + 1) < n) && ((x + 1) < n) && (board[y + 1][x] == 0) && (board[y + 1][x + 1] == 0) && !visited[y + 1][x + 1][3]) {
                        visited[y + 1][x + 1][3] = true;
                        return true;
                    }
                    break;
                case 2:
                    if (((y + 1) < n) && ((x + 1) < n) && (board[y + 1][x] == 0) && (board[y + 1][x + 1] == 0) && !visited[y][x][1]) {
                        visited[y][x][1] = true;
                        return true;
                    }
                    break;
                case 3:
                    if (((y - 1) >= 0) && ((x + 1) < n) && (board[y - 1][x] == 0) && (board[y - 1][x + 1] == 0) && !visited[y][x][3]) {
                        visited[y][x][3] = true;
                        return true;
                    }
                    break;
            }
            break;
        case 1:
            switch (move) {
                case 0:
                    if (((y + 1) < n) && ((x + 1) < n) && (board[y][x + 1] == 0) && (board[y + 1][x + 1] == 0) && !visited[y + 1][x + 1][2]) {
                        visited[y + 1][x + 1][2] = true;
                        return true;
                    }
                    break;
                case 1:
                    if (((y + 1) < n) && ((x - 1) >= 0) && (board[y][x - 1] == 0) && (board[y + 1][x - 1] == 0) && !visited[y + 1][x - 1][0]) {
                        visited[y + 1][x - 1][0] = true;
                        return true;
                    }
                    break;
                case 2:
                    if (((y + 1) < n) && ((x - 1) >= 0) && (board[y][x - 1] == 0) && (board[y + 1][x - 1] == 0) && !visited[y][x][2]) {
                        visited[y][x][2] = true;
                        return true;
                    }
                    break;
                case 3:
                    if (((y + 1) < n) && ((x + 1) < n) && (board[y][x + 1] == 0) && (board[y + 1][x + 1] == 0) && !visited[y][x][0]) {
                        visited[y][x][0] = true;
                        return true;
                    }
                    break;
            }
            break;
        case 2:
            switch (move) {
                case 0:
                    if (((y + 1) < n) && ((x - 1) >= 0) && (board[y + 1][x] == 0) && (board[y + 1][x - 1] == 0) && !visited[y + 1][x - 1][3]) {
                        visited[y + 1][x - 1][3] = true;
                        return true;
                    }
                    break;
                case 1:
                    if (((y - 1) >= 0) && ((x - 1) >= 0) && (board[y - 1][x] == 0) && (board[y - 1][x - 1] == 0) && !visited[y - 1][x - 1][1]) {
                        visited[y - 1][x - 1][1] = true;
                        return true;
                    }
                    break;
                case 2:
                    if (((y - 1) >= 0) && ((x - 1) >= 0) && (board[y - 1][x] == 0) && (board[y - 1][x - 1] == 0) && !visited[y][x][3]) {
                        visited[y][x][3] = true;
                        return true;
                    }
                    break;
                case 3:
                    if (((y + 1) < n) && ((x - 1) >= 0) && (board[y + 1][x] == 0) && (board[y + 1][x - 1] == 0) && !visited[y][x][1]) {
                        visited[y][x][1] = true;
                        return true;
                    }
                    break;
            }
            break;
        case 3:
            switch (move) {
                case 0:
                    if (((y - 1) >= 0) && ((x - 1) >= 0) && (board[y][x - 1] == 0) && (board[y - 1][x - 1] == 0) && !visited[y + 1][x - 1][0]) {
                        visited[y + 1][x - 1][0] = true;
                        return true;
                    }
                    break;
                case 1:
                    if (((y - 1) >= 0) && ((x + 1) < n) && (board[y][x + 1] == 0) && (board[y - 1][x + 1]) == 0 && !visited[y - 1][x + 1][2]) {
                        visited[y - 1][x + 1][2] = true;
                        return true;
                    }
                    break;
                case 2:
                    if (((y - 1) >= 0) && ((x + 1) < n) && (board[y][x + 1] == 0) && (board[y - 1][x + 1] == 0) && !visited[y][x][0]) {
                        visited[y][x][0] = true;
                        return true;
                    }
                    break;
                case 3:
                    if (((y - 1) >= 0) && ((x - 1) >= 0) && (board[y][x - 1] == 0) && (board[y - 1][x - 1] == 0) && !visited[y][x][2]) {
                        visited[y][x][2] = true;
                        return true;
                    }
                    break;
            }
            break;
    }
    return false;
}

// 노가다
// BFS
int solution(vector<vector<int>> board) {
    int answer = 987654321;
    queue<Robot> bfs_q;
    int n = board.size();
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    bfs_q.push({0, 0, 0, 0});
    while (!bfs_q.empty()) {
        Robot pos = bfs_q.front();
        bfs_q.pop();

        if (IsAnswer(pos, n - 1)) {
            answer = min(answer, pos.count);
        } else {
            for (int i = 0; i < 4; i++) {
                if (CheckMove(board, pos.x, pos.y, pos.state, i)) {
                    bfs_q.push({pos.x + dx[i], pos.y + dy[i], pos.state, pos.count + 1});
                }
            }
            switch (pos.state) {
                case 0:
                    if (CheckRotate(board, pos.x, pos.y, 0, 0)) bfs_q.push({pos.x + 1, pos.y - 1, 1, pos.count + 1});
                    if (CheckRotate(board, pos.x, pos.y, 0, 1)) bfs_q.push({pos.x + 1, pos.y + 1, 3, pos.count + 1});
                    if (CheckRotate(board, pos.x, pos.y, 0, 2)) bfs_q.push({pos.x, pos.y, 1, pos.count + 1});
                    if (CheckRotate(board, pos.x, pos.y, 0, 3)) bfs_q.push({pos.x, pos.y, 3, pos.count + 1});
                    break;
                case 1:
                    if (CheckRotate(board, pos.x, pos.y, 1, 0)) bfs_q.push({pos.x + 1, pos.y + 1, 2, pos.count + 1});
                    if (CheckRotate(board, pos.x, pos.y, 1, 1)) bfs_q.push({pos.x - 1, pos.y + 1, 0, pos.count + 1});
                    if (CheckRotate(board, pos.x, pos.y, 1, 2)) bfs_q.push({pos.x, pos.y, 2, pos.count + 1});
                    if (CheckRotate(board, pos.x, pos.y, 1, 3)) bfs_q.push({pos.x, pos.y, 0, pos.count + 1});
                    break;
                case 2:
                    if (CheckRotate(board, pos.x, pos.y, 2, 0)) bfs_q.push({pos.x - 1, pos.y + 1, 3, pos.count + 1});
                    if (CheckRotate(board, pos.x, pos.y, 2, 1)) bfs_q.push({pos.x - 1, pos.y - 1, 1, pos.count + 1});
                    if (CheckRotate(board, pos.x, pos.y, 2, 2)) bfs_q.push({pos.x, pos.y, 3, pos.count + 1});
                    if (CheckRotate(board, pos.x, pos.y, 2, 3)) bfs_q.push({pos.x, pos.y, 1, pos.count + 1});
                    break;
                case 3:
                    if (CheckRotate(board, pos.x, pos.y, 3, 0)) bfs_q.push({pos.x - 1, pos.y - 1, 0, pos.count + 1});
                    if (CheckRotate(board, pos.x, pos.y, 3, 1)) bfs_q.push({pos.x + 1, pos.y - 1, 2, pos.count + 1});
                    if (CheckRotate(board, pos.x, pos.y, 3, 2)) bfs_q.push({pos.x, pos.y, 0, pos.count + 1});
                    if (CheckRotate(board, pos.x, pos.y, 3, 3)) bfs_q.push({pos.x, pos.y, 2, pos.count + 1});
                    break;
            }
        }
    }
    
    return answer;
}