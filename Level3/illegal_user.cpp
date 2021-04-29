// https://programmers.co.kr/learn/courses/30/lessons/64064?language=cpp

#include <string>
#include <vector>
#include <set>

using namespace std;

bool visited[8];

// set 중첩하여 제재 아이디 목록이 중복되는 경우를 제거
// DFS (Recursive)
// banned_id[depth]와 매칭되는 user_id를 찾은 경우 visited에 마킹
// 모두 찾은 경우 visited에서 마킹되어 있는 index만 set에 넣고 재귀 탈출
void recur_match(set<set<int>>& banned_lists, vector<string>& user_id, vector<string>& banned_id, int depth) {
    if (depth == banned_id.size()) {
        set<int> banned;

        for (int i = 0; i < user_id.size(); i++) {
            if (visited[i]) banned.insert(i);
        }
        banned_lists.insert(banned);
        return;
    }
    for (int i = 0; i < user_id.size(); i++) {
        if ((user_id[i].size() != banned_id[depth].size()) || visited[i]) continue;
        bool matched = true;

        for (int index = 0; index < user_id[i].size(); index++) {
            char bann = banned_id[depth][index];
            char user = user_id[i][index];

            if ((bann != '*') && (bann != user)) {
                matched = false;
                break;
            }
        }
        if (matched) {
            visited[i] = true;
            recur_match(banned_lists, user_id, banned_id, depth + 1);
            visited[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    set<set<int>> banned_lists;
    
    for (int i = 0; i < user_id.size(); i++) {
        visited[i] = false;
    }

    recur_match(banned_lists, user_id, banned_id, 0);
    answer = banned_lists.size();

    return answer;
}