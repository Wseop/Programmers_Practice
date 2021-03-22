// https://programmers.co.kr/learn/courses/30/lessons/1844?language=cpp

#include <vector>
#include <queue>

using namespace std;

// BFS 활용 (Queue)
// 시작 위치부터의 최단 거리를 갖는 2차원 배열을 추가로 정의하여 최단거리 관리 (사이클 형성 방지)
// 이동가능한 위치이면서 최단거리일 경우 update
int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    queue<pair<int, int>> position;         // BFS
    vector<vector<int>> dist;               // 시작 위치부터의 최단거리
    int m = maps.size();
    int n = maps[0].size();
    
    // dist 초기화
    for (int i = 0; i < m; i++) {
        vector<int> tmp;
        for (int j = 0; j < n; j++) {
            tmp.push_back(987654321);
        }
        dist.push_back(tmp);
    }
    
    dist[0][0] = 1;
    position.push({0, 0});
    while (!position.empty()) {
        int cur_y = position.front().first;
        int cur_x = position.front().second;
        position.pop();
        
        for (int i = 0; i < 4; i++) {
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];
            
            if (next_y < 0 || next_x < 0 || next_y >= m || next_x >= n) continue;
            if (maps[next_y][next_x] == 0) continue;
            if (next_y == m-1 && next_x == n-1) {
                return dist[cur_y][cur_x] + 1;
            }
            if (dist[next_y][next_x] > (dist[cur_y][cur_x] + 1)) {
                position.push({next_y, next_x});
                dist[next_y][next_x] = dist[cur_y][cur_x] + 1;
            }
        }
    }
    
    return answer;
}