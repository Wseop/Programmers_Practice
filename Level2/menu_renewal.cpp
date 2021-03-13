// https://programmers.co.kr/learn/courses/30/lessons/72411?language=cpp

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

// includes와 next_permutation을 활용
// 코스의 길이가 2인 경우부터 가능한 모든 조합에 대해 체크
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    unordered_map<string, int> course_menus;    // map 사용시 시간초과 발생
    vector<int> max_count(10, 0);               // course 길이 별 최대 주문 횟수
    
    // includes에서 사용 및 순서만 다른 조합을 비교하지 않도록 하기 위해 정렬
    for (int i = 0; i < orders.size(); i++) {
        sort(orders[i].begin(), orders[i].end());
    }
    for (int i = 0; i < course.size(); i++) {
        int len = course[i];
        string order = "";
        
        for (int j = 0; j < orders.size(); j++) {
            order = orders[j];
            if (order.size() < len) continue;
            do {
                int count = 0;
                string new_course = order.substr(0, len);       // 새로운 조합을 get
                // 순서만 다른 조합을 제거하여 key값을 최소화하기 위해 정렬 (정렬하지 않을 경우 key가 많아져서 시간초과 발생)
                sort(new_course.begin(), new_course.end());     
                // 이전에 나왔던 조합인 경우 pass
                if (course_menus.count(new_course) != 0) continue;
                // order마다 해당 조합이 있는지 확인
                for (int l = 0; l < orders.size(); l++) {
                    if (includes(orders[l].begin(), orders[l].end(), new_course.begin(), new_course.end())) {
                        count++;
                    }
                }
                course_menus.insert({new_course, count});
                if (max_count[len - 1] < count) {
                    max_count[len - 1] = count;
                }
            } while (next_permutation(order.begin(), order.end()));
        }
    }
    for (auto iter = course_menus.begin(); iter != course_menus.end(); iter++) {
        if (max_count[iter->first.size() - 1] >= 2 && max_count[iter->first.size() - 1] == iter->second) {
            answer.push_back(iter->first);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}