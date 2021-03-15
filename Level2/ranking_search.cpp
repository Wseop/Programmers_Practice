// https://programmers.co.kr/learn/courses/30/lessons/72412?language=cpp

#include <string>
#include <vector>

using namespace std;

// 인자로 주어진 info를 parsing
// 문자를 만들어 나가다가 공백을 만나면 해당하는 정수로 변환하여 vector에 push
// for loop 종료 후 남아있는 문자열은 점수에 해당됨, 마찬가지로 vector에 push 후 return
vector<int> ParseInfo(string info) {
    string parsed_str = "";
    vector<int> parsed_info;
    
    for (int i = 0; i < info.size(); i++) {
        if (info[i] != ' ') {
            parsed_str += info[i];
        } else if (parsed_str == "cpp" || parsed_str == "backend" || 
                   parsed_str == "junior" || parsed_str == "chicken") {
            parsed_info.push_back(0);
            parsed_str = "";
        } else if (parsed_str == "java" || parsed_str == "frontend" || 
                   parsed_str == "senior" || parsed_str == "pizza") {
            parsed_info.push_back(1);
            parsed_str = "";
        } else if (parsed_str == "python") {
            parsed_info.push_back(2);
            parsed_str = "";
        }
    }
    parsed_info.push_back(stoi(parsed_str));
    return parsed_info;
}

// 인자로 주어진 query를 parsing
// ParseInfo와 동일하지만 '-'인 경우 -1을 push하고, and이면 무시
vector<int> ParseQuery(string query) {
    string parsed_str = "";
    vector<int> parsed_query;
    
    for (int i = 0; i < query.size(); i++) {
        if (query[i] == '-') {
            parsed_query.push_back(-1);
        }
        else if (query[i] != ' ') parsed_str += query[i];
        else if (parsed_str == "cpp" || parsed_str == "backend" || 
                   parsed_str == "junior" || parsed_str == "chicken") {
            parsed_query.push_back(0);
            parsed_str = "";
        } else if (parsed_str == "java" || parsed_str == "frontend" || 
                   parsed_str == "senior" || parsed_str == "pizza") {
            parsed_query.push_back(1);
            parsed_str = "";
        } else if (parsed_str == "python") {
            parsed_query.push_back(2);
            parsed_str = "";
        } else if (parsed_str == "and") {
            parsed_str = "";
        }
    }
    parsed_query.push_back(stoi(parsed_str));
    return parsed_query;
}

// 문제에서 주어진 language, part, career, food들을 순서대로 0, 1, 2(language만)로 할당
// 바로 접근할 수 있도록 위 조건들을 각각 index로 하는 4차원 배열을 사용
// 같은 조건이어도 점수가 다를 수 있으므로 vector를 사용
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int> applicant[3][2][2][2];      // language, part, career, food and value is scores
    
    // info를 parsing하여 applicant에 push
    for (int i = 0; i < info.size(); i++) {
        vector<int> ret = ParseInfo(info[i]);
        applicant[ret[0]][ret[1]][ret[2]][ret[3]].push_back(ret[4]);
    }
    // 각 query마다 parsing 진행
    // 특정 조건의 index값이 -1이면 모두 탐색
    // -1이 아니면 해당 index만 탐색하도록 범위를 지정
    for (int i = 0; i < query.size(); i++) {
        int count = 0;
        vector<int> ret = ParseQuery(query[i]);
        vector<pair<int, int>> indexs;
        
        // -1이면 0부터 1(language는 2)까지 모두 탐색하도록 pair생성
        // -1이 아니면 해당 index 한번만 탐색할 수 있도록 같은 값으로 pair생성
        if (ret[0] == -1) indexs.push_back({0, 2});
        else indexs.push_back({ret[0], ret[0]});
        if (ret[1] == -1) indexs.push_back({0, 1});
        else indexs.push_back({ret[1], ret[1]});
        if (ret[2] == -1) indexs.push_back({0, 1});
        else indexs.push_back({ret[2], ret[2]});
        if (ret[3] == -1) indexs.push_back({0, 1});
        else indexs.push_back({ret[3], ret[3]});
        
        // 위 조건대로 탐색 진행
        for (int j = indexs[0].first; j <= indexs[0].second; j++) {
            for (int k = indexs[1].first; k <= indexs[1].second; k++) {
                for (int l = indexs[2].first; l <= indexs[2].second; l++) {
                    for (int m = indexs[3].first; m <= indexs[3].second; m++) {
                        vector<int> scores = applicant[j][k][l][m];
                        for (int n = 0; n < scores.size(); n++) {
                            if (scores[n] >= ret[4]) count++;
                        }
                    }
                }
            }
        }
        answer.push_back(count);
    }
    return answer;
}