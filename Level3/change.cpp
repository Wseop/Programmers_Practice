#include <string>
#include <vector>

using namespace std;

int dp[100001];

// DP인데... 글로 설명하기가 어렵다...
int solution(int n, vector<int> money) {
    int answer = 0;

    dp[0] = 1;
    for (int i = 0; i < money.size(); i++) {
        for (int j = money[i]; j <= n; j++) {
            dp[j] += dp[j - money[i]];
        }
    }
    answer = dp[n];

    return answer;
}