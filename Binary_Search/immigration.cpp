// https://programmers.co.kr/learn/courses/30/lessons/43238?language=cpp

// 이분 탐색 문제 -> 시작과 끝 값을 어떻게 지정?
// line 33 ~ 35. - 풀이의 핵심이 되는 point, 임의의 시간에 대해 심사 가능한 인원 수를 계산

#include <string>
#include <vector>

using namespace std;

// start : n = 1 일 때, 심사속도가 가장 빠른 심사관에게 심사받는 시간
// end : 심사속도가 가장 빠른 심사관만 심사를 하는 시간
long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long fastest_checker = 1000000000;
    
    // 가장 빠른 심사관을 찾는 단계
    for (int i = 0; i < times.size(); i++) {
        if (fastest_checker > times[i]) {
            fastest_checker = times[i];
        }
    }
    
    // 범위 설정
    long long start = fastest_checker;      // at least one checker should work.
    long long end = fastest_checker * n;    // worst case is work only one person who is the fastest
    long long mid = (start + end) / 2;

    while (start <= end) {
        long long checked_person = 0;

        // 각 심사관이 주어진 시간동안 심사할 수 있는 인원 수
        for (int i = 0; i < times.size(); i++) {
            checked_person += (mid / times[i]);
        }
        // 심사할 수 있는 인원수가 n이지만 더 짧은 시간에 심사할 수 있는 경우가 가능하므로 범위 재지정하여 재탐색
        if (checked_person >= n) {  
            answer = mid;
            end = mid - 1;
        } else {    
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    
    return answer;
}