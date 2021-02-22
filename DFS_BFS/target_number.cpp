#include <string>
#include <vector>

using namespace std;

int ans = 0;

void dfs(int sum, vector<int> &numbers, int depth, int target) {
	// 모든 숫자를 다 사용한 경우 계산한 값이 target인지 확인 후 재귀 탈출
    if (depth == numbers.size()) {
        if (sum == target) ans++;
        return;
    }
    dfs(sum + numbers[depth], numbers, depth + 1, target);
    dfs(sum - numbers[depth], numbers, depth + 1, target);
}

int solution(vector<int> numbers, int target) {
    
    dfs(0, numbers, 0, target);
    
    return ans;
}