// https://programmers.co.kr/learn/courses/30/lessons/17686

#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

void ToLower(string& str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += ('a' - 'A');
        }
    }
}

bool IsDigit(char c) {
    if (c >= '0' && c <= '9') return true;
    return false;
}

// multimap을 사용하여 key값에 따라 정렬
// 1. HEAD를 key로 하는 multimap(head_map)에 넣어서 HEAD로 우선 정렬 수행
// 2. head_map에서 동일한 HEAD를 가지는 element들에 대해 
//    NUMBER를 key로 하는 multimap(number_map)에 넣어서 NUMBER로 재 정렬 수행
// 3. number_map에서 순서대로 꺼내서 answer에 추가 -> 2~3 반복
vector<string> solution(vector<string> files) {
    vector<string> answer;
    multimap<string, pair<int, string>> head_map;   // key : HEAD, value : <NUMBER, 파일명>
    set<string> heads;                              // head_map 탐색에 사용될 HEAD의 집합
    
    for (int i = 0; i < files.size(); i++) {
        string file = files[i];
        string head = "";
        string number = "";
        int j = 0;
        
        // HEAD parsing
        while (!IsDigit(file[j])) {
            head += file[j++];
        }
        // NUMBER parsing
        while (j < file.size() && IsDigit(file[j])) {
            number += file[j++];
        }
        ToLower(head);
        head_map.insert({head, {stoi(number), file}});
        heads.insert(head);
    }
    for (auto iter_h = heads.begin(); iter_h != heads.end(); iter_h++) {
        multimap<int, string> number_map;               // key : NUMBER, value : 파일명
        auto range = head_map.equal_range(*iter_h);
        
        for (auto iter_r = range.first; iter_r != range.second; iter_r++) {
            number_map.insert({iter_r->second.first, iter_r->second.second});
        }
        for (auto iter_n = number_map.begin(); iter_n != number_map.end(); iter_n++) {
            answer.push_back(iter_n->second);
        }
    }
    
    return answer;
}