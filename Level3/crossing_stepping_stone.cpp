// https://programmers.co.kr/learn/courses/30/lessons/64062?language=cpp

#include <string>
#include <vector>

using namespace std;

// 이분 탐색
// 지나갈 수 있는 인원수를 정해진 범위내에서 조절해가며 탐색
// 지나갈 수 있는 인원수 (mid)가 돌에 적힌 숫자보다 큰 경우가 연속해서 k번 이상 나오면 너무 큰 case
// mid 인원 수 만큼 지나갈 수 있는 경우 중 가장 큰 경우를 반환
int solution(vector<int> stones, int k) {
    int answer = 0;
    int left = 1;
    int right = 200000000;

    while (left <= right) {
        int mid = (left + right) / 2;
        int count = 0;
        bool big = false;

        for (int value : stones) {
            if (value < mid) count++;
            else count = 0;
            if (count >= k) {
                big = true;
                break;
            }
        }
        if (big) {
            right = mid - 1;
        } else {
            answer = answer < mid ? mid : answer;
            left = mid + 1;
        }
    }

    return answer;
}