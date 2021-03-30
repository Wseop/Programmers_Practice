// https://programmers.co.kr/learn/courses/30/lessons/17684?language=cpp

#include <string>
#include <vector>
#include <map>

using namespace std;

// 사전은 map으로 관리 <문자열, 색인>
vector<int> solution(string msg) {
    vector<int> answer;
    map<string, int> dict;
    int index = 1;
    
    // 길이가 1인 단어로 사전 초기화
    for (int i = 0; i < 26; i++) {
        char c = 'A' + i;
        dict[string(1, c)] = index++;
    }
    
    string current = msg.substr(0, 1);
    int pos = 0;
    // 1. 현재 입력(current)이 사전에 있는 경우
    //      1-1. pos가 마지막 index이면 현재 입력에 대한 색인을 결과에 추가 후 종료
    //      1-2. 현재 입력에 다음 문자를 붙인 후 재시도
    // 2. 현재 입력이 사전에 없는 경우 
    //      이전 loop에서의 입력에 대한 색인을 결과에 추가
    //      현재 입력은 사전에 추가
    //      현재 입력을 새로 추가된 문자로 update 후 재시도
    while (pos < msg.size()) {
        if (dict.count(current) != 0) {
            if (pos + 1 == msg.size()) {
                answer.push_back(dict[current]);
                break;
            } else {
                current += msg[++pos];
            }
        } else {
            answer.push_back(dict[current.substr(0, current.size() - 1)]);
            dict[current] = index++;
            current = msg[pos];
        }
    }
    
    return answer;
}