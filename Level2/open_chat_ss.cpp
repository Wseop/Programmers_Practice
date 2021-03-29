// https://programmers.co.kr/learn/courses/30/lessons/42888?language=cpp

#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> map_id_nick;
    vector<pair<string, string>> result;
    
    for (int i = 0; i < record.size(); i++) {
        stringstream ss;
        string command = "";
        string id = "";
        string nick = "";

        ss.str(record[i]);
        ss >> command;
        ss >> id;
        
        if (command == "Leave") {
            result.push_back({command, id});
        } else {
            ss >> nick;
            map_id_nick[id] = nick;
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