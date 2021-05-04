// https://programmers.co.kr/learn/courses/30/lessons/67258?language=cpp

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 단순한 2중 for loop으로 구현 시 시간 초과,,
// left, right 2개의 index를 사용하여 탐색 시간을 줄이는 것이 포인트
// 우선 left = 0에서 시작하여 조건을 만족하는 right를 구함
// 이후 left를 늘리면서 선택된 보석을 제외, 조건을 만족하지 않으면 조건을 만족할 때 까지 다시 right를 늘리면서 탐색
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    map<string, int> visit_count;
    int kinds;
    int l = 0, r = 0;
    int collect = 0;
    int min_range;

    for (string gem : gems) {
        visit_count[gem] = 0;
    }
    kinds = visit_count.size();

    for (r = 0; r < gems.size(); r++) {
        string gem = gems[r];

        if (visit_count[gem] == 0) collect++;
        visit_count[gem]++;
        if (collect == kinds) break;
    }    
    min_range = r - l + 1;
    answer = {l + 1, r + 1};

    while (r < gems.size()) {
        string gem = gems[l];
        int range;

        l++;
        visit_count[gem]--;
        if (visit_count[gem] == 0) collect--;
        if (collect < kinds) {
            r++;
            while (r < gems.size()) {
                gem = gems[r];
                visit_count[gem]++;
                if (visit_count[gem] == 1) collect++;
                if (collect == kinds) break;
                else r++;
            }
        }
        range = r - l + 1;
        if (range < min_range) {
            min_range = range;
            answer = {l + 1, r + 1};
        }
    }

    return answer;
}