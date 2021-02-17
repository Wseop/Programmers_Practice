#include <string>
#include <vector>

using namespace std;

long long dp[101][101] = {0, };

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for (int i = 0; i < puddles.size(); i++) {
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }
    for (int x = 1; x <= m; x++) {
        if (dp[1][x] == -1) break;
        dp[1][x] = 1;
    }
    for (int y = 1; y <= n; y++) {
        if (dp[y][1] == -1) break;
        dp[y][1] = 1;
    }
    for (int y = 2; y <= n; y++) {
        for (int x = 2; x <= m; x++) {
            if (dp[y][x] == -1) continue;
            if (dp[y-1][x] != -1) dp[y][x] += dp[y-1][x];
            if (dp[y][x-1] != -1) dp[y][x] += dp[y][x-1];
            // if didn't operate % here, overflow can be occurred.
            dp[y][x] %= 1000000007;
        }
    }
    return dp[n][m];
}