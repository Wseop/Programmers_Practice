#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int idx_front = 0;
    int idx_back = people.size() - 1;
    
    //descending order
    sort(people.begin(), people.end(), greater<int>());
    while (idx_front <= idx_back && idx_front < people.size()) {
        if (people[idx_front] + people[idx_back] <= limit) {
            idx_back--;
        }
        idx_front++;
        answer++;
    }
    
    return answer;
}