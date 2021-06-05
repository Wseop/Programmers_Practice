// https://programmers.co.kr/learn/courses/30/lessons/60062?language=cpp#

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 완전 탐색
// 한 바퀴 돈 이후 상황을 처리하는게 좀 헷갈렸음...
// 모든 경우의 수를 탐색하기 위해 next_permutation을 사용
// 현재 위치를 취약 지점으로 update 후 이동 거리만큼 추가로 이동
// 취약 지점 index는 자연스럽게 start 이후부터 탐색하므로 다시 start가 되면 탐색 종료
// 한 바퀴 돌았을 경우(cycle)에 대해 추가로 if문을 추가하여 해결
int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 987654321;
    bool update = false;

    do {
        for (int start = 0; start < weak.size(); start++) {
            int count = 0;
            int weak_i = start;
            int cur = 0;
            bool cycle = false;
            
            for (int dist_i = 0; dist_i < dist.size(); dist_i++) {
                bool find = false;

                cur = weak[weak_i];
                cur += dist[dist_i];
                count++;
                while (cur >= weak[weak_i]) {
                    weak_i++;
                    if (weak_i == weak.size()) {
                        cycle = true;
                        weak_i = 0;
                    }
                    if (weak_i == start) {
                        find = true;
                        break;
                    }
                    if (cycle && cur < (weak[weak_i] + n)) {
                        break;
                    }
                }
                if (find) {
                    update = true;
                    answer = min(answer, count);
                    break;
                }
            }
        }
    } while (next_permutation(dist.begin(), dist.end()));
    if (!update) answer = -1;

    return answer;
}