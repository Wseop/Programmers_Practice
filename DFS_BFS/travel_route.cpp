// https://programmers.co.kr/learn/courses/30/lessons/43164?language=cpp

#include <string>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>

using namespace std;

bool cmp(vector<string> a, vector<string> b) {
    return a[1] < b[1];
}

int dfs(multimap<string, string>& map_tickets, string current, vector<string>& answer) {
	// 모든 ticket을 사용했으면 정상 종료
    if (map_tickets.empty()) return 1;
    
    int ret;
    int elements = map_tickets.count(current);
    
	// ticket이 남아있지만, 현재 위치(current)에서 출발하는 ticket이 없을 경우 재탐색
    if (elements == 0) return -1;
    
	// 다음 목적지를 answer에 삽입 및 사용한 ticket 제거
	// 재탐색이 필요한 경우 answer에 삽입했던 목적지 정보 제거 및 ticket 정보 복구
    for (int i = 0; i < elements; i++) {
        auto iter_tickets = map_tickets.find(current);
        // <current, dst>
        pair<string, string> ticket = make_pair(iter_tickets->first, iter_tickets->second);
        answer.push_back(ticket.second);
        map_tickets.erase(iter_tickets);
        ret = dfs(map_tickets, ticket.second, answer);
        if (ret == 1) break;
        answer.pop_back();
        map_tickets.insert(ticket);
    }
    
    return ret;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    multimap<string, string> map_tickets;
    string current = "ICN";
    
    // 경로가 여러개일 경우 알파벳순으로 방문하므로 도착점을 기준으로 오름차순 정렬
    sort(tickets.begin(), tickets.end(), cmp);
    for (auto iter = tickets.begin(); iter != tickets.end(); iter++) {
        map_tickets.insert(make_pair((*iter)[0], (*iter)[1]));
    }
    answer.push_back(current);
    dfs(map_tickets, current, answer);
    
    return answer;
}