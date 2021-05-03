// https://programmers.co.kr/learn/courses/30/lessons/12971?language=cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// DP
// 첫 스티커를 선택할 경우와 선택하지 않을 경우로 나누어서 2번 탐색
// 첫 스티커를 선택할 경우 탐색 범위는 [2, size - 1)
// 첫 스티커를 선택하지 않을 경우 탐색 범위는 [2, size)
// i번째 위치에서 최댓값은 i번째 위치를 선택할 경우와 선택하지 않을 경우로 나뉜다.
// i번째 위치를 선택할 경우, dp[i] = dp[i - 2] + sticker[i]
// i번째 위치를 선택하지 않을 경우, dp[i] = dp[i - 1]
// 위 두 값중 큰 값을 사용
int solution(vector<int> sticker)
{
    int answer = 0;
    vector<int> dp(100001, 0);

    if (sticker.size() == 1) return sticker[0];
    dp[0] = sticker[0];
    dp[1] = sticker[0];
    for (int i = 2; i < sticker.size() - 1; i++) {
        dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
    }
    answer = dp[sticker.size() - 2];
    dp[0] = 0;
    dp[1] = sticker[1];
    for (int i = 2; i < sticker.size(); i++) {
        dp[i] = max(dp[i - 2] + sticker[i], dp[i - 1]);
    }
    answer = max(answer, dp[sticker.size() - 1]);

    return answer;
}