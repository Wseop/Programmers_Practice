// https://programmers.co.kr/learn/courses/30/lessons/70130?language=cpp#

#include <string>
#include <vector>

// 교집합이 최소 1개 이상 -> 각 숫자가 나온 횟수가 2이상인 경우만 체크
// (나온 횟수 * 2)가 최대로 가능한 스타수열의 길이이므로 매 loop마다 체크하여 불필요한 case 건너뜀
// {index - 1, index} or {index , index + 1}의 형태로 수열을 생성가능하며 최대로 찾기 위해서는 앞쪽부터 검사를 진행
int solution(std::vector<int> a) {
    int answer = -1;
    std::vector<int> count(a.size() + 1, 0);
    int max = 0;

    for (int num : a) {
        count[num]++;
    }
    for (int num = 0; num < count.size(); num++) {
        int len = 0;
        std::vector<bool> visited(a.size() + 1, false);

        if (count[num] < 2) continue;
        if ((count[num] * 2) < max) continue;

        for (int index = 0; index < a.size(); index++) {
            if (a[index] == num) {
                if (((index - 1) >= 0) && (a[index - 1] != a[index]) && !visited[index] && !visited[index - 1]) {
                    len += 2;
                    visited[index] = true;
                    visited[index - 1] = true;
                }
                else if (((index + 1) < a.size()) && (a[index] != a[index + 1]) && !visited[index] && !visited[index + 1]) {
                    len += 2;
                    visited[index] = true;
                    visited[index + 1] = true;
                }
            }
        }
        max = max < len ? len : max;
    }
    answer = max;

    return answer;
}