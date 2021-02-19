#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000000][3];
int num_house;
vector<int> g_money;

int pick(int index, int first_picked) {
    // Exit conditions
    // 1. Out of index
    if (index >= num_house) return 0;
    // 2. If first house is picked, then last house cannot pick
    if (index == (num_house-1) && (first_picked == 1)) return 0;
    // 3. memoization
    if (dp[index][first_picked] != 0) return dp[index][first_picked];
    
    dp[index][first_picked] = max(dp[index][first_picked], g_money[index] + pick(index + 3, first_picked));
    dp[index][first_picked] = max(dp[index][first_picked], g_money[index] + pick(index + 2, first_picked));
    return dp[index][first_picked];
}

int solution(vector<int> money) {
    int answer = 0;
    g_money = money;
    num_house = money.size();
    
    // exception case
    if (num_house == 3) 
        answer = *max_element(money.begin(), money.end());
    else  
        answer = max(pick(0, 1), pick(1, 0));
    answer = max(answer, pick(2, 2));
    
    return answer;
}