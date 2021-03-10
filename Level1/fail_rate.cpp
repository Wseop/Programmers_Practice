// https://programmers.co.kr/learn/courses/30/lessons/42889?language=cpp

#include <string>
#include <vector>
#include <map>
#include <functional>

using namespace std;

// 실패율을 Key로 하는 multimap 활용
// Key는 오름차순으로 정렬
// 1번 스테이지부터 체크하므로 중복된 실패율이 있는 경우 작은 스테이지부터 삽입됨
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> try_count(N + 2, 0);
    vector<int> fail_count(N + 2, 0);
    multimap<double, int, greater<double>> failrate_stage;
    
    for (int i = 0; i < stages.size(); i++) {
        for (int j = 1; j <= stages[i]; j++) {
            try_count[j]++;
        }
        fail_count[stages[i]]++;
    }
    for (int i = 1; i <= N; i++) {
        if (try_count[i] == 0) failrate_stage.insert({0, i});
        else failrate_stage.insert({fail_count[i] / (double)try_count[i], i});
    }
    for (auto iter = failrate_stage.begin(); iter != failrate_stage.end(); iter++) {
        answer.push_back(iter->second);
    }
    return answer;
}