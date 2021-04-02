// https://programmers.co.kr/learn/courses/30/lessons/43236?language=cpp

// 일반적으로, 이분 탐색 문제의 경우 범위가 매우 크게 주어짐!
// 답이 될 수 있는 구간을 범위로 잡을 것...

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Target이 될 수 있는 범위는 0 ~ 최대 거리 -> start = 0, end = distance로 설정 후 이분 탐색 진행
// 1-1. 바위 제거 : 바위 사이의 거리가 mid보다 작을 경우 바위를 제거하여 거리를 늘림
// 1-2. 위치 이동 : 1-1.이 아니면 한 블록 이동
// 2-1. 제거가능한 바위의 갯수를 초과하면 target이 너무 크기 때문에 최대값을 줄임
// 2-2. 2-1.이 아니면 target이 작은 경우이므로 최솟값을 늘림
int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    
    int start = 0;
    int end = distance;
    int mid = (start + end) / 2;    
    
    while (start <= end) {
        int prev = 0;
        int count_remove = 0;
        
        // If the distance between the currently searched rock and the previous rock is less than mid, 
        // remove it so that mid can be satisfied.
        // Else, do not erase, so prev value becomes the current rock position.
        for (int i = 0; i < rocks.size(); i++) {
            if (rocks[i] - prev < mid) {
                count_remove++;
            } else {
                prev = rocks[i];
            }
        }
        // If erase more than the target, the mid is too large,
        // thus reducing end value.
        if (count_remove > n) {
            end = mid - 1;
            mid = (start + end) / 2;
        } else {
            answer = max(answer, mid);
            start = mid + 1;
            mid = (start + end) / 2;
        }
    }
    
    return answer;
}