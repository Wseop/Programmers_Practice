// https://programmers.co.kr/learn/courses/30/lessons/72413?language=cpp

#include <string>
#include <vector>

using namespace std;

const int INF = 987654321;

// Floyd Warshall 알고리즘 적용
// 합승을 해서 가는 경우와 각자 가는 경우에 대해 모두 계산 후 최솟값을 반환
// 합승을 해서 가는 경우, 합승 구간에 도착점이 걸리는 지 구분하여 작성
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    int min_fare = INF;
    int fare_a = 0, fare_b = 0, fare_shared = 0;
    int total = 0;
    vector<vector<int>> routes;
    
    // routes 배열 초기화
    for (int i = 0; i <= n; i++) {
        vector<int> tmp(n + 1, INF);
        routes.push_back(tmp);
    }
    // 입력값으로 routes 배열 초기화
    for (int i = 0; i < fares.size(); i++) {
        int node1 = fares[i][0];
        int node2 = fares[i][1];
        int fare = fares[i][2];

        routes[node1][node2] = fare;
        routes[node2][node1] = fare;
    }
    // Floyd Warshall 알고리즘 적용
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (routes[i][k] + routes[k][j] < routes[i][j])
                    routes[i][j] = routes[i][k] + routes[k][j];
            }
        }
    }
    // 1. 합승을 하지 않는 경우 (각각 이동하는 경우 운임)
    fare_a = routes[s][a];
    fare_b = routes[s][b];
    total = fare_a + fare_b;
    min_fare = min_fare > total ? total : min_fare;
    
    // 2. 합승하는 경우
    for (int i = 1; i <= n; i++) {
        // 예외처리. 도착점이 시작점과 같거나 경로가 없으면 pass
        if ((i == s) || (routes[s][i] == INF)) continue;
        fare_shared = routes[s][i];
        // 합승 구간이 A의 목적지인 경우 B만 추가 이동
        if (i == a) total = fare_shared + routes[i][b];
        // 합승 구간이 B의 목적지인 경우 A만 추가 이동
        else if (i == b) total = fare_shared + routes[i][a];
        // 둘다 아닌 경우 둘다 추가 이동
        else total = fare_shared + routes[i][a] + routes[i][b];
        min_fare = min_fare > total ? total : min_fare;
    }
    answer = min_fare;
    
    return answer;
}