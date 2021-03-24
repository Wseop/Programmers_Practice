// https://programmers.co.kr/learn/courses/30/lessons/12981?language=cpp

// set의 insert() : <iterator, true/false>를 반환
// iterator : 해당 element의 위치
// true/false : 중복된 값이면 false
// 
// string의 front(), back()으로 맨 앞과 뒤 접근 가능

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

// set - insert함수의 반환 값을 활용하여 단어 중복 검사
vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<int> say_count(n, 0);    // 각 사람이 말한 횟수
    int index = 0;                  // 사람 번호
    set<string> words_set;

    answer.push_back(0);
    answer.push_back(0);
    for (int i = 0; i < words.size(); i++) {
        auto ret = words_set.insert(words[i]);
        say_count[index]++;
        if (i > 0 && words[i-1].back() != words[i].front()) {
            answer.clear();
            answer.push_back(index + 1);
            answer.push_back(say_count[index]);
            break;
        }
        if (!ret.second) {
            answer.clear();
            answer.push_back(index + 1);
            answer.push_back(say_count[index]);
            break;
        }
        index = (index + 1) % n;
    }

    return answer;
}