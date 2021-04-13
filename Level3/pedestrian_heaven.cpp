// https://programmers.co.kr/learn/courses/30/lessons/1832?language=cpp

#include <vector>

using namespace std;

int MOD = 20170805;
int dp_l[501][501];
int dp_u[501][501];

// DP - 왼쪽, 위에서 오는 경우를 각각 구함
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp_l[i][j] = 0;
            dp_u[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        if (city_map[i][0] == 1) break;
        dp_u[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (city_map[0][i] == 1) break;
        dp_l[0][i] = 1;
    }
    for (int y = 1; y < m; y++) {
        for (int x = 1; x < n; x++) {
            if (city_map[y - 1][x] == 0) {
                dp_u[y][x] = (dp_u[y][x] + dp_u[y - 1][x] + dp_l[y - 1][x]) % MOD;
            }
            else if (city_map[y - 1][x] == 2) {
                dp_u[y][x] = (dp_u[y][x] + dp_u[y - 1][x]) % MOD;
            }
            if (city_map[y][x - 1] == 0) {
                dp_l[y][x] = (dp_l[y][x] + dp_u[y][x - 1] + dp_l[y][x - 1]) % MOD;
            }
            else if (city_map[y][x - 1] == 2) {
                dp_l[y][x] = (dp_l[y][x] + dp_l[y][x - 1]) % MOD;
            }
        }
    }
    answer = (dp_l[m - 1][n - 1] + dp_u[m - 1][n - 1]) % MOD;

    return answer;
}