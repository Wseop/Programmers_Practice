// https://programmers.co.kr/learn/courses/30/lessons/68644?language=cpp

#include <string>
#include <vector>
#include <set>

using namespace std;

// 완전 탐색으로 해결
// 중복 제거 및 오름차순 정렬을 위해 결과를 set에 넣었다가 answer로 이동
vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    set<int> results_set;
    
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < numbers.size(); j++) {
            if (i != j) {
                results_set.insert(numbers[i] + numbers[j]);
            }
        }
    }
    // answer.assign(results_set.begin(), results_set.end());
    for (auto iter = results_set.begin(); iter != results_set.end(); iter++) {  
        answer.push_back(*iter);
    }
    return answer;
}