// https://programmers.co.kr/learn/courses/30/lessons/43162?language=cpp

// 기본적인 BFS, DFS 문제

#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[200];

// BFS로 방문 가능한 모든 정점에 대해 기록 -> visited
// 위 과정을 모든 노드에 대해 수행
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    queue<int> q;
	// BFS, 0번부터 시작
    for (int i = 0; i < n; i++) {
		// 최초 방문일 경우 새로운 네트워크 형성
        if (!visited[i]) {
            visited[i] = true;
            q.push(i);
            answer++;
        }
        while (!q.empty()) {
            int computer = q.front();
            q.pop();
            for (int j = 0; j < n; j++) {
                if (computer != j && computers[computer][j] == 1 && !visited[j]) { 
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
    }
    
    return answer;
}