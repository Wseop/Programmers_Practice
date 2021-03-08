// https://programmers.co.kr/learn/courses/30/lessons/49191?language=cpp

#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int INF = 987654321;
int floyd[101][101];

// Floyd Warshall 알고리즘 활용
int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                floyd[i][j] = INF;
            }
        }
    }
    // 승자 -> 패자 경로로 연결
    for (int i = 0; i < results.size(); i++) {
        floyd[results[i][0]][results[i][1]] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= n; i++) {
                if (floyd[i][k] + floyd[k][j] < floyd[i][j]) {
                    floyd[i][j] = floyd[i][k] + floyd[k][j];
                }
            }
        }
    }
    // 승자 -> 패자 경로가 있는 경우 패자 -> 승자 경로 또한 존재하므로 이러한 case에 대해 연결
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (floyd[i][j] != INF) {
                floyd[j][i] = floyd[i][j];
            }
        }
    }
    // 순위를 알 수 있는 선수 check
    for (int i = 1; i <= n; i++) {
        bool valid = true;
        for (int j = 1; j <= n; j++) {
            if (floyd[i][j] == INF) {
                valid = false;
                break;
            }
        }
        if (valid) {
            answer++;
        }
    }
    return answer;
}