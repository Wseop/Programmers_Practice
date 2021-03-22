// https://programmers.co.kr/learn/courses/30/lessons/49994?language=cpp

#include <string>
#include <map>

using namespace std;

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

// 시작점, 도착점을 pair로 하는 multimap으로 방문 기록을 관리
// 지나온 길에 대한 counting이므로 역방향도 함께 관리
int solution(string dirs) {
    int answer = 0;
    multimap<pair<int, int>, pair<int, int>> visited;   // <start, end>
    pair<int, int> cursor = {0, 0};                     // <x, y>
    
    for (int i = 0; i < dirs.size(); i++) {
        char dir = dirs[i];
        int direction;
        bool visit = false;
        pair<int, int> next;
        
        switch (dir) {
            case 'U':
                direction = 0;
                break;
            case 'D':
                direction = 1;
                break;
            case 'R':
                direction = 2;
                break;
            case 'L':
                direction = 3;
                break;
        }
        next = {cursor.first + dx[direction], cursor.second + dy[direction]};
        if (next.first < -5 || next.first > 5 || next.second < -5 || next.second > 5) continue;
        // 현재 경로의 정방향에 대해 중복 검사
        auto range = visited.equal_range(cursor);
        for (auto iter = range.first; iter != range.second; iter++) {
            if (iter->first == cursor && iter->second == next) {
                visit = true;
                break;
            }
        }
        // 현재 경로의 역방향에 대해 중복 검사
        range = visited.equal_range(next);
        for (auto iter = range.first; iter != range.second; iter++) {
            if (iter->first == next && iter->second == cursor) {
                visit = true;
                break;
            }
        }
        if (!visit) {
            visited.insert({cursor, next});
            visited.insert({next, cursor});
            answer++;
        }
        cursor = next;
    }
    
    return answer;
}