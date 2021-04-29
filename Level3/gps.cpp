// https://programmers.co.kr/learn/courses/30/lessons/1837?language=cpp

#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
// Dynamic Programming.
// i 시간에 j 노드에 위치할 경우 최소 변경횟수를 memoization해가며 해결
// dp[i][j] = min(dp[i][j], dp[i - 1][l]) 이 때, l은 j와 인접한(j포함) 노드들
// 계산 후 j가 log와 다르면 변경해야하므로 +1
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    vector<vector<int>> map(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> dp(k, vector<int>(n + 1, INF));

    // 경로 세팅
    for (int i = 0; i < edge_list.size(); i++) {
        int a = edge_list[i][0];
        int b = edge_list[i][1];
        map[a][b] = 1;
        map[b][a] = 1;
    }
    for (int i = 1; i <= n; i++) {
        map[i][i] = 1;
    }
    // Dynamic Programming
    dp[0][gps_log[0]] = 0;
    for (int i = 1; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int l = 1; l <= n; l++) {
                if (map[j][l] == 1 || map[l][j] == 1) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][l]);
                }
            }
            if (j != gps_log[i]) dp[i][j] += 1;
        }
    }
    answer = dp[k - 1][gps_log.back()] >= INF ? -1 : dp[k - 1][gps_log.back()];

    return answer;
}