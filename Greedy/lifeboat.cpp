#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int idx_front = 0;
    int idx_back = people.size() - 1;
    
    // 몸무게 내림차순 정렬
    sort(people.begin(), people.end(), greater<int>());
    // 무거운 사람부터 선택 (idx_front)
    // 가벼운 사람을 추가할 수 있으면 추가 (idx_back)
    while (idx_front <= idx_back && idx_front < people.size()) {
        if (people[idx_front] + people[idx_back] <= limit) {
            idx_back--;
        }
        idx_front++;
        answer++;
    }
    
    return answer;
}