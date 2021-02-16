#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[500][500] = {0, };

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int height = triangle.size();
    
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < height; i++) {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
    }
    for (int i = 2; i < height; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = max(triangle[i][j] + dp[i - 1][j - 1], triangle[i][j] + dp[i - 1][j]);
        }
    }
    answer = *max_element(dp[height - 1], dp[height - 1] + (height - 1));
    return answer;
}