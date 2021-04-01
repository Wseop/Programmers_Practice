// https://programmers.co.kr/learn/courses/30/lessons/68646?language=cpp

#include <string>
#include <vector>

using namespace std;

// 특정 풍선을 기준으로 왼쪽, 오른쪽에 위치한 풍선들은 번호가 큰 풍선만 제거하면서 하나씩만 남길 수 있음
// 최종적으로 남기고자 하는 풍선의 번호가 왼쪽, 오른쪽 풍선보다 하나라도 작은 경우가 있으면 남길 수 있게 됨
// but, 단순 반복문으로 구현 시 중복된 영역을 반복적으로 탐색하므로 dynamic programming으로 구현
int solution(vector<int> a) {
    int answer = 0;
    int dp_min_left[1000000];
    int dp_min_right[1000000];
    
    dp_min_left[0] = a[0];
    for (int i = 1; i < a.size(); i++) {
        dp_min_left[i] = dp_min_left[i - 1] < a[i] ? dp_min_left[i - 1] : a[i];
    }
    dp_min_right[a.size() - 1] = a[a.size() - 1];
    for (int i = a.size() - 2; i >= 0; i--) {
        dp_min_right[i] = dp_min_right[i + 1] < a[i] ? dp_min_right[i + 1] : a[i];
    }
    for (int i = 0; i < a.size(); i++) {
        if (dp_min_left[i] >= a[i] || dp_min_right[i] >= a[i]) answer++;
    }
    
    return answer;
}