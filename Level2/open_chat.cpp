// https://programmers.co.kr/learn/courses/30/lessons/42888?language=cpp

// map에 추가 시
// 1. insert를 사용하면 중복일 경우 새로운 값으로 update하지 않음
// 2. map[key] = value 로 추가 가능하며, 중복일 경우 새로운 값으로 update 함

// stringstream을 사용하면 문자열 parsing에 용이
// open_chat_ss.cpp -> stringstream을 사용한 버전

#include <string>
#include <vector>
#include <map>

using namespace std;

// 주어진 record parsing
// return : command, id, [nickname]
vector<string> ParseRecord(string record) {
    vector<string> ret;
    string parsed_str = "";
    
    for (int i = 0; i < record.size(); i++) {
        if (record[i] == ' ') {
            ret.push_back(parsed_str);
            parsed_str = "";
        } else {
            parsed_str += record[i];
        }
    }
    ret.push_back(parsed_str);
    return ret;
}

// 1. map을 활용하여 id와 nickname을 매칭
// 2. Enter or Leave일 경우 vector에 추가 {command, id}
// 3. vector를 돌면서 결과 출력
vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> map_id_nick;
    vector<pair<string, string>> result;
    
    for (int i = 0; i < record.size(); i++) {
        vector<string> parsed_record = ParseRecord(record[i]);
        string command = parsed_record[0];
        string id = parsed_record[1];
        
        if (command == "Leave") {
            result.push_back({command, id});
        } else {
            map_id_nick[id] = parsed_record[2];
            if (command == "Enter") {
                result.push_back({command, id});
            }
        }
    }
    for (int i = 0; i < result.size(); i++) {
        if (result[i].first == "Enter") {
            answer.push_back(map_id_nick[result[i].second] + "님이 들어왔습니다.");
        } else {
            answer.push_back(map_id_nick[result[i].second] + "님이 나갔습니다.");
        }
    }
    return answer;
}