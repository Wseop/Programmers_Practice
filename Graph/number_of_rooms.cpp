// https://programmers.co.kr/learn/courses/30/lessons/49190?language=cpp

#include <string>
#include <vector>
#include <map>

using namespace std;

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

// 방 형성 조건 : 이미 방문했던 정점 && 새로운 간선인 경우
// 대각선 이동인 경우 2개의 방이 형성되는 Case가 존재, 모든 이동을 2칸으로 할 경우 해결 가능 (line 24.)
int solution(vector<int> arrows) {
    int answer = 0;
    map<pair<int, int>, bool> visited;      // 정점 방문 여부 [y, x]
    map<pair<pair<int, int>, pair<int, int>>, bool> edges;      // [y1, x1]와 [y2, x2] 간 간선의 존재 여부
    pair<int, int> current_pos = {0, 0};    // 정점은 pair로 관리, 시작은 [0, 0]
    
    visited[current_pos] = true;
    for (int i = 0; i < arrows.size(); i++) {
        // 대각선인 case를 고려하여 모든 이동은 2회씩 진행
        for (int j = 0; j < 2; j++) {
            pair<int, int> next_pos = { current_pos.first + dy[arrows[i]], current_pos.second + dx[arrows[i]] };

            if (visited[next_pos] == true) {
                if (edges[{ current_pos, next_pos }] == false) {
                    answer++;
                    edges[{ current_pos, next_pos }] = true;
                    edges[{ next_pos, current_pos }] = true;
                }
            } else {
                visited[next_pos] = true;
                edges[{ current_pos, next_pos }] = true;
                edges[{ next_pos, current_pos }] = true;
            }
            current_pos = next_pos;
        }
    }
    
    return answer;
}