// https://programmers.co.kr/learn/courses/30/lessons/49189?language=cpp#

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> adjacency(n + 1);   // 인접리스트
    vector<bool> visited(n + 1, false);
    vector<int> distances(n + 1, 0);
    queue<int> bfs;
    
    for (int i = 0; i < edge.size(); i++) {
        int start = edge[i][0];
        int end = edge[i][1];
        
        adjacency[start].push_back(end);
        adjacency[end].push_back(start);
    }
    visited[1] = true;
    bfs.push(1);
    
    while (!bfs.empty()) {
        int start = bfs.front();
        bfs.pop();
        
        for (int i = 0; i < adjacency[start].size(); i++) {
            int end = adjacency[start][i];
            // 목적지가 방문한 적이 없는 노드이면 거리 계산 후 Queue에 추가
            if (!visited[end]) {
                visited[end] = true;
                distances[end] = distances[start] + 1;
                bfs.push(end);
            }
        }
    }
    // 오름차순으로 정렬 후 가장 큰 값을 가지는 노드의 갯수를 구함
    sort(distances.begin(), distances.end());
    for (int i = distances.size() - 1; i >= 0; i--) {
        if (distances[i] == distances[distances.size() - 1]) {
            answer++;
        } else {
            break;
        }
    }
    return answer;
}