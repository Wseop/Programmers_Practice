// https://programmers.co.kr/learn/courses/30/lessons/12979?language=cpp

#include <iostream>
#include <vector>

using namespace std;

// Greedy? 미수신지역의 범위에 따라 설치해야 할 갯수가 정해져 있음 (설치 위치는 여러경우가 있을 수 있지만 가장 많이 cover하는 순으로 설치하면 됨)
// 미수신지역의 범위는 아래와 같은 규칙을 가짐
// [1 ~ 1번째 시작점)
// (1번째 종료점 ~ 2번째 시작점)
// (2번째 종료점 ~ n]
// 계산식을 간단히 하기 위해 범위를 모두 미포함으로 변경
// (0 ~ 1번째 시작점)
// (1번째 종료점 ~ 2번째 시작점)
// (2번째 종료점 ~ n + 1)
// 간단히 (i-1번째 종료점 ~ i번째 시작점)로 표현가능
// 설치해야 할 기지국 수는 ((i번째 시작점 - i-1번째 종료점 -1) / coverage) + 1, 여기서 coverage는 2w + 1
int solution(int n, vector<int> stations, int w) {
    int answer = 0;
    int coverage = (2 * w) + 1;
    int start = 0;
    int end = 0;
    int need = 0;

    for (int i = 0; i < stations.size(); i++) {
        end = stations[i] - w;
        need = end - start - 1;

        if (need > 0) {
            answer += (((need - 1) / coverage) + 1);
        }
        start = stations[i] + w;
    }
    end = n + 1;
    need = end - start - 1;
    if (need > 0) {
        answer += (((need - 1) / coverage) + 1);
    }

    return answer;
}