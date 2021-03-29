// https://programmers.co.kr/learn/courses/30/lessons/42890?language=cpp

#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// next_permutation으로 가능한 모든 attributes의 조합을 확인
// set을 사용하여 순서만 다른 조합을 방지
int solution(vector<vector<string>> relation) {
    int answer = 0;
    set<set<int>> candidates;
    int max_attr = relation[0].size();
    vector<int> attrs;
    
    // attribute의 이름은 해당 열의 번호로 함
    for (int i = 0; i < max_attr; i++) attrs.push_back(i);
    for (int i = 0; i < max_attr; i++) {
        do {
            set<int> key;
            bool is_min = true;
            
            // attibute 조합으로 candidate_key 생성
            for (int j = 0; j <= i; j++) {
                key.insert(attrs[j]);
            }
            // 생성된 candidate_key가 minimality를 만족하는지 확인
            for (auto iter_a = candidates.begin(); iter_a != candidates.end(); iter_a++) {
                int count = 0;
                for (auto iter_b = iter_a->begin(); iter_b != iter_a->end(); iter_b++) {
                    if (key.count(*iter_b)) count++;
                }
                if (count == iter_a->size()) {
                    is_min = false;
                    break;
                }
            }
            // minimality를 만족한다면 candidate_key가 될 수 있는지 확인
            if (is_min) {
                set<string> tuples;
                
                for (int j = 0; j < relation.size(); j++) {
                    string tuple = "";
                    
                    // j행의 attribute에 해당하는 값들을 이어 붙인 뒤 set에 삽입
                    for (auto iter = key.begin(); iter != key.end(); iter++) {
                        tuple += relation[j][*iter];
                    }
                    tuples.insert(tuple);
                }
                // 삽입된 값들의 갯수가 전체 행의 크기와 같다면 uniqueness를 만족하므로 candidate_key가 될 수 있음
                if (tuples.size() == relation.size()) {
                    candidates.insert(key);
                }
            }
        } while (next_permutation(attrs.begin(), attrs.end()));
    }
    answer = candidates.size();
    return answer;
}