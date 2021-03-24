// https://programmers.co.kr/learn/courses/30/lessons/12978?language=cpp

#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;

// Floyd Warshall 알고리즘 활용
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int floyd[51][51];
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {
                floyd[i][j] = 0;
            }
            else {
                floyd[i][j] = INF;
            }
        }
    }
    // 양방향 이동이 가능, 여러 경로가 가능함에 유의하여 경로 초기화
    for (int i = 0; i < road.size(); i++) {
        int a = road[i][0];
        int b = road[i][1];
        int dist = road[i][2];
        
        if (floyd[a][b] > dist) floyd[a][b] = dist;
        if (floyd[b][a] > dist) floyd[b][a] = dist;
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (floyd[i][k] + floyd[k][j] < floyd[i][j]) {
                    floyd[i][j] = floyd[i][k] + floyd[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        if (floyd[1][i] <= K) answer++;
    }

    return answer;
}