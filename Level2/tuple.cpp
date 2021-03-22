// https://programmers.co.kr/learn/courses/30/lessons/64065?language=cpp

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

// 집합의 크기가 작은 순으로 나열한 뒤 새로 등장하는 숫자들을 순서대로 나열해주면 해결
// 집합의 크기를 key로 하는 multimap에 넣은 뒤, 중복체크를 하면서 multimap을 순회하도록 구현
vector<int> solution(string s) {
    vector<int> answer;
    vector<int> temp;
    multimap<int, int> elements_map;
    string str_num = "";
    int count = 0;                      // 집합의 크기
    
    // 문자열 parsing
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            str_num += s[i];
        }
        else if (s[i] == '}' && (str_num.size() != 0)) {
            count++;
            temp.push_back(stoi(str_num));
            str_num = "";
            for (int j = 0; j < count; j++) {
                elements_map.insert({count, temp.back()});
                temp.pop_back();
            }
            count = 0;
        }
        else if (s[i] == ',' && (str_num.size() != 0)) {
            count++;
            temp.push_back(stoi(str_num));
            str_num = "";
        }
    }
    
    vector<int> dup_check(100001, 0);
    for (auto iter = elements_map.begin(); iter != elements_map.end(); iter++) {
        if (dup_check[iter->second] == 0) {
            dup_check[iter->second] = 1;
            answer.push_back(iter->second);
        }
    }
    
    return answer;
}