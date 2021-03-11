// https://programmers.co.kr/learn/courses/30/lessons/49993?language=cpp

#include <string>
#include <vector>

using namespace std;

// 문자열 skill에서 c가 위치한 index를 반환
// 없다면 -1을 반환
int GetIndex(string skill, char c) {
    for (int i = 0; i < skill.size(); i++) {
        if (skill[i] == c) return i;
    }
    return -1;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for (int i = 0; i < skill_trees.size(); i++) {
        string tree = skill_trees[i];
        int skill_index;                // 현재 배우려는 스킬이 선행스킬 중 몇 번째인지에 대한 정보
        int learned = -1;               // 선행스킬 중 어느 스킬까지 배웠는지에 대한 정보
        bool able = true;
        
        for (int j = 0; j < tree.size(); j++) {
            skill_index = GetIndex(skill, tree[j]);
            // 선행스킬이 아니면 무시해도 됨
            if (skill_index == -1) continue;
            // 앞의 선행스킬을 배운 상태여야 해당 스킬을 배울 수 있음
            else if ((skill_index - 1) != learned) {
                able = false;
                break;
            }
            learned++;
        }
        if (able) answer++;
    }
    
    return answer;
}